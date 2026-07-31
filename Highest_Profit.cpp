#include<iostream>
#include<vector>
using namespace std;
int profit(vector<int>& prices)
{
    if(prices.empty())
    {
        return 0;
    }
    int maxProfit = 0;
    int minPrice = prices[0];
    int l = prices.size();
    for(int i = 0;i < l;i++)
    {
        maxProfit = max(maxProfit, prices[i] - minPrice);
        if(minPrice > prices[i])
        {
            minPrice = prices[i];
        }
    }
    return maxProfit;
}
int main()
{
    vector<int> a = {3,4,2,6,3,6,8};
    cout<<"Highest Profit = "<<profit(a);
}