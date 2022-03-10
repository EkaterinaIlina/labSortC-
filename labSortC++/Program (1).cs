using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace Sorting
{
    internal class Program
    {

        static void Main(string[] args)
        {
            int intMinSize = 0;
            int intMaxSize = 100000;
            int doubleMinSize = 0;
            int doubleMaxSize = 100000;
            int step = 1000;

            // 1) different sorting options
            // 1.1) not sorted
            TestSort(
                    "1-1-notSorted-avgTime.txt",
                    "1-1-notSorted-arraySize.txt",
                    intMinSize,
                    intMaxSize,
                    step,
                    100,
                    int.MinValue,
                    int.MaxValue,
                    0.0,
                    1
            );

            // 1.2) sort ratio 0.25, sorted block in begin
            TestSort(
                    "1-2-025-begin-avgTime.txt",
                    "1-2-025-begin-arraySize.txt",
                    intMinSize,
                    intMaxSize,
                    step,
                    100,
                    int.MinValue,
                    int.MaxValue,
                    0.25,
                    1
            );

            // 1.3) sort ratio 0.25, sorted block in middle
            TestSort(
                    "1-3-025-middle-avgTime.txt",
                    "1-3-025-middle-arraySize.txt",
                    intMinSize,
                    intMaxSize,
                    step,
                    100,
                    int.MinValue,
                    int.MaxValue,
                    0.25,
                    2
            );

            // 1.4) sort ratio 0.25, sorted block in end
            TestSort(
                    "1-4-025-end-avgTime.txt",
                    "1-4-025-end-arraySize.txt",
                    intMinSize,
                    intMaxSize,
                    step,
                    100,
                    int.MinValue,
                    int.MaxValue,
                    0.25,
                    3
            );

            // 1.5) sort ratio 0.5, sorted block in begin
            TestSort(
                    "1-5-05-begin-avgTime.txt",
                    "1-5-05-begin-arraySize.txt",
                    intMinSize,
                    intMaxSize,
                    step,
                    100,
                    int.MinValue,
                    int.MaxValue,
                    0.5,
                    1
            );

            // 1.6) sort ratio 0.5, sorted block in middle
            TestSort(
                    "1-6-05-middle-avgTime.txt",
                    "1-6-05-middle-arraySize.txt",
                    intMinSize,
                    intMaxSize,
                    step,
                    100,
                    int.MinValue,
                    int.MaxValue,
                    0.5,
                    2
            );

            // 1.7) sort ratio 0.5, sorted block in end
            TestSort(
                    "1-7-05-end-avgTime.txt",
                    "1-7-05-end-arraySize.txt",
                    intMinSize,
                    intMaxSize,
                    step,
                    100,
                    int.MinValue,
                    int.MaxValue,
                    0.5,
                    3
            );

            // 1.8) sort ratio 0.75, sorted block in begin
            TestSort(
                    "1-8-075-begin-avgTime.txt",
                    "1-8-075-begin-arraySize.txt",
                    intMinSize,
                    intMaxSize,
                    step,
                    100,
                    int.MinValue,
                    int.MaxValue,
                    0.75,
                    1
            );

            // 1.9) sort ratio 0.75, sorted block in middle
            TestSort(
                    "1-9-075-middle-avgTime.txt",
                    "1-9-075-middle-arraySize.txt",
                    intMinSize,
                    intMaxSize,
                    step,
                    100,
                    int.MinValue,
                    int.MaxValue,
                    0.75,
                    2
            );

            // 1.10) sort ratio 0.75, sorted block in end
            TestSort(
                    "1-10-075-end-avgTime.txt",
                    "1-10-075-end-arraySize.txt",
                    intMinSize,
                    intMaxSize,
                    step,
                    100,
                    int.MinValue,
                    int.MaxValue,
                    0.75,
                    3
            );

            // 1.11) fully sorted
            TestSort(
                    "1-11-fullySorted-avgTime.txt",
                    "1-11-fullySorted-arraySize.txt",
                    intMinSize,
                    intMaxSize,
                    step,
                    100,
                    int.MinValue,
                    int.MaxValue,
                    1.0,
                    1
            );

            // 2) different ranges of values
            // 2.1) from 0 until MAX_VALUE
            TestSort(
                    "2-1-from-0-until-MAX_VALUE-avgTime.txt",
                    "2-1-from-0-until-MAX_VALUE-arraySize.txt",
                    intMinSize,
                    intMaxSize,
                    step,
                    100,
                    0,
                    int.MaxValue,
                    0.0,
                    1
            );

            // 2.2) from MIN_VALUE until 0
            TestSort(
                    "2-2-from-MIN_VALUE-until-0-avgTime.txt",
                    "2-2-from-MIN_VALUE-until-0-arraySize.txt",
                    intMinSize,
                    intMaxSize,
                    step,
                    100,
                    int.MinValue,
                    0,
                    0.0,
                    1
            );

            // 2.3) from MIN_VALUE until MAX_VALUE
            TestSort(
                    "2-3-from-MIN_VALUE-until-MAX_VALUE-avgTime.txt",
                    "2-3-from-MIN_VALUE-until-MAX_VALUE-arraySize.txt",
                    intMinSize,
                    intMaxSize,
                    step,
                    100,
                    int.MinValue,
                    int.MaxValue,
                    0.0,
                    1
            );

            // 2.4) from -100 until 101
            TestSort(
                    "2-4-from--100-until-101-avgTime.txt",
                    "2-4-from--100-until-101-arraySize.txt",
                    intMinSize,
                    intMaxSize,
                    step,
                    100,
                    -100,
                    101,
                    0.0,
                    1
            );

            // 3) different types of data
            // 3.1) int array
            TestSort(
                    "3-1-int-avgTime.txt",
                    "3-1-int-arraySize.txt",
                    intMinSize,
                    intMaxSize,
                    step,
                    100,
                    int.MinValue,
                    int.MaxValue,
                    0.0,
                    1
            );

            // 3.2) double array
            TestSort(
                    "3-2-double-avgTime.txt",
                    "3-2-double-arraySize.txt",
                    doubleMinSize,
                    doubleMaxSize,
                    step,
                    100,
                    double.MinValue,
                    double.MaxValue,
                    0.0,
                    1
            );
        }

        private static void TestSort
            (
            String avgTimeFileName,
            String arraySizeFileName,
            int minSize,
            int maxSize,
            int step,
            int numberLaunches,
            int from,
            int until,
            double sortRatio,
            int sortedPosition
            ) {

            try
            {
                using StreamWriter avgTimeFile = new StreamWriter(avgTimeFileName, false, Encoding.UTF8);
                using StreamWriter arraySizeFile = new StreamWriter(arraySizeFileName, false, Encoding.UTF8);

                for (int size = minSize; size <= maxSize; size += step)
                {
                    double sumTime = 0;
                    double avgTime;

                    for (int i = 0; i < numberLaunches; i++)
                    {
                        int[] array = ArrayGenerator.GenerateInt(size, from, until, sortRatio, sortedPosition);

                        Stopwatch sw = Stopwatch.StartNew();
                        Quicksort.Sort(array, 0, array.Length - 1);
                        sw.Stop();

                        sumTime += sw.Elapsed.TotalMilliseconds;
                    }
                    avgTime = (double)sumTime / numberLaunches;

                    avgTimeFile.WriteLine(avgTime);
                    avgTimeFile.Flush();

                    arraySizeFile.WriteLine(size);
                    arraySizeFile.Flush();
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
        }

        private static void TestSort
            (
            String avgTimeFileName,
            String arraySizeFileName,
            int minSize,
            int maxSize,
            int step,
            int numberLaunches,
            double from,
            double until,
            double sortRatio,
            int sortedPosition
            ) {

            try
            {
                using StreamWriter avgTimeFile = new StreamWriter(avgTimeFileName, false, Encoding.UTF8);
                using StreamWriter arraySizeFile = new StreamWriter(arraySizeFileName, false, Encoding.UTF8);

                for (int size = minSize; size <= maxSize; size += step)
                {
                    double sumTime = 0;
                    double avgTime;

                    for (int i = 0; i < numberLaunches; i++)
                    {
                        double[] array = ArrayGenerator.GenerateDouble(size, from, until, sortRatio, sortedPosition);

                        Stopwatch sw = Stopwatch.StartNew();
                        Quicksort.Sort(array, 0, array.Length - 1);
                        sw.Stop();

                        sumTime += sw.Elapsed.TotalMilliseconds;
                    }
                    avgTime = (double)sumTime / numberLaunches;

                    avgTimeFile.WriteLine(avgTime);
                    avgTimeFile.Flush();

                    arraySizeFile.WriteLine(size);
                    arraySizeFile.Flush();
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
        }
    }
}
