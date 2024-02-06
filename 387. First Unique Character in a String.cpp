#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <random>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;

#include "util.h"

int firstUniqChar(string s)
{
    vector<pair<int, int>> smap(26, pair<int, int>(0, -1));

    for (int i = 0; i < s.length(); i++)
    {
        if (smap[(int)s[i] - (int)'a'].first == 0)
        {
            smap[(int)s[i] - (int)'a'].second = i;
        }
        smap[(int)s[i] - (int)'a'].first++;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (smap[(int)s[i] - (int)'a'].first == 1)
        {
            return smap[(int)s[i] - (int)'a'].second;
        }
    }

    return -1;
}

int main()
{
    cout << firstUniqChar("leetcode") << endl;
}