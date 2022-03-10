#pragma once
class ArrayGenerator
{
	
public:
	static int* generateInt(int arraySize, int from, int until, double sortRatio, int sortedPosition);
	static double* generateDouble(int arraySize, double from, double until, double sortRatio, int sortedPosition);

private:
	static double checkSortRatio(double sortRatio);
	static int checkSortedPosition(int sortedPosition, int arraySize, int sortedSize);
};
