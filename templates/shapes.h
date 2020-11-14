#pragma once
#include <iostream>
#include <ostream>

class Shape {
	private:
		int sides;

	public:
		Shape();
		Shape(const int);

		virtual const int area() = 0;
		friend std::ostream& operator<<(std::ostream&, const Shape&);
};

class Square: public Shape {
	private:
		int length;

	public:
		Square();
		Square(const int length);

		const int area();
		friend std::ostream& operator<<(std::ostream&, const Square&);
};

class Circle: public Shape {
	private:
		int radius;

	public:
		Circle();
		Circle(const int radius);

		const int area();
		const float circumference();
		friend std::ostream& operator<<(std::ostream&, const Circle&);
};
