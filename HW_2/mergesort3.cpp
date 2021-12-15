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

using namespace std;


//My merge3 function which sorts the array in ascending order and returns it.
//I created my merge sort function through implementing the same logic that was
//used within our Algorithms ch1 reading from week 1. The merge3 section found
//in this program is the same one used in the HW_1 merge sort last week.
void merge3(int numArray[], int p, int q, int r) {

    int firstNum = q - p + 1;
    int secondNum = r - q;

    //creates temporary arrays
    int leftArray[1000];
    int rightArray[1000];

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


int main() {
    {
        //imports the data.txt file to be sorted
        ifstream data("data.txt");

        //if the text file does not open, error message prints
        if (data.fail()) {
            cout << "ERROR: data.txt file did not open :(" << endl;
            return 0;
        }

        int x;
        int* numArray;

        //stores the data.txt values into an array
        while (data >> x) {
            numArray = new int[x];
            int j = 0;

            while (x > j) {
                data >> numArray[j];
                j++;
            }

            //calls the mergeSort3 function to sort data.txt values
            mergeSort3(numArray, 0, x - 1);
            //calls the printSorted function to print sorted values
            printSorted(numArray, x);
        }

        //closes the imported data.txt file
        data.close();
        return 0;
    }
}
