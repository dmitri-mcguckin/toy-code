#include "list.h"

List::List(): head(NULL) {}

void List::add(Shape* data) {
	add(data, head);
}

void List::add(Shape* data, Node*& head) {
	if(!head) {
		head = new Node;
		head->data = data;
		head->next = NULL;
		return;
	}
	add(data, head->next);
}

void List::display() {
	display(head);
}

void List::display(Node*& head) {
	if(!head)
		return;
	head->data->display();
	std::cout << std::endl;
	display(head->next);
}
