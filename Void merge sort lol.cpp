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

void mergeSort(int arr[], int l, int r)
{
    if (r - l == 0)
    {
        return;
    }
    else if (r - l == 1)
    {
        if (arr[r] < arr[l])
        {
            int tmp = arr[r];
            arr[r] = arr[l];
            arr[l] = tmp;
            return;
        }
    }
    else
    {
        mergeSort(arr, l, l + ((r - l) / 2) - 1);
        mergeSort(arr, l + ((r - l) / 2), r);

        int arr_1_l = l;
        int arr_1_l_c = arr_1_l;
        int arr_1_len = (l + ((r - l) / 2) - 1) - l + 1;
        int arr_2_l = l + ((r - l) / 2);
        int arr_2_l_c = arr_2_l;
        int arr_2_len = r - (l + ((r - l) / 2)) + 1;

        int len = arr_1_len + arr_2_len;
        int *merger = new int[len];

        int k = 0;
        for (int i = 0; i < len; i++)
        {
            if (arr_2_l == arr_2_l_c + arr_2_len || (arr_1_l < arr_1_l_c + arr_1_len && arr[arr_1_l] < arr[arr_2_l]))
            {
                merger[k++] = arr[arr_1_l++];
            }
            else
            {
                merger[k++] = arr[arr_2_l++];
            }
        }

        k = 0;
        for (int i = l; i <= r; i++)
        {
            arr[i] = merger[k++];
        }

        delete[] merger;
    }
}
int main()
{
    int arr[] = {10, 4, 7, 1, 8, 9, 2, 3, 4, 1, 2};
    mergeSort(arr, 0, 10);
    cout << luigiutil::array_t_string(arr, 11);
}