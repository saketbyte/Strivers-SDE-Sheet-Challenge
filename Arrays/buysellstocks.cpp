#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices)
{
    // Write your code here.

    int minimumPrice = prices[0];
    int maximumProfit = 0;

    for (auto i : prices)
    {
        minimumPrice = i < minimumPrice ? i : minimumPrice;
        maximumProfit = maximumProfit < (i - minimumPrice) ? (i - minimumPrice) : maximumProfit;
    }

    return maximumProfit;
}