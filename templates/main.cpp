#include <iostream>
#include <vector>
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
	std::vector<Shape*> shapes;

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

				shapes.push_back(new Square(length));
				break;

				case '2':
					cout << "Radius of the circle: ";
					int radius;
					cin >> radius;

					shapes.push_back(new Circle(radius));
					break;

				case '3':
					for(Shape* s: shapes){
						Square* sp = dynamic_cast<Square*>(s);
						Circle* cp = dynamic_cast<Circle*>(s);
						if(sp) cout << *sp;
						else if(cp) cout << *cp;
						cout << endl;
					}
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
