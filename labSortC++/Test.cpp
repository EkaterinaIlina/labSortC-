#include "Test.h"
#include <iostream>
#include <fstream>
#include <string>
#include "ArrayGenerator.h"
#include "Quicksort.h"

void Test::testSort(std::string avgTimeFileName, std::string arraySizeFileName, int minSize, int maxSize, int step, int numberLaunches, int from, int until, double sortRatio, int sortedPosition)
{
    std::ofstream avgTimeFile(avgTimeFileName);
    std::ofstream arraySizeFile(arraySizeFileName);

    for (int size = minSize; size <= maxSize; size += step)
    {
        clock_t sumTime = 0;
        double avgTime;

        for (int i = 0; i < numberLaunches; i++)
        {
            int* array = ArrayGenerator::generateInt(size, from, until, sortRatio, sortedPosition);

            clock_t begin = clock();
            Quicksort::sort(array, 0, size - 1);
            sumTime += clock() - begin;

            delete array;
        }
        avgTime = (double)sumTime / numberLaunches;

        if (avgTimeFile.is_open())
        {
            avgTimeFile << avgTime << std::endl;
        }

        if (arraySizeFile.is_open())
        {
            arraySizeFile << size << std::endl;
        }
    }

    avgTimeFile.close();
    arraySizeFile.close();
}

void Test::testSort(std::string avgTimeFileName, std::string arraySizeFileName, int minSize, int maxSize, int step, int numberLaunches, double from, double until, double sortRatio, int sortedPosition)
{
    std::ofstream avgTimeFile(avgTimeFileName);
    std::ofstream arraySizeFile(arraySizeFileName);

    for (int size = minSize; size <= maxSize; size += step)
    {
        clock_t sumTime = 0;
        double avgTime;

        for (int i = 0; i < numberLaunches; i++)
        {
            double* array = ArrayGenerator::generateDouble(size, from, until, sortRatio, sortedPosition);

            clock_t begin = clock();
            Quicksort::sort(array, 0, size - 1);
            sumTime += clock() - begin;

            delete array;
        }
        avgTime = (double)sumTime / numberLaunches;

        if (avgTimeFile.is_open())
        {
            avgTimeFile << avgTime << std::endl;
        }

        if (arraySizeFile.is_open())
        {
            arraySizeFile << size << std::endl;
        }
    }

    avgTimeFile.close();
    arraySizeFile.close();
}
