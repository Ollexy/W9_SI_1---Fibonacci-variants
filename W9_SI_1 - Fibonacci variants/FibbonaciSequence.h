#pragma once
class FibbonaciSequence
{
	
public:
	int addition = 0;
	void numOfAddition();
	int iterative(int num);
	int naiveRecursive(int num);
	int recursiveMemo(int num);
	int tailRecursive(int n, int a = 0, int b = 1);
	void allLevels(int n);
};

