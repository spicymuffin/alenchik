#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
const string vector_2_string(const vector<T> &_vector)
{
    string returnString = "";
    for (int i = 0; i < static_cast<int>(_vector.size()); ++i)
    {
        returnString += to_string(_vector[i]) + " ";
    }
    return returnString;
}

void randfill(vector<int> &_vector, int _size, int _min = -100, int _max = 100)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < _size; ++i)
    {
        _vector.push_back(rand() % (_max + 1 - _min) + _min);
    }
}

int randrange(int _min = -100, int _max = 100)
{
    srand((unsigned int)time(NULL));
    return rand() % (_max + 1 - _min) + _min;
}