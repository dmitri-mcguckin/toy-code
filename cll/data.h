#pragma once
#include <iostream>

class Data {
	private:
		int data;
	public:
		Data();
		Data(const int);
		const int get();
		friend std::ostream& operator <<(std::ostream&, const Data&);
};
