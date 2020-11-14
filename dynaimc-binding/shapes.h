#pragma once
#include <iostream>

class Shape {
	private:
		int sides;

	public:
		Shape();
		Shape(const int);

		virtual const int area() = 0;
		virtual void display();
};

class Square: public Shape {
	private:
		int length;

	public:
		Square();
		Square(const int length);

		const int area();
		void display();
};

class Circle: public Shape {
	private:
		int radius;

	public:
		Circle();
		Circle(const int radius);

		const int area();
		const float circumference();
		void display();
};
