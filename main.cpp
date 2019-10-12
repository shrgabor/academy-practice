#include <iostream>

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
}
