#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> ThreeSum(vector<int>& arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> sol;
    int key;
    int l = arr.size();
    for(int i = 0;i < l-2;i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        int left = i + 1;
        int right = l - 1;
        key = (-1)*arr[i];
       while(left < right)
       {
            int t = arr[left] + arr[right];
            if(t == key)
            {
                vector<int> e = {arr[i],arr[left],arr[right]};
                sol.push_back(e);
                left++;
                right--;
            }
            else if(t < key)
            {
                left++;
            }
            else if(t > key)
            {
                right--;
            }
       }
    }
    return sol;
}
int main()
{
    vector<int> a = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> sol = ThreeSum(a);
    cout<<"Solution elements are:\n";
    for(vector<int> i : sol)
    {
        for(int e : i)
        {
            cout<<"\t"<<e;
        }
        cout<<endl;
    }
}