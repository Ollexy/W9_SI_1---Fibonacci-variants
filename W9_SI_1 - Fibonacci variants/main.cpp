#include <iostream>
#include "fibbonaciSequence.h"

int main() {
	int n;

	std::cout << "Enter number: ";
	std::cin >> n;

	FibbonaciSequence fib;
	fib.allLevels(n);

	return 0;
}