#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
}

void merge(int arr[], int start, int mid, int end)
{
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    int *leftArr = new int[leftSize];
    int *rightArr = new int[rightSize];

    for (int i = start; i <= mid; i++)
    {
        leftArr[i - start] = arr[i];
    }

    for (int i = mid + 1; i <= end; i++)
    {
        rightArr[i - mid - 1] = arr[i];
    }

    int i = 0, j = 0, k = start;

    while (i < leftSize && j < rightSize)
    {
        if (leftArr[i] < rightArr[j])
        {

            arr[k] = leftArr[i];
            i++;
        }
        else
        {

            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < leftSize)
    {

        arr[k] = leftArr[i];
        k++;
        i++;
    }

    while (j < rightSize)
    {
        arr[k] = rightArr[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main()
{
    int arr[] = {65, 25, 22, 22, 30, 32};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}
