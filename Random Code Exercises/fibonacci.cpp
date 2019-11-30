#include <iostream>

long long fib1(int num)
{
    if (num == 0 || num == 1)
        return num;
    
    return fib1(num - 1) + fib1(num - 2);
}

long long fib2(int num)
{
    if (num == 1)
        return 1;

    long long i = 0;
    long long j = 1;
    long long k = 0;

    for (int iter = 2; iter <= num; iter++)
    {
        k = i + j;
        i = j;
        j = k;
    }

    return k;
}