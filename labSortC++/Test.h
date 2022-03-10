#pragma once
#include <string>
class Test
{

public:
    static void testSort(
        std::string avgTimeFileName,
        std::string arraySizeFileName,
        int minSize,
        int maxSize,
        int step,
        int numberLaunches,
        int from,
        int until,
        double sortRatio,
        int sortedPosition
    );
    static void testSort(
        std::string avgTimeFileName,
        std::string arraySizeFileName,
        int minSize,
        int maxSize,
        int step,
        int numberLaunches,
        double from,
        double until,
        double sortRatio,
        int sortedPosition
    );
};

