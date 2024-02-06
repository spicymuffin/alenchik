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

typedef pair<char, int> char_int;
void print_queue(std::queue<char_int> q)
{
    while (!q.empty())
    {
        std::cout << q.front().first << ": " << q.front().second << " ";
        q.pop();
    }
    std::cout << std::endl;
}

void print_map(std::map<char, int> m)
{
    cout << "(map) ";
    for (auto it : m)
    {
        cout << it.first << ": " << it.second << " ";
    }
    cout << endl;
}

string minWindow(string s, string t)
{
    int tmap[256];
    int smap[256];

    int minlen = INT_MAX;
    int minleft = 0;

    for (auto it : t)
    {
        tmap[(int)it]++;
    }

    int right = 0;
    int left = 0;

    int required = tmap.size();
    int formed = 0;

    while (right < s.length())
    {
        smap[s[right]]++;

        if (tmap.find(s[right]) != tmap.end() && smap[s[right]] == tmap[s[right]])
        {
            formed++;
        }

        while (left <= right && formed == required)
        {
            int len = right - left + 1;

            if (len < minlen)
            {
                minleft = left;
                minlen = len;
            }

            smap[s[left]]--;
            if (tmap.find(s[left]) != tmap.end() && smap[s[left]] < tmap[s[left]])
            {
                formed--;
            }
            left += 1;
        }
        right += 1;
    }

    return minlen == INT_MAX ? "" : s.substr(minleft, minlen);
}

int main()
{
    cout << minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << minWindow("aa", "aa") << endl;
}
