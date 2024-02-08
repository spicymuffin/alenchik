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
#include <unordered_map>

using namespace std;

#include "util.h"

vector<int> getFrequencies(vector<int> &v)
{
    unordered_map<int, int> alen; // use an ordered map

    for (const int &it : v)
    {
        alen[it]++;
    }

    int minimum = INT_MAX;
    int min_elem = -1;
    int min_min_elem = INT_MAX;
    int min_min = -1;
    int maximum = INT_MIN;
    int max_elem = -1;
    int min_max_elem = INT_MAX;
    int min_max = -1;

    for (const auto &it : alen)
    {
        if (it.second <= minimum)
        {
            minimum = it.second;
            min_elem = it.first;
            if (min_min != minimum)
            {
                min_min = minimum;
                min_min_elem = min_elem;
            }
            if (min_elem < min_min_elem)
            {
                min_min_elem = min_elem;
            }
        }
        if (it.second >= maximum)
        {
            maximum = it.second;
            max_elem = it.first;
            if (min_max != maximum)
            {
                min_max = maximum;
                min_max_elem = max_elem;
            }
            if (max_elem < min_max_elem)
            {
                min_max_elem = max_elem;
            }
        }
    }
    vector<int> result = {min_max_elem, min_min_elem};

    return result;
}

int main()
{
    vector<int> gay = {11, 13, 3, 14, 17, 3, 7, 9, 1, 11, 9, 15, 5, 2, 2, 3};

    cout << luigiutil::vector_2_string(getFrequencies(gay)) << endl;
}