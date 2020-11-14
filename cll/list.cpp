#include "list.h"

//
// Node implementation
//
Node::Node(): next(NULL) {}

Node::Node(const Data& data): Data(data), next(NULL) {}

void Node::set_next(Node* next) {
	this->next = next;
}

Node* Node::get_next() const {
	return next;
}

CLL::CLL() : rear(NULL) {}

CLL::~CLL() { remove_all(); }

void CLL::enqueue(const Data& src) {
	if(!rear) {
		rear = new Node(src);
		rear->set_next(rear);
		return;
	}

	Node* temp = new Node(src);
	temp->set_next(rear->get_next());
	rear->set_next(temp);
	rear = temp;
}

Data CLL::dequeue() {
	if(!rear)
		return Data();

	Node* temp = rear->get_next();
	rear->set_next(temp->get_next());
	Data src(*temp);
	delete temp;
	return src;
}

int CLL::remove_all() {
	if(!rear)
		return 0;
	return remove_all(rear->get_next());
}

int CLL::remove_all(const Node* rear) {
	if(rear == this->rear) {
		delete rear;
		return 1;
	}

	const Node* next = rear->get_next();
	delete rear;
	return remove_all(next) + 1;
}

std::ostream& operator<< (std::ostream& buffer, const CLL& src) {
	if(!src.rear)
		return buffer;

	Node* curr = src.rear->get_next();

	while(curr != src.rear) {
		buffer << *curr;
		if(curr->get_next()) buffer << " -> ";
		curr = curr->get_next();
	}

	buffer << *src.rear;
	return buffer;
}
