#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "util.h"

void sift_up(int _index)
{
}

void heap_insert(vector<int> &_heap, int _value, int &_n)
{
    int insert = _n;
    _heap[_n] = _value;
    int parent = ((insert + (insert % 2)) / 2) - 1;
    while (parent >= 0 && _heap[parent] > _heap[insert])
    {
        swap(_heap[parent], _heap[insert]);
        insert = parent;
        parent = ((insert + (insert % 2)) / 2) - 1;
    }
    _n++;
}

int remove_min(vector<int> &_heap, int &_n)
{
    swap(_heap[0], _heap[_n - 1]);
    _n--;
    int i = 0;
    while (i * 2 + 1 < _n) // first child bc if it doesnt exist then tree is over.
    {
        int j = i * 2 + 1;
        if (i * 2 + 2 < _n and _heap[j] > _heap[i * 2 + 2])
        {
            j = i * 2 + 2;
        }
        if (_heap[j] >= _heap[i])
        {
            break;
        }
        swap(_heap[j], _heap[i]);
        i = j;
    }
    return _heap[_n];
}

void heap_sort(vector<int> &array)
{
    int array_length = static_cast<int>(array.size());
    int hl = 0;

    for (int k = 0; k < array_length; ++k)
    {
        int i = k;
        hl++;
        while (i > 0 && array[i] < array[(i + (i % 2)) / 2 - 1])
        {
            swap(array[i], array[(i + (i % 2)) / 2 - 1]);
            i = (i + (i % 2)) / 2 - 1;
        }
        cout << vector_2_string(array) << endl;
    }

    cout << "====" << endl;

    for (int k = 0; k < array_length; ++k)
    {
        swap(array[0], array[array_length - k - 1]);
        hl--;
        int i = 0;
        while (i * 2 + 1 < hl)
        {

            if (array[i * 2 + 1] < array[i * 2 + 2])
            {
                if (array[i * 2 + 1] >= array[i])
                {
                    break;
                }
                swap(array[i * 2 + 1], array[i]);
                i = i * 2 + 1;
            }
            else
            {
                if (array[i * 2 + 2] >= array[i])
                {
                    break;
                }
                swap(array[i * 2 + 2], array[i]);
                i = i * 2 + 2;
            }
        }
        cout << vector_2_string(array) << endl;
    }
}

int main()
{
    vector<int> arr = vector<int>();
    vector<int> heap = {3, 4, 5, 12, 13, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int heap_len = 6;

    randfill(arr, 10, 0, 20);

    cout << pow(2, 3) << endl;
    // cout << vector_2_string(heap) << endl;

    // heap_insert(heap, 1, heap_len);

    // cout << vector_2_string(heap) << endl;

    // heap_insert(heap, 2, heap_len);

    // cout << vector_2_string(heap) << endl;

    // cout << remove_min(heap, heap_len) << endl;

    // cout << vector_2_string(heap) << endl;

    cout << vector_2_string(arr) << endl;

    heap_sort(arr);

    cout << vector_2_string(arr) << endl;
}