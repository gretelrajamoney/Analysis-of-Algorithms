/* Name: Gretel Rajamoney
 * Date: 2/6/2021
 * Assignment: HW4
 * Program: activity.cpp
 * Language: C++
 * 
 * Resources Used:
 * my original insertion.cpp algorithm
 * that was originally created in hw1
 *
 * link instructing how to read a file
 * until it reaches an empty line
 * https://stackoverflow.com/questions/21647/reading-from-text-file-until-eof-repeats-last-line
 *  
 */

// imports necessary libraries
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


void selectActivity(int start[], int finish[], int position[], int n)
{
	// creates temporary variables to hold array elements while sorting
	int temp_start;
	int temp_finish;
	int temp_pos;

	// sort the activities in descending order based on their finish times
	// implemented insertion sort in order to sort the array (from hw 1)
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (start[j] < start[j + 1])
			{
				temp_start = start[j];
				temp_finish = finish[j];
				temp_pos = position[j];
			
				start[j] = start[j + 1];
				finish[j] = finish[j + 1];
				position[j] = position[j + 1];
				
				start[j + 1] = temp_start;
				finish[j + 1] = temp_finish;
				position[j + 1] = temp_pos;
			}
		}
	}

	// creates a count variable to hold total of completed activities
	int count = 1;

	int i = 0;
	int current = 0;

	// creates a temporary array to hold indexes of selected activities
	int reverse[1000];

	// parses through array, storing selected activities into reverse array
	for (int j = 1; j < n; j++)
	{
		if (start[current] >= finish[j])
		{
			count = count + 1;
			reverse[i] = position[j];
			current = j;
			i = i + 1;
		}
	}

	// prints out the total count of activities selected
	cout << "total number of activities selected: " << count << endl;
	int num = count - 2;

	// prints out the activities that were selected prompt
	cout << "activities selected: ";

	// parses through reverse array in backwards order
	// prints out the selected activities with spacing
	for (int i = num; i >= 0; i--)
	{
		cout << reverse[i] << " ";
	}
	
	// prints out the last selected activity
	cout << position[0] << " ";
	cout << endl;
	cout << endl;
}


int main()
{
	// create variables
	int numActivity[1000];
	int startTime[1000];
	int endTime[1000];
	int totalActivities;

	// reads in act.txt data file
	ifstream activities("act.txt");

	// prints out error message if it fails to open
	if (activities.fail())
	{
		cout << "ERROR: act.txt file did not open :(" << endl;
		return 0;
	}

	// creates a variable to hold the set count
	int setCount = 1;

	// runs until the data file is empty
	while (!activities.eof())
	{
		// prints out the set count to the user and increments
		cout << "set number: " << setCount << endl;
		setCount = setCount + 1;

		// stores the total number of activities in the set
		activities >> totalActivities;
		cout << "total number of activities: " << totalActivities << endl;
	
		// stores all values from act.txt into their respective arrays
		for (int x = 0; x < totalActivities; x++)
		{
			activities >> numActivity[x];
			activities >> startTime[x];
			activities >> endTime[x];
		}

		// calls the selectActivity greedy algorithm created above
		selectActivity(startTime, endTime, numActivity, totalActivities);
	}
	
	// closes act.txt file prior to terminating
	activities.close();
	return 0;
}




































