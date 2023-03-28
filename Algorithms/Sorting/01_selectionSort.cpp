#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[], int n)
{
    int start_unsorted, loop_unsorted, min_idx;

    for (start_unsorted = 0; start_unsorted < n - 1; start_unsorted++)
    {
        min_idx = start_unsorted;
        for (loop_unsorted = start_unsorted + 1; loop_unsorted < n; loop_unsorted++)
        {
            if (arr[loop_unsorted] < arr[min_idx])
            {
                min_idx = loop_unsorted;
            }

            if (min_idx != start_unsorted)
            {
                swap(&arr[min_idx], &arr[start_unsorted]);
            }
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
}
int main()
{
    int arr[] = {65, 25, 22, 22, 30, 32};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}
