#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <random>
#include <cstdlib>
#include <ctime>
#include <map>
#include <sstream>

using namespace std;

#include "util.h"

string getSignature(const string &inp)
{
    vector<int> map(26, 0);
    for (char c : inp)
    {
        map[(int)c - (int)'a']++;
    }

    stringstream ss;
    for (int i = 0; i < 26; i++)
    {
        if (map[i] != 0)
        {
            ss << (char)(i + (int)'a') << map[i];
        }
    }

    return ss.str();
}

vector<vector<string>> groupAnagrams(const vector<string> &strs)
{
    map<string, vector<string>> map;

    for (int i = 0; i < strs.size(); i++)
    {
        map[getSignature(strs[i])].push_back(strs[i]);
    }

    vector<vector<string>> result;

    for (auto it : map)
    {
        result.push_back(it.second);
    }

    return result;
}

vector<string> inp = {"eat", "tea", "tan", "ate", "nat", "bat"};

int main()
{
    vector<vector<string>> gay = groupAnagrams(inp);
    for (auto it_1 : gay)
    {
        cout << "[";
        for (auto it_2 : it_1)
        {
            cout << it_2 << " ";
        }
        cout << "]";
    }
}