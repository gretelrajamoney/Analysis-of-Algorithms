#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <time.h>

using namespace std;

void merge(int numArray[], int p, int q, int r) {

    int firstNum = q - p + 1;
    int secondNum = r - q;

    int leftArray[50000];
    int rightArray[50000];

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

void mergeSort(int numArray[], int left, int right) {
    if (right > left) {
        int center = left + (right - left) / 2;

        mergeSort(numArray, left, center);
        mergeSort(numArray, center + 1, right);
        merge(numArray, left, center, right);
    }
}

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

    for (int n = 0; n <= 100000; n = n + 1000)
    {
        double total1 = 0;
        double total2 = 0;
        int x = 11;

        for (int i = 1; i <= x; i++)
        {
            for (int i = 0; i < n; i++)
            {
                testArray1[i] = rand() % 50;
                testArray2[i] = testArray1[i];
            }

            clock_t start2 = clock();
            clock_t end2 = clock();
            double runtime2 = (double)(end2 - start2) / (CLOCKS_PER_SEC / 1000);
            total2 = total2 + runtime2;

            clock_t start1 = clock();
            mergeSort(testArray1, 0, n - 1);
            clock_t end1 = clock();
            double runtime1 = (double)(end1 - start1) / (CLOCKS_PER_SEC / 1000);
            total1 = total1 + runtime1;
        }

        double average = total1 / x;

        cout << n << " " << average << endl;
    }
    return 0;
}


    
        
