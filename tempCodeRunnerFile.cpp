#include<iostream>
#include<utility>
#include<iterator>
#include<vector>
#include<map>
std::pair<int,int> TwoSum(std::vector<int>& a,int key)
{
    std::map<int,int> seen;
    //std::pair<int,int> solution;
    int l = a.size();
    for(int i = 0;i < l;i++)
    {
        auto it = seen.find(key-a[i]);
        if(it != seen.end())
        {
            return {seen[key-a[i]],i};
        }
        else
        {
            seen[a[i]] = i;
        }
    }
    return {-1,-1};
} 

int main()
{
    std::vector<int> arr = {3,2,5,2,5,7,9};
    std::pair<int,int> p = TwoSum(arr,16);
    if(p.first == -1)
    {
        std::cout<<"Not found";
        return -1;
    }
    std::cout<<"1st index is = "<<p.first<<"\n2nd index is = "<<p.second;
    return 0;
}