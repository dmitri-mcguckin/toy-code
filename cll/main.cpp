#include <iostream>

using namespace std;

// A generic data class that could be anything
class Data {
	private:
		int data;
	public:
		Data();
		Data(const int);
		const int get();
};

// Data implementation
Data::Data() : data(-1) {}
Data::Data(const int data): data(data) {}
const int Data::get() { return this->data; }

// A node class part of a CLL
class Node {
	private:
		Data * data;
		Node * next;
	public:
		Node();
		Node(Data&);
		~Node();

		Data* get();
		void set_next(Node*);
		Node* get_next();

		friend ostream& operator<< (ostream&, const Node&);
};

// Node implementation
Node::Node() : data(NULL), next(NULL) {}
Node::Node(Data& data): data(&data), next(NULL) {}
Node::~Node() { if(data) delete data; }

Data* Node::get() { return data; }
void Node::set_next(Node* next) { this->next = next; }
Node* Node::get_next() { return next; }

ostream& operator<< (ostream& buffer, const Node& src) {
	buffer << src.data->get();
	return buffer;
}

// A toy circularly linked list... but something's off...
class CLL {
	private:
		Node* rear;

		Node* dequeue(Node*);
	public:
		CLL();
		~CLL();

		void enqueue(Data&);
		Data dequeue();

		void remove_all();

		friend ostream& operator<< (ostream&, const CLL&);
};

CLL::CLL() : rear(NULL) {}
CLL::~CLL() { remove_all(); }

void CLL::enqueue(Data& src) {
	if(!rear) {
		rear = new Node(src);
		rear->set_next(rear);
		return;
	}
	Node* temp = new Node(src);
	temp->set_next(rear->get_next());
	rear->set_next(temp);
}

// This function crashes, what's fundamentally wrong with it?
Data CLL::dequeue() {
	if(!rear) return Data(-1);

	Node* removed_node = dequeue(rear);
	Data data = *removed_node->get();
	delete removed_node;
	return data;
}

Node* CLL::dequeue(Node* curr) {
	if(curr == rear){
		rear = NULL;
		return curr;
	}
	else if(curr->get_next() == rear) {
		Node* temp = rear;
		curr->set_next(rear->get_next());
		rear = curr;
		return temp;
	}
	return dequeue(curr->get_next());
}

// An iterative solution, but what would the recursive version look like?
void CLL::remove_all() { while(rear) dequeue(); }

ostream& operator<< (ostream& buffer, const CLL& src) {
	if(!src.rear) return buffer;

	Node* curr = src.rear->get_next();
	while(curr != src.rear) {
		buffer << *curr;
		if(curr->get_next()) buffer << " -> ";
		curr = curr->get_next();
	}
	buffer << *src.rear;
	return buffer;
}

int main(int argc, char** argv) {
	CLL list;

	Data d1(3);
	Data d2(2);
	Data d3(1);

	list.enqueue(d1);
	list.enqueue(d2);
	list.enqueue(d3);

	cout << "List: " << list << endl;

	Data item = list.dequeue();

	cout << "Removed: " << item << endl;
	cout << "List: " << list << endl;
}
