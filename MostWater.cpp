#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MostWater(vector<int>& arr)
{
    int maxWater = 0;
    int l = arr.size();
    int left = 0;
    int right = l-1;
    while(left < right)
    {
        int q = (right-left)*min(arr[left],arr[right]);
        maxWater = max(maxWater,q);
        if(arr[left] < arr[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return maxWater;
}
int main()
{
    vector<int> vec = {1,6,6,2,5,4,8,3,7};
    cout<<"Maximum water in this vec : "<<MostWater(vec)<<endl;
}