#pragma once
class Quicksort
{

public:
	static void sort(int* array, int left, int right);
	static void sort(double* array, int left, int right);

private:
	static int partition(int* array, int left, int right);
	static int partition(double* array, int left, int right);
	static void swap(int* array, int indexLeft, int indexRight);
	static void swap(double* array, int indexLeft, int indexRight);
};
