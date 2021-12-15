#include <iostream>
#include <stdlib.h>  
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <time.h>


using namespace std;

void insertionSort(int numArray[], int size)
{
	int save;
	int j;

	for (int i = 1; i < size; i++)
	{
		save = numArray[i];
		j = i - 1;

		while (numArray[j] > save && j >= 0)
		{
			numArray[j + 1] = numArray[j];
			j = j - 1;
		}

		numArray[j + 1] = save;
	}
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

    for (int n = 0; n <= 2000; n = n + 150)
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
            insertionSort(testArray1, n - 1);
            clock_t end1 = clock();
            double runtime1 = (double)(end1 - start1) / (CLOCKS_PER_SEC / 1000);
            total1 = total1 + runtime1;
        }

        double average = total1 / x;

        cout << n << " " << average << endl;
    }
    return 0;
}