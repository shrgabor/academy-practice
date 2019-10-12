#include <iostream>

int main() {
	int integer = 8;
	char a = 65;
	std::cout << "Hello Academy!" << std::endl;
	std::cout << "value is > " << integer << " size is > " << sizeof(integer) << std::endl;

	// POINTERS
	std::cout << &integer << std::endl;
	int* pointer = &integer;
}
