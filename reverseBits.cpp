#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

long reverseBits(long n)
{
    long sum = 0;
    for (long i = 0; i < 32; ++i)
    {
        sum += (n % 2) * pow(2, 31 - i);
        n /= 2;
    }
    return sum;
}

int main()
{
    cout << reverseBits(12) << endl;
}