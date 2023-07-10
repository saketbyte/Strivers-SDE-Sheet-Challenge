#include <bits/stdc++.h>
void sort012(int *arr, int n)
{

    //         Dutch National Flag algorithm

    int low = 0, last = n - 1, pointer = 0;

    while (pointer <= last)
    {

        switch (arr[pointer])
        {
        case 0:
            swap(arr[low], arr[pointer]);
            low++;
            pointer++;
            break;
        case 1:
            pointer++;
            break;

        case 2:
            swap(arr[pointer], arr[last]);
            last--;
            break;
        }
    }

    //   Write your code here
}