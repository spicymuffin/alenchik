#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <random>
#include <cstdlib>
#include <ctime>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

#include "util.h"

vector<int> countFrequency(int n, int x, vector<int> &nums)
{
    vector<int> alen(x, 0);

    for (auto it : nums)
    {
        alen[it - 1]++;
    }

    return alen;
}

int main()
{
    vector<int> retard = {1,
                          3,
                          4,
                          3,
                          4,
                          1};
    vector<int> alen = countFrequency(6, 4, retard);
}