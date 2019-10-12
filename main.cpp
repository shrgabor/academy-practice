#include <iostream>

void enumExample() {
	enum Color {
		red, green = 5, blue
	};
	Color c = green;
	switch (c) {
		case green: std::cout << c; break;
		case red  : std::cout << "red"; break;
		case blue : std::cout << "blue"; break;
	}

	if (c < blue) {
		std::cout << std::endl << "c is less than " << blue << std::endl;
	}
//	int value = green;  // implicit conversion
}

void increment(int var) {
	var++; // fixme
}

int main() {
	int integer = 8;
	char a = 65;
	std::cout << "Hello Academy!" << std::endl;
	std::cout << "value is > " << integer << " size is > " << sizeof(integer) << std::endl;

	// POINTERS
	std::cout << &integer << std::endl;
	int* pointer = &integer;

	// REFERENCES
	int var = 5;
	int& ref = var;
	ref = 2;
	increment(var);
	std::cout << "value is > " << var << " size is > " << sizeof(var) << std::endl;
	std::cout << "value is > " << ref << " size is > " << sizeof(ref) << std::endl;

	// ENUMS
	enumExample();
}
