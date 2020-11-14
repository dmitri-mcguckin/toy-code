#include "list.h"

//
// Node implementation
//
Node::Node(): is_red(true), left(NULL), right(NULL) {}

Node::Node(const Node& src): Data(src), is_red(true), left(NULL), right(NULL) {}

Node::Node(const Data& data): Data(data), is_red(true), left(NULL), right(NULL) {}

void Node::set_color(const bool is_red) {
	this-> is_red = is_red;
}

bool Node::get_color() const {
	return is_red;
}

void Node::set_left(Node* left) {
	this->left = left;
}

void Node::set_right(Node* right) {
	this->right = right;
}

Node* Node::get_left() const {
	return left;
}

Node* Node::get_right() const {
	return right;
}

std::ostream& operator<< (std::ostream& buffer, const Node& src) {
	buffer << (Data) src << " | " << (src.is_red ? "red" : "black");
	return buffer;
}

//
// Red Black Tree implementation
//
RedBlackTree::RedBlackTree(): root(NULL) {}

RedBlackTree::RedBlackTree(const RedBlackTree& src) {
	if(src.root){
		root = new Node(*src.root);

		if(src.root->get_left()){
			Node* left = new Node(*src.root->get_left());
			root->set_left(left);
			copy_tree(root->get_left(), src.root->get_left());
		}

		if(src.root->get_right()){
			Node* right = new Node(*src.root->get_right());
			root->set_right(right);
			copy_tree(root->get_right(), src.root->get_right());
		}
	}
}

void RedBlackTree::copy_tree(Node* dest, const Node* src) {
	if(src->get_left()){
		Node* left = new Node(*src->get_left());
		dest->set_left(left);
		copy_tree(dest->get_left(), src->get_left());
	}

	if(src->get_right()){
		Node* right = new Node(*src->get_right());
		dest->set_right(right);
		copy_tree(dest->get_right(), src->get_right());
	}
}

int RedBlackTree::add(Data& src) {
		return add(src, root, NULL);
}

//
// Return Codes:
//	1: Do an insertion
//
int RedBlackTree::add(Data& src, Node* root, Node* parent) {
	// One way or another, we fell off the end of the tree
	if(!root) {
		// If no parent, then we are at the top of the tree and there is no root,
		//	ergo create the root of the tree now
		if(!parent) {
			this->root = new Node(src);
			fix_violations(root, NULL, NULL, NULL);
			return 0;
		}
		// There is a parent so we are not at the top of the tree,
		//	return a 1 to indicate that the parent-calling-recursion needs to do
		//	an insertion
		else
			return 1;
	}

	// Travel left or right depending on arbitrary data value ordering/comparison
	if(src < *root){
		// Go left
		int res = add(src, root->get_left(), root);

		// Come back from recursion a bit and check if we need to do anything

		// Do an insertion
		if(res == 1)
			root->set_left(new Node(src));

		// Who's yo daddy? (Also who's your uncle?)
		Node* uncle;
		if(parent->get_right() == root)
			uncle = parent->get_left();
		else
			uncle = parent->get_right();

		// Fix any RB-tree-rule violations
		fix_violations(root->get_left(), root, uncle, parent);
	}
	else {
		// TODO: Mirror left-traversal
	}

	return -1;
}

//
// Cases:
//	0.) child is root (of the tree)
//	1.) child.uncle is red
//	2.) child.uncle is black triangle
//	3.) child.uncle is black line
//
void RedBlackTree::fix_violations(Node* child, Node* parent, Node* uncle, Node* grandparent) {
	if(!parent) { // Case 0
		root->set_color(false);
		return;
	}
	else { // Not Case 0
		if(uncle && uncle->get_color()) { // Case 1: Uncle exists and is is red
			// Recolor the subtree starting with a black grandparent
			recolor(grandparent, false);
		}
		else { // Not Case 1: Uncle is black, may or may not exist
			bool is_linec
		}
	}
}

void RedBlackTree::recolor(Node* root, bool is_red) {
	// If We're trying to recolor a non-existant relative, don't.
	if(!root)
		return;

	// If the current node's color is not the expected color, then repaint it
	//	and keep traversing
	if(root->get_color() != is_red)
	{
		root->set_color(is_red);
		recolor(root->get_left(), !is_red);
		recolor(root->get_right(), !is_red);
	}
	// If logic falls through to this line, then the current node's color is
	//	already the expected color, we can assume that its subtree is also
	//	colored correctly.
}

std::ostream& operator<<(std::ostream& buffer, const RedBlackTree& src) {
	src.display(buffer, 0, src.root);
	return buffer;
}

void RedBlackTree::display(std::ostream& buffer, const int depth, const Node* root) const {
	if(!root)
		return;
	buffer << "(lvl " << depth << " | " << *root << ")" << std::endl;
	display(buffer, depth + 1, root->get_left());
	display(buffer, depth + 1, root->get_right());
}
