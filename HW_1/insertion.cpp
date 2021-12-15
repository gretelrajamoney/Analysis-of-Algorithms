#include <iostream>
#include <fstream>


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
	{
		ifstream data("data.txt");
		if (data.fail()) {
			cout << "ERROR: data.txt file did not open :(" << endl;
			return 0;
		}

		int size;
		int* numArray;

		while (data >> size) {
			numArray = new int[size];
			int j = 0;

			while (size > j) {
				data >> numArray[j];
				j = j + 1;
			}

			insertionSort(numArray, size);
			printSorted(numArray, size);
		}

		data.close();
		return 0;
	}
}