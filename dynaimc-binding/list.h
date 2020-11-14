#pragma once
#include <iostream>
#include "shapes.h"

struct Node {
	Shape* data;
	Node* next;
};

class List {
	private:
		Node* head;

		void add(Shape* data, Node*& head);
		void display(Node*& head);
	public:
		List();

		void add(Shape* data);
		void display();
};
