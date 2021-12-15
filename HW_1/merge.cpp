#include <iostream>
#include <fstream>

using namespace std;

void merge(int numArray[], int p, int q, int r) {

    int firstNum = q - p + 1;
    int secondNum = r - q;

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

int main() {
    {
        ifstream data("data.txt");
        if (data.fail()) {
            cout << "ERROR: data.txt file did not open :(" << endl;
            return 0;
        }

        int x;
        int* numArray;

        while (data >> x) {
            numArray = new int[x];
            int j = 0;

            while (x > j) {
                data >> numArray[j];
                j++;
            }

            mergeSort(numArray, 0, x - 1);
            printSorted(numArray, x);
        }

        data.close();
        return 0;
    }
}
