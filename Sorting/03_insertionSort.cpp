#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
}

void insertionSort(int arr[], int n)
{
    int num;
    for (int i = 1; i < n; i++)
    {
        num = arr[i];
        int j = i;
        while (j > 0 && num < arr[j - 1])
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = num;
    }
}

int main()
{
    int arr[] = {65, 25, 22, 22, 30, 32};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}
