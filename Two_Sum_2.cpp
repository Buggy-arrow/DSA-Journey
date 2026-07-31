#include<iostream>
#include<utility>
#include<vector>
using namespace std;
pair<int,int> twoSum2(vector<int>& arr, int tar)
{
    int n = arr.size();
    int left = 0;
    int right = n-1;
    int t;
    while(left < right)
    {
        t = arr[left]+arr[right];
        if(t == tar)
        {
            return {left+1,right+1};
        }
        else if(t < tar)
        {
            left++;
        }
        else if(t > tar)
        {
            right--;
        }
    }
    return {-1,-1};
}
int main()
{
    vector<int> num = {2,3,5,6,9,12,18,19};
    int target;
    cout<<"A array is as given : \n";
    for(int i : num)
    {
        cout<<"\t"<<i;
    }
    cout<<"\nEnter your target of Two Sum 2 : ";
    cin>>target;
    pair<int,int> p = twoSum2(num,target);
    cout<<"Answer = ["<<p.first<<","<<p.second<<"]\n";
}