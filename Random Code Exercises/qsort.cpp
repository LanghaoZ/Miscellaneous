#include <iostream>
#include <vector>

int partition(vector<int>& arr, int lo, int hi)
{
    int pivot = arr[hi];
    int index = lo - 1;

    for (int i = low; i < hi; i++)
    {
        if (arr[i] <= pivot)
        {
            index++;
            swap(arr[index], arr[i]);
        }
    }

    swap(arr[index + 1], arr[hi]);
    return index + 1;
}

void qsort(vector<int>& arr, int lo, int hi)
{
    if (lo < hi)
    {
        int mid = partition(arr, lo, hi);
        qsort(arr, lo, mid - 1);
        qsort(arr, mid + 1, hi);
    }
}

void quickSort(vector<int>& arr)
{
    qsort(arr, 0, arr.size() - 1);
}

int main()
{
    
}

