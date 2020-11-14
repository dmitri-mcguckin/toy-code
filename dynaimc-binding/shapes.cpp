#include "shapes.h"

//
// Shape implementation
//
Shape::Shape(): sides(0) {}

Shape::Shape(const int sides): sides(sides) {}

void Shape::display() {
	std::cout << "Shape<sides: " << sides << ">";
}

//
// Square implementation
//
Square::Square(): Shape(4), length(0) {}

Square::Square(const int length): Shape(4), length(length) {}

const int Square::area() {
	return length * length;
}

void Square::display() {
	std::cout << "Square<length: " << length << ">\t";
  Shape::display();
}

//
// Circle implementation
//
Circle::Circle(): Shape(-1), radius(0) {}

Circle::Circle(const int radius): Shape(-1), radius(radius) {}

const int Circle::area() {
	return 3.14 * (radius * radius);
}

const float Circle::circumference() {
	return 3.14 * 2 * radius;
}

void Circle::display() {
	std::cout << "Circle<radius: " << radius << ", circumference: " << circumference() << ">\t";
  Shape::display();
}
