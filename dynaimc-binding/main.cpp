#include <iostream>
#include "list.h"
#include "shapes.h"

using namespace std;

void print_menu() {
	cout << "1.) Add Square" << endl
			 << "2.) Add Circle" << endl
			 << "3.) Display All" << endl
			 << "q.) Quit" << endl;
}

int main() {
	bool running = true;
	List shapes;

	while(running){
		print_menu();

		cout << "?: ";
		char option;
		std::cin >> option;

		switch(option) {
			case '1':
				cout << "Length of the square: ";
				int length;
				cin >> length;

				shapes.add(new Square(length));
				break;

				case '2':
					cout << "Radius of the circle: ";
					int radius;
					cin >> radius;

					shapes.add(new Circle(radius));
					break;

				case '3':
					shapes.display();
					break;

			case 'q':
				running = false;
				break;
			default:
				cout << "Unknown option: " << option << endl;
		}
	}

	return 0;
}
