/* Name: Gretel Rajamoney
 * Date: 1/27/2021
 * Assignment: HW 3
 * Program: knapsack.cpp
 * Language: c++
 *
 * Resources Used:
 * class lectures discussing the algorithm
 * old homework assignment syntax for runtimes
 */


// imports necessary libraries
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


// recursively calculates knapsack algorithm
int recursiveKnapsack(int n, int val[], int wt[], int W)
{
	if (n == 0)
	{
		return 0;
	}
	
	else if (W == 0)
	{
		return 0;
	}

	else if (W < wt[n - 1])
	{
		return recursiveKnapsack(n - 1, val, wt, W);
	}

	else
	{
		// returns the bigger value out of the two calculations
		int num1 = val[n - 1] + recursiveKnapsack(n - 1, val, wt, W - wt[n - 1]);
		int num2 = recursiveKnapsack(n - 1, val, wt, W);
		int bigger;

		if (num1 > num2)
		{
			bigger = num1;
		}

		else
		{
			bigger = num2;
		}
		return bigger;
	}

}


// creates knapsack algorithm using dynamic programming
int dynamicKnapsack(int n, int val[], int wt[], int W)
{
	int DP[n + 1][W + 1]; // creates 2D array to store values

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			if (i == 0)
			{
				DP[i][j] = 0;
			}
			
			else if (j == 0)
			{
				DP[i][j] = 0;
			}

			else if (wt[i - 1] <= j)
			{
				int num1 = val[i - 1] + DP[i - 1][j - wt[i - 1]];
				int num2 = DP[i - 1][j];

				// finds the bigger value and stores it into the array
				if (num1 > num2)
				{
					DP[i][j] = num1;
				}
			
				else
				{
					DP[i][j] = num2;
				}
			}

			else
			{
				DP[i][j] = DP[i - 1][j];
			}
		}
	}

	return DP[n][W];
}



int main()
{
	int n = 0;
	int recursion;
	double recursionTime;
	int dynamic;
	double dynamicTime;
	clock_t startTimeRec;
	clock_t endTimeRec;
	clock_t startTimeDP;
	clock_t endTimeDP;

	// runs n sizes from 0 to 50 incrementing by 5
	while (n <= 50)
	{
		// returns 21 values
		for (int i = 1; i <= 21; i++)
		{
			int* val = (int*)malloc(n * sizeof(int)); // dynamically allocates val array size
			int* wt = (int*)malloc(n * sizeof(int)); // dynamically allocates wt array size
			int W = 10000; // sets W to a constant value

			// generates random values for val and wt arrays
			for (int j = 0; j < n; j++)
			{
				val[j] = rand() % 50;
				wt[j] = rand() % 50;
			}

			startTimeRec = clock();	// starts time for recursive algorithm
			//recursion = recursiveKnapsack(n, val, wt, W); // calls the recursive function and saves result
			endTimeRec = clock(); // ends time for recursive algorithm
			recursionTime = ((double)(endTimeRec - startTimeRec)) / CLOCKS_PER_SEC * 1.0; // calculates runtime for recusive algorithm

			startTimeDP = clock(); // starts time for dynamically programmed algorithm
			dynamic = dynamicKnapsack(n, val, wt, W); // calls the dynamically programmed function and saves result
			endTimeDP = clock(); // ends time for dynamically programmed algorithm
			dynamicTime = ((double)(endTimeDP - startTimeDP)) / (CLOCKS_PER_SEC / 1000.0); // calculates runtime for dynamically programmed algorithm


			// prints out runtimes, maximums, n sizes, W constant for both algorithms in requested format
			cout << "n = " << n << "   W = " << W << "   Rec. Time = " << recursionTime << "   DP Time = " << dynamicTime << "   Rec. Max = " << recursion << "   DP Max = " << dynamic << endl;
			n = n + 5; // increments size by 5
		}
		return 0;
	}

}

