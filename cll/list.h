#pragma once
#include <iostream>
#include "data.h"

class Node: public Data {
	private:
		Node * next;
	public:
		Node();
		Node(const Data&);

		void set_next(Node*);
		Node* get_next() const;
};

class CLL {
	private:
		Node* rear;

		int remove_all(const Node*);
	public:
		CLL();
		~CLL();

		void enqueue(const Data&);
		Data dequeue();
		int remove_all();

		friend std::ostream& operator<< (std::ostream&, const CLL&);
};
