#include <iostream>

using namespace std;

int findMax(int input[], int lo, int hi)
{
    int mid = lo + ((hi - lo) / 2);

    if (mid == lo || mid == hi)
        return mid;

    // int midEle = input[mid];
    // int loEle = input[lo];
    // int hiEle = input[hi];

    // if (midEle < loEle)
    //     return findMax(input, lo, mid);
    
    // else
    // {
    //     return findMax(input, mid, hi);
    // }

    bool increasing = input[mid] >= input[mid - 1] ? true : false;

    if (increasing)
        return findMax(input, mid, hi);
    else
        return findMax(input, lo, mid);
    

}

int findMaxWrapper(int input[])
{
    int n = input.size();
    return findMax(input, 0, n);
}
