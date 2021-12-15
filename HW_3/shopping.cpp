/* Name: Gretel Rajamoney
 * Date: 1/27/2021
 * Assignment: HW 3
 * Program: shopping.cpp
 * Language: c++
 *
 * Resources Used: 
 * geeks for geeks sorting 2D vector in c++
 * https://www.geeksforgeeks.org/sorting-2d-vector-in-c-set-1-by-row-and-column/
 * c++ reference library
 * https://www.cplusplus.com/reference/
 */


// imports necessary libraries
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

// the knapsack algorithm is implemented using dynamic programming
// n = number of objects, val = object price, wt = object weight,
// W = carrying capacity, vector o = stores what each member carried
int dynamicKnapsack(int n, int val[], int wt[], int W, vector<int> &o)
{
	int DP[n + 1][W + 1]; //creates 2D array

	// finds the highest value sack each member can carry that is
	// either equal to or lower than their respective carrying limit
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

				// finds the bigger number and stores it in the array
				if(num1 > num2)
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

	// takes the maximum value from the array and saves it 		
	int knapsack = DP[n][W];
	int x = W;

	// saves all items carried by each member and stores it into the vector
	// using push_back function, the value gets moves to the end each time
	for (int z = n; z > 0 && knapsack > 0; z--)
	{
		if (knapsack != DP[z - 1][x])
		{
                        o.push_back(z);
                        knapsack = knapsack - val[z - 1]; // subtracts item price from the total value
                        x = x - wt[z - 1]; // subtracts item weight from the carrying capacity
		}
	}
	
	return DP[n][W]; // returns the maximum value
}


int main()
{
	int testCases;
	int totalObjects;
	int familySize;
	int carryCapacity;
	int highestPrice;
	int sack;

	int objectPrice[5000]; // creates array to hold object prices
	int objectWeight[100]; // creates array to hold object weights

	// opens the shopping.txt file and prints error if unable to open
	ifstream shopping("shopping.txt");
	if (shopping.fail()) 
	{
		cout << "ERROR: shopping.txt file did not open :(" << endl;
		return 0;
	}

	// opens the results.txt file and prints error if unable to open
	ofstream results("results.txt");
	if (results.fail())
	{
		cout << "ERROR: results.txt file did not open :(" << endl;
		return 0;
	}

	// stores the number of test cases from shopping.txt into variable
	shopping >> testCases;

	// prints out test case header into results.txt file
	for (int x = 0; x < testCases; x++)
	{
		results << "Test Case: #" << x + 1 << endl;
		shopping >> totalObjects; // stores total number of objects into variable

		// stores the price and weights of each object into an array
		for (int y = 0; y < totalObjects; y++)
		{
			shopping >> objectPrice[y];
			shopping >> objectWeight[y];
		}

		shopping >> familySize; // stores the number of family members into a variable
		vector<vector<int> >objects(100); // creates a vector of size 100 to hold which item was carried
		highestPrice = 0; // resets the highest price to 0 after each iteration

		for (int z = 0; z < familySize; z++)
		{
			shopping >> carryCapacity; // stores the carrying capacity of each family member

			// calls the dynamically programmed knapsack algorithm
			sack = dynamicKnapsack(totalObjects, objectPrice, objectWeight, carryCapacity, objects[z]);
			highestPrice = highestPrice + sack;
		}

		// writes the total value and items prompt to results.txt
		results << "Total Value: $" << highestPrice << endl;
		results << "Each Family Member's Items: " << endl;

		// prints out the list of items each family member carried by
		// locating it witin the vector saved from knapsack algorithm
		for (int i = 0; i < familySize; i++)
		{
			// uses sort function to arrange numbers in increasing order
			sort(objects[i].begin(), objects[i].end());

			// prints out each family member with a colon
			results << i + 1 << ": ";
		
			// prints out the carried objects with commas if necessary
			for (int j = 0; j < objects[i].size(); j++)
			{
				if (j == objects[i].size() - 1)
				{
					results << objects[i][j];
				}
				
				else
				{
					results << objects[i][j] << ", ";
				}
			}
			
			results << endl;
		}
		
		results << endl;
	}
	
	// closes files before exitting
	shopping.close();
	results.close();
	return 0;
}
