#include<iostream>
#include<vector>
using namespace std;
vector<int> ArrayProduct(vector<int>& arr)
{
    if(arr.empty())
        return {};
    int l = arr.size();
    if(l == 1)
        return{1};
    vector<int> sol(l);
    vector<int> prefix(l,1);
    vector<int> suffix(l,1);
    for(int i = 0;i < l;i++)
    {
        if(i == 0)
        {
            prefix[0] = arr[0];
            suffix[l-1] = arr[l-1];
        }
        else
        {
            prefix[i] = prefix[i-1]*arr[i];
            suffix[l-1-i] = suffix[l-i]*arr[l-1-i];
        }
    }
    for(int k = 0;k < l;k++)
    {
        if(k == 0)
        {
            sol[k] = suffix[k+1]; 
        }
        else if(k == l-1)
        {
            sol[k] = prefix[k-1];
        }
        else
        {
            sol[k] = suffix[k+1]*prefix[k-1];
        }
    }
    return sol;
}

int main()
{
    vector<int> nums = {1,2,3,4};
    cout<<"\nInput vector : \n";
    for(int i : nums)
    {
        cout<<"\t"<<i;
    }
    vector<int> ans = ArrayProduct(nums);
    cout<<"\nOutput vector : \n";
    for(int j : ans)
    {
        cout<<"\t"<<j;
    }
}