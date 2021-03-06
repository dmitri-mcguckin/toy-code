#include <iostream>
#include "data.h"
#include "list.h"

using namespace std;

void print_menu() {
	cout << "1.) Add a number" << endl
			 << "2.) Remove a number" << endl
			 << "3.) Display all" << endl
			 << "q.) Quit" << endl;
}

int main(int argc, char** argv) {
	bool running = true;
	CLL list;

	while(running) {
		char option;
		print_menu();
		cout << "?: ";
		cin >> option;

		switch(option) {
			case '1':
				int number;
				cout << "Enter a number: ";
				cin >> number;
				list.enqueue(Data(number));
				break;

			case '2':
				{
					Data item = list.dequeue();
					cout << "Removed " << item << " from the list!" << endl;
				}
				break;

			case '3':
				cout << "Here's the full CLL of numbers:"
						 << endl << list << endl;
				break;

			case 'q':
				running = false;
				cout << "Goodbye!" << endl;
				break;
			default:
				cout << "Unrecognized option: " << option << endl;
		}
	}
}
