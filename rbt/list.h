#pragma once
#include <iostream>
#include "data.h"

class Node: public Data {
	private:
		bool is_red;
		Node* left;
		Node* right;

	public:
		Node();
		Node(const Node&);
		Node(const Data&);

		void set_color(const bool);
		bool get_color() const;
		void set_left(Node*);
		void set_right(Node*);
		Node* get_left() const;
		Node* get_right() const;

		friend std::ostream& operator<<(std::ostream&, const Node&);
};

class RedBlackTree {
	private:
		Node* root;

		void copy_tree(Node*, const Node*);
		int add(Data&, Node*, Node*);
		void fix_violations(Node*, Node*, Node*, Node*);
		void recolor(Node*, bool);

		void display(std::ostream&, const int, const Node*) const;
	public:
		RedBlackTree();
		RedBlackTree(const RedBlackTree&);

		int add(Data&);
		void remove(const int);
		friend std::ostream& operator<<(std::ostream&, const RedBlackTree&);
};
