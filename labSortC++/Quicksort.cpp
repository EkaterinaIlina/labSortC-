#include "Quicksort.h"

void Quicksort::sort(int* array, int left, int right)
{
    if (left < right)
    {
        int p = partition(array, left, right);

        sort(array, left, p);
        sort(array, p + 1, right);
    }
}

void Quicksort::sort(double* array, int left, int right)
{
    if (left < right)
    {
        int p = partition(array, left, right);

        sort(array, left, p);
        sort(array, p + 1, right);
    }
}

int Quicksort::partition(int* array, int left, int right)
{
    int pivot = array[(left + right) / 2];
    int i = left;
    int j = right;

    while (true)
    {
        while (array[i] < pivot)
        {
            i++;
        }
        while (array[j] > pivot)
        {
            j--;
        }
        if (i >= j)
        {
            return j;
        }
        swap(array, i++, j--);
    }
}

int Quicksort::partition(double* array, int left, int right)
{
    double pivot = array[(left + right) / 2];
    int i = left;
    int j = right;

    while (true)
    {
        while (array[i] < pivot)
        {
            i++;
        }
        while (array[j] > pivot)
        {
            j--;
        }
        if (i >= j)
        {
            return j;
        }
        swap(array, i++, j--);
    }
}

void Quicksort::swap(int* array, int indexLeft, int indexRight)
{
    int tmp = array[indexLeft];
    array[indexLeft] = array[indexRight];
    array[indexRight] = tmp;
}

void Quicksort::swap(double* array, int indexLeft, int indexRight)
{
    double tmp = array[indexLeft];
    array[indexLeft] = array[indexRight];
    array[indexRight] = tmp;
}
