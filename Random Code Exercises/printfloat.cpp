#include <iostream>

using namespace std;

printFloat(float num)
{
    for (int i = 0; i < 32; i++)
    {
        int a = ((i << 0x01) & num) >> i;
        cout << a;
    }
}

int main()
{
    float a = 123.456;
    printFloat(a);
}