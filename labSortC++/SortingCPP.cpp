// SortingCPP.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <string>
#include "ArrayGenerator.h"
#include "Quicksort.h"
#include "Test.h"

int main()
{
    int intMinSize = 0;
    int intMaxSize = 100000;
    int doubleMinSize = 0;
    int doubleMaxSize = 100000;
    int step = 1000;

    //// 1) different sorting options
    //// 1.1) not sorted
    //Test::testSort(
    //    "1-1-notSorted-avgTime.txt",
    //    "1-1-notSorted-arraySize.txt",
    //    intMinSize,
    //    intMaxSize,
    //    step,
    //    100,
    //    INT_MIN,
    //    INT_MAX,
    //    0.0,
    //    1
    //);

    //// 1.2) sort ratio 0.25, sorted block in begin
    //Test::testSort(
    //    "1-2-025-begin-avgTime.txt",
    //    "1-2-025-begin-arraySize.txt",
    //    intMinSize,
    //    intMaxSize,
    //    step,
    //    100,
    //    INT_MIN,
    //    INT_MAX,
    //    0.25,
    //    1
    //);

    //// 1.3) sort ratio 0.25, sorted block in middle
    //Test::testSort(
    //    "1-3-025-middle-avgTime.txt",
    //    "1-3-025-middle-arraySize.txt",
    //    intMinSize,
    //    intMaxSize,
    //    step,
    //    100,
    //    INT_MIN,
    //    INT_MAX,
    //    0.25,
    //    2
    //);

    //// 1.4) sort ratio 0.25, sorted block in end
    //Test::testSort(
    //    "1-4-025-end-avgTime.txt",
    //    "1-4-025-end-arraySize.txt",
    //    intMinSize,
    //    intMaxSize,
    //    step,
    //    100,
    //    INT_MIN,
    //    INT_MAX,
    //    0.25,
    //    3
    //);

    //// 1.5) sort ratio 0.5, sorted block in begin
    //Test::testSort(
    //    "1-5-05-begin-avgTime.txt",
    //    "1-5-05-begin-arraySize.txt",
    //    intMinSize,
    //    intMaxSize,
    //    step,
    //    100,
    //    INT_MIN,
    //    INT_MAX,
    //    0.5,
    //    1
    //);

    //// 1.6) sort ratio 0.5, sorted block in middle
    //Test::testSort(
    //    "1-6-05-middle-avgTime.txt",
    //    "1-6-05-middle-arraySize.txt",
    //    intMinSize,
    //    intMaxSize,
    //    step,
    //    100,
    //    INT_MIN,
    //    INT_MAX,
    //    0.5,
    //    2
    //);

    //// 1.7) sort ratio 0.5, sorted block in end
    //Test::testSort(
    //    "1-7-05-end-avgTime.txt",
    //    "1-7-05-end-arraySize.txt",
    //    intMinSize,
    //    intMaxSize,
    //    step,
    //    100,
    //    INT_MIN,
    //    INT_MAX,
    //    0.5,
    //    3
    //);

    //// 1.8) sort ratio 0.75, sorted block in begin
    //Test::testSort(
    //    "1-8-075-begin-avgTime.txt",
    //    "1-8-075-begin-arraySize.txt",
    //    intMinSize,
    //    intMaxSize,
    //    step,
    //    100,
    //    INT_MIN,
    //    INT_MAX,
    //    0.75,
    //    1
    //);

    //// 1.9) sort ratio 0.75, sorted block in middle
    //Test::testSort(
    //    "1-9-075-middle-avgTime.txt",
    //    "1-9-075-middle-arraySize.txt",
    //    intMinSize,
    //    intMaxSize,
    //    step,
    //    100,
    //    INT_MIN,
    //    INT_MAX,
    //    0.75,
    //    2
    //);

    //// 1.10) sort ratio 0.75, sorted block in end
    //Test::testSort(
    //    "1-10-075-end-avgTime.txt",
    //    "1-10-075-end-arraySize.txt",
    //    intMinSize,
    //    intMaxSize,
    //    step,
    //    100,
    //    INT_MIN,
    //    INT_MAX,
    //    0.75,
    //    3
    //);

    //// 1.11) fully sorted
    //Test::testSort(
    //    "1-11-fullySorted-avgTime.txt",
    //    "1-11-fullySorted-arraySize.txt",
    //    intMinSize,
    //    intMaxSize,
    //    step,
    //    100,
    //    INT_MIN,
    //    INT_MAX,
    //    1.0,
    //    1
    //);

    //// 2) different ranges of values
    //// 2.1) from 0 until MAX_VALUE
    //Test::testSort(
    //    "2-1-from-0-until-MAX_VALUE-avgTime.txt",
    //    "2-1-from-0-until-MAX_VALUE-arraySize.txt",
    //    intMinSize,
    //    intMaxSize,
    //    step,
    //    100,
    //    0,
    //    INT_MAX,
    //    0.0,
    //    1
    //);

    //// 2.2) from MIN_VALUE until 0
    //Test::testSort(
    //    "2-2-from-MIN_VALUE-until-0-avgTime.txt",
    //    "2-2-from-MIN_VALUE-until-0-arraySize.txt",
    //    intMinSize,
    //    intMaxSize,
    //    step,
    //    100,
    //    INT_MIN,
    //    0,
    //    0.0,
    //    1
    //);

    //// 2.3) from MIN_VALUE until MAX_VALUE
    //Test::testSort(
    //    "2-3-from-MIN_VALUE-until-MAX_VALUE-avgTime.txt",
    //    "2-3-from-MIN_VALUE-until-MAX_VALUE-arraySize.txt",
    //    intMinSize,
    //    intMaxSize,
    //    step,
    //    100,
    //    INT_MIN,
    //    INT_MAX,
    //    0.0,
    //    1
    //);

    //// 2.4) from -100 until 101
    //Test::testSort(
    //    "2-4-from--100-until-101-avgTime.txt",
    //    "2-4-from--100-until-101-arraySize.txt",
    //    intMinSize,
    //    intMaxSize,
    //    step,
    //    100,
    //    -100,
    //    101,
    //    0.0,
    //    1
    //);

    //// 3) different types of data
    //// 3.1) int array
    //Test::testSort(
    //    "3-1-int-avgTime.txt",
    //    "3-1-int-arraySize.txt",
    //    intMinSize,
    //    intMaxSize,
    //    step,
    //    100,
    //    INT_MIN,
    //    INT_MAX,
    //    0.0,
    //    1
    //);

    //// 3.2) double array
    //Test::testSort(
    //    "3-2-double-avgTime.txt",
    //    "3-2-double-arraySize.txt",
    //    doubleMinSize,
    //    doubleMaxSize,
    //    step,
    //    100,
    //    DBL_MIN,
    //    DBL_MAX,
    //    0.0,
    //    1
    //);
}
