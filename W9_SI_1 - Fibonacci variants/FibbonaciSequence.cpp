#include "FibbonaciSequence.h"
#include <iostream>
#include <ctime>

int fib[50], arr[50];

void FibbonaciSequence::numOfAddition()
{
	addition++;
}

int FibbonaciSequence::iterative(int num){
	long n = num;

	arr[0] = 0;
	arr[1] = 1;

	for (int i{ 2 }; i <= n; i++) {
		numOfAddition();
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[n];
}

int FibbonaciSequence::naiveRecursive(int num){
	if (num <= 1)
		return num;
	else {
		numOfAddition();
		return naiveRecursive(num - 1) + naiveRecursive(num - 2);
	}
}

int FibbonaciSequence::recursiveMemo(int num){
	if (num <= 1)
		return num;
	if (fib[num] != 0)
		return fib[num];
	else {
		fib[num] = recursiveMemo(num - 1) + recursiveMemo(num - 2);
		numOfAddition();
		return fib[num];
	}	
}

int FibbonaciSequence::tailRecursive(int n, int a, int b){
	if (n == 0)
		return a;
	if (n == 1)
		return b;
	numOfAddition();
	return tailRecursive(n - 1, b, a + b);
}

void FibbonaciSequence::allLevels(int n)
{
	// LVL 0
	std::cout << "\nITERATIVE: \n";
	std::cout << n << ". " << iterative(n) << std::endl;
	std::cout << "Number of addition: " << addition << std::endl << std::endl;
	addition = 0;

	// LVL 1
	std::cout << "NAIVE RECURSIVE: \n";
	std::cout << n << ". " << naiveRecursive(n) << std::endl;
	std::cout << "Number of addition: " << addition << std::endl << std::endl;
	addition = 0;

	// LVL 2
	std::cout << "RECURSIVE MEMOZATION: \n";
	std::cout << n << ". " << recursiveMemo(n) << std::endl;
	std::cout << "Number of addition: " << addition << std::endl << std::endl;
	addition = 0;

	// LVL 3
	std::cout << "TAIL RECURSIVE: \n";
	std::cout << n << ". " << tailRecursive(n) << std::endl;
	std::cout << "Number of addition: " << addition << std::endl << std::endl;
}

