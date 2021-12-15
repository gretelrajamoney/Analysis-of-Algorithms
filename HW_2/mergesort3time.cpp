/* Name: Gretel Rajamoney
 * Date: 1/20/2021
 * Assignment: HW 2
 * Program: mergesort3time.cpp
 * Resources Used: professors lecture videos
 * she goes over exact examples in C++ !!
 * Language: C++
 */

//imports necessary libraries
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <time.h>

using namespace std;


//My merge3 function which sorts the array in ascending order and returns it.
//I created my merge sort function through implementing the same logic that was
//used within our Algorithms ch1 reading from week 1. The merge3 section found
//in this program is the same one used in the HW_1 merge sort last week.
void merge3(int numArray[], int p, int q, int r) {

    int firstNum = q - p + 1;
    int secondNum = r - q;

    //creates temporary arrays
    int leftArray[10000];
    int rightArray[10000];

    for (int i = 0; i < firstNum; i++)
    {
        leftArray[i] = numArray[p + i];
    }

    int i = 0;

    for (int j = 0; j < secondNum; j++)
    {
        rightArray[j] = numArray[q + 1 + j];
    }

    int j = 0;

    int flag = p;

    //transverses array until sorted in ascending order
    //copies remaining elements back into the array
    while (i < firstNum && j < secondNum) {
        if (rightArray[j] > leftArray[i]) {
            numArray[flag] = leftArray[i];
            i = i + 1;
        }
        else {
            numArray[flag] = rightArray[j];
            j = j + 1;
        }
        flag = flag + 1;
    }

    while (firstNum > i) {
        numArray[flag] = leftArray[i];
        i = i + 1;
        flag = flag + 1;
    }

    while (secondNum > j) {
        numArray[flag] = rightArray[j];
        j = j + 1;
        flag = flag + 1;
    }
}


//My mergeSort3 function essentially splits the array into three
//separate sections and then sorts it by calling the merge3 function.
void mergeSort3(int numArray[], int left, int right) {
    if (right == (left + 1))
    {
        if (numArray[right] > numArray[left])
        {
            int flag = numArray[left];
            numArray[left] = numArray[right];
            numArray[right] = flag;
        }
    }
    if (left < right)
    {
        int splitSize = (right - left + 1) / 3;

        mergeSort3(numArray, left, left + splitSize - 1);
        mergeSort3(numArray, left + splitSize, left + splitSize + splitSize);
        mergeSort3(numArray, left + splitSize + splitSize + 1, right);
        merge3(numArray, left, left + splitSize - 1, left + splitSize + splitSize);
        merge3(numArray, left, left + splitSize + splitSize, right);
    }
}


//My printSorted function essentially prints out the sorted array
//in ascending order with spaces between each number when called.
void printSorted(int numArray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << numArray[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand(time(NULL));
    int testArray1[100000];
    int testArray2[10000];

    for (int i = 0; i < 1000; i++)
    {
        testArray1[i] = rand() % 10000;
        testArray2[i] = testArray1[i];
    }

    //sets for loop that starts at zero and increments the
    //size by 10,000 each run to test the runtimes
    for (int n = 0; n <= 100000; n = n + 10000)
    {
        double total = 0;
        int x = 11;

        for (int i = 1; i <= x; i++)
        {
            for (int j = 0; j < n; j++)
            {
                //creates a random array of correct size to test
                testArray1[i] = rand() % 50;
                testArray2[j] = testArray1[j];
            }

            //calculates the time of the run using clock() functions
            clock_t start = clock();
            mergeSort3(testArray2, 0, n - 1);
            clock_t end = clock();
            double runtime = (double)(end - start) * 1.0 / (CLOCKS_PER_SEC * 1.0 / 1000.0);
            total = total + runtime;
        }

        //calculates the average by dividing the runtime by array size
        double average = total / x;

        //prints out the runtime for each array size
        cout << n << " " << average << endl;
    }
    return 0;
}