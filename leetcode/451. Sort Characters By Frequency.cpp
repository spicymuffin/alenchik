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

string frequencySort(string s)
{
    map<char, int> smap;

    for (const char &c : s)
    {
        smap[c]++;
    }
    std::vector<std::pair<char, int>> pairs;
    for (auto itr = smap.begin(); itr != smap.end(); ++itr)
        pairs.push_back(*itr);

    std::sort(pairs.begin(), pairs.end(), [=](std::pair<char, int> &a, std::pair<char, int> &b)
              { return a.second > b.second; });

    stringstream ss;

    for (const std::pair<char, int> &pair : pairs)
    {
        for (int i = 0; i < pair.second; ++i)
        {
            ss << pair.first;
        }
    }

    return ss.str();
}

int main()
{
    cout << frequencySort("Aabb") << endl;
}