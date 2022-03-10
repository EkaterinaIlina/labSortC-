using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sorting
{
    internal class ArrayGenerator
    {

        private static readonly Random random = new();

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
        //   T:System.ArgumentException:
        //     If from is greater than or equal to until.
        public static int[] GenerateInt(
            int arraySize, 
            int from, 
            int until, 
            double sortRatio, 
            int sortedPosition
            )
        {
            if (from >= until)
            {
                throw new ArgumentException();
            }

            int[] array = new int[arraySize];

            sortRatio = CheckSortRation(sortRatio);
            int sortedSize = (int)(arraySize * sortRatio);

            sortedPosition = CheckSortedPosition(sortedPosition, arraySize, sortedSize);

            int[] sortedArray = new int[sortedSize];
            for (int i = 0; i < sortedSize; i++)
            {
                sortedArray[i] = random.Next(from, until);
            }
            Quicksort.Sort(sortedArray, 0, sortedSize - 1);

            int j = 0;
            for (int i = 0; i < arraySize; i++)
            {
                if (sortedPosition <= i && j < sortedSize)
                {
                    array[i] = sortedArray[j];
                    j++;
                }
                else
                {
                    array[i] = random.Next(from, until);
                }
            }

            return array;
        }

        //
        // Summary:
        //     Returns a randomly generated double array from the specified range of values, with the specified array size, sort ratio and sorted block position.
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
        //   T:System.ArgumentException:
        //     If from is greater than or equal to until.
        public static double[] GenerateDouble(
            int arraySize, 
            double from, 
            double until, 
            double sortRatio, 
            int sortedPosition
            )
        {
            if (from >= until)
            {
                throw new ArgumentException();
            }

            double[] array = new double[arraySize];

            sortRatio = CheckSortRation(sortRatio);
            int sortedSize = (int)(arraySize * sortRatio);

            sortedPosition = CheckSortedPosition(sortedPosition, arraySize, sortedSize);

            double[] sortedArray = new double[sortedSize];
            for (int i = 0; i < sortedSize; i++)
            {
                sortedArray[i] = random.NextDouble() * (until - from) + from;
            }
            Quicksort.Sort(sortedArray, 0, sortedSize - 1);

            int j = 0;
            for (int i = 0; i < arraySize; i++)
            {
                if (sortedPosition <= i && j < sortedSize)
                {
                    array[i] = sortedArray[j];
                    j++;
                }
                else
                {
                    array[i] = random.NextDouble() * (until - from) + from;
                }
            }

            return array;
        }

        private static double CheckSortRation(double sortRatio)
        {
            if (sortRatio > 1.0)
            {
                sortRatio = 1.0;
            }
            else if (sortRatio < 0.0)
            {
                sortRatio = 0.0;
            }

            return sortRatio;
        }

        private static int CheckSortedPosition(int sortedPosition, int arraySize, int sortedSize)
        {
            return _ = sortedPosition switch
            {
                1 => 0,
                2 => (arraySize / 2) - (sortedSize / 2),
                _ => arraySize - sortedSize,
            };
        }
    }
}
