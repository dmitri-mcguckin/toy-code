#include "shapes.h"

//
// Shape implementation
//
Shape::Shape(): sides(0) {}

Shape::Shape(const int sides): sides(sides) {}

std::ostream& operator<<(std::ostream& buffer, const Shape& src) {
	buffer << ", Shape<sides: " << src.sides << ">";
	return buffer;
}

//
// Square implementation
//
Square::Square(): Shape(4), length(0) {}

Square::Square(const int length): Shape(4), length(length) {}

const int Square::area() {
	return length * length;
}

std::ostream& operator<<(std::ostream& buffer, const Square& src) {
	buffer << "Square<length: " << src.length << ">";
	buffer << (Shape&) src;
	return buffer;
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

std::ostream& operator<<(std::ostream& buffer, const Circle& src) {
	buffer << "Circle<radius: " << src.radius << ">";
	buffer << (Shape&) src;
	return buffer;
}
