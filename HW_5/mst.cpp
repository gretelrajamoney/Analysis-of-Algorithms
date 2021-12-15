/* Name: Gretel Rajamoney
 * Date: 2/19/2021
 * Assignment: HW5
 * Program: mst.cpp
 * Language: C++
 *
 * Resources Used:
 * Prims Algorithm
 * used lectures as well as online syntax regarding how to locate the mst
 * https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
 *
 * Powers & Square Roots
 * http://www.cplusplus.com/forum/beginner/107564/
 *
 * Rounding Numbers
 * https://www.programiz.com/cpp-programming/library-function/cmath/round
 */


// imports necessary libraries
#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>


using namespace std;


// defines all functions
int findKey(int[], bool[], int);
void primAlgorithm(int adjMatrix[30][30], int);


// this function creates an adjacency matrix that stores all of the
// distances between all of the coordinates in the graph.txt file
void createAdjacency(int xCoord[], int yCoord[], int caseVertices)
{
	// creates the adjacency matrix
	int adjMatrix[30][30];

	for (int i = 0; i < caseVertices; i++)
	{
		for (int j = 0; j < caseVertices; j++)
		{
			if (i == j)
			{
				adjMatrix[i][j] = 0;
			}

			else
			{
				// calculates the distance between points
				// using the formula provided on the pdf
				int tempX1 = xCoord[i];
				int tempY1 = yCoord[i];
				int tempX2 = xCoord[j];
				int tempY2 = yCoord[j];

				int subX = tempX1 - tempX2;
				int subY = tempY1 - tempY2;
	
				int powX = pow(subX, 2);
				int powY = pow(subY, 2);

				int XY = powX + powY;
				
				// rounds the distance to the nearest number
				int root = round(sqrt(XY));
				
				// stores the distance into the adjacency matrix
				adjMatrix[i][j] = root;
			}
		}
	}

	// calls the prim algorithm function to find the mst
	primAlgorithm(adjMatrix, caseVertices);

}



// this function calculates and returns the mst using prim's algorithm
void primAlgorithm (int adjMatrix[30][30], int caseVertices)
{
	// creates arrays to store calculated values
	int original[30];
	int key[30];
	bool mst[30];

	// transverses through arrays to store infinity and false values
	for (int i = 0; i < caseVertices; i++)
	{
		key[i] = INT_MAX;
		mst[i] = false;
	}

	// stores a 0 and -1 into the first index of array so that it is picked first
	key[0] = 0;
	original[0] = -1;

	for (int x = 1; x < caseVertices; x++)
	{
		// calls the findKey function and stores a true in the index of the key
		int u = findKey(key, mst, caseVertices);
		mst[u] = true;

		// updates the key value in the original array as well as the adjacency matrix
		for (int v = 0; v < caseVertices; v++)
		{
			// updates the key if the matrix is smaller than the key value
			if (adjMatrix[u][v] && adjMatrix[u][v] < key[v] && mst[v] == false)
			{
				original[v] = u;
				key[v] = adjMatrix[u][v];
			}
		}
	}

	// creates a variable to count the total distance
	int measure = 0;
	cout << "total distance: ";

	// transverses through array until total distance is calculated
	for (int i = 1; i < caseVertices; i++)
	{
		measure = measure + adjMatrix[i][original[i]];
	}

	// prints out the total distance
	cout << measure << endl;
}


// finds the location of the minimum key value
int findKey (int key[], bool mst[], int caseVertices)
{
	// creates the minimum value
	int min = INT_MAX, minIndex;

	for (int v = 0; v < caseVertices; v++)
	{
		if (mst[v] == false && key[v] < min)
		{
			minIndex = v;
			min = key[v];
		}
	}

	// returns the index of the minimum value
	return minIndex;

}




int main()
{
	// creates variables to hold data from file
	int testCases;
	int caseVertices;

	// reads in the graph.txt file
	ifstream graph("graph.txt");

	// prints out an error message if the file can not be opened
	if (graph.fail())
	{
		cout << "ERROR: graph.txt file did not open :(" << endl;
		return 0;
	}

	// stores the total amount of cases in the variable
	graph >> testCases;

	// transveres through data until all test cases are completed
	for (int i = 1; i <= testCases; i++)
	{
		cout << "test case: " << i << endl;
		
		// stores the total number of vertices in the variable
		graph >> caseVertices;
	
		// creates array to hold x and y coordinate
		int xCoord[caseVertices];
		int yCoord[caseVertices];
	
		// transverses through all vertices until coordinates are stored
		for (int j = 0; j < caseVertices; j++)
		{
			graph >> xCoord[j];
			graph >> yCoord[j];
		}

		// calls the function to create the adjacency matrix
		createAdjacency(xCoord, yCoord, caseVertices);
		cout << endl;
	}
}

















































































































































































