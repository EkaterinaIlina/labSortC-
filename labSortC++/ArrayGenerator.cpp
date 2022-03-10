#include "ArrayGenerator.h"
#include <stdlib.h>
#include <time.h>
#include <stdexcept>
#include "Quicksort.h"

//
// Summary:
//     Returns a randomly generated int array from the specified range of values, with the specified array size, sort ratio and sorted block position.
//
// Parameters:
//   arraySize:
//     The size of generated array.
//   from:
//     The least value that can be returned.
//   until:
//     The upper bound (exclusive) for the returned value.
//   sortRatio:
//     The sort ratio (1 and greater than 1 - fully sorted array, 0.5 - half sorted array, 0 and less than 0 - fully not sorted array).
//   sortedPosition:
//     The position of the sorted block in the generated array (1 - the beginning of the array, 2 - the middle of the array, other number - end of array).
//
// Returns:
//     A randomly generated {@code int} array from the specified range of values, with the specified array size, sort ratio and sorted block position.
//
// Exceptions:
//   invalid_argument:
//     If from is greater than or equal to until.
int* ArrayGenerator::generateInt(
	int arraySize, 
	int from, 
	int until, 
	double sortRatio, 
	int sortedPosition
)
{
	if (from >= until)
	{
		throw std::invalid_argument("The argument from is greater than or equal to until");
	}

	srand(time(0));

	int* array = new int[arraySize];

	sortRatio = checkSortRatio(sortRatio);
	int sortedSize = (int)(arraySize * sortRatio);

	sortedPosition = checkSortedPosition(sortedPosition, arraySize, sortedSize);

	int* sortedArray = new int[sortedSize];
	for (int i = 0; i < sortedSize; i++) {
		sortedArray[i] = from + rand() % (until - from);
	}
	Quicksort::sort(sortedArray, 0, sortedSize - 1);

	int j = 0;
	for (int i = 0; i < arraySize; i++) {
		if (sortedPosition <= i && j < sortedSize) {
			array[i] = sortedArray[j];
			j++;
		}
		else {
			array[i] = from + rand() % (until - from);
		}
	}

	return array;
}

//
// Summary:
//     Returns a randomly generated int array from the specified range of values, with the specified array size, sort ratio and sorted block position.
//
// Parameters:
//   arraySize:
//     The size of generated array.
//   from:
//     The least value that can be returned.
//   until:
//     The upper bound (exclusive) for the returned value.
//   sortRatio:
//     The sort ratio (1 and greater than 1 - fully sorted array, 0.5 - half sorted array, 0 and less than 0 - fully not sorted array).
//   sortedPosition:
//     The position of the sorted block in the generated array (1 - the beginning of the array, 2 - the middle of the array, other number - end of array).
//
// Returns:
//     A randomly generated {@code int} array from the specified range of values, with the specified array size, sort ratio and sorted block position.
//
// Exceptions:
//   invalid_argument:
//     If from is greater than or equal to until.
double* ArrayGenerator::generateDouble(
	int arraySize, 
	double from, 
	double until, 
	double sortRatio, 
	int sortedPosition
)
{
	if (from >= until)
	{
		throw std::invalid_argument("The argument from is greater than or equal to until");
	}

	srand(time(0));

	double* array = new double[arraySize];

	sortRatio = checkSortRatio(sortRatio);
	int sortedSize = (int)(arraySize * sortRatio);

	sortedPosition = checkSortedPosition(sortedPosition, arraySize, sortedSize);

	double* sortedArray = new double[sortedSize];
	for (int i = 0; i < sortedSize; i++) {
		sortedArray[i] = (double)(rand()) / RAND_MAX * (until - from) + from;
	}
	Quicksort::sort(sortedArray, 0, sortedSize - 1);

	int j = 0;
	for (int i = 0; i < arraySize; i++) {
		if (sortedPosition <= i && j < sortedSize) {
			array[i] = sortedArray[j];
			j++;
		}
		else {
			array[i] = (double) (rand()) / RAND_MAX * (until - from) + from;
		}
	}

	return array;
}

double ArrayGenerator::checkSortRatio(double sortRatio)
{
	if (sortRatio > 1.0) {
		sortRatio = 1.0;
	}
	else if (sortRatio < 0.0) {
		sortRatio = 0.0;
	}

	return sortRatio;
}

int ArrayGenerator::checkSortedPosition(int sortedPosition, int arraySize, int sortedSize)
{
	switch (sortedPosition)
	{
	case 1:
		sortedPosition = 0;
		break;
	case 2:
		sortedPosition = (arraySize / 2) - (sortedSize / 2);
		break;
	default:
		sortedPosition = arraySize - sortedSize;
		break;
	}

	return sortedPosition;
}
