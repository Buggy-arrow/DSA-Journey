#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;
int LongestSubstring(string str)
{
    if(str.empty())
    {
        return 0;
    }
    if(str.size() == 1)
    {
        return 1;
    }
    int l = str.length();
    int left = 0;
    int right = 0;
    unordered_set<char> window = {str.at(0)};
    int maxLength = 0;
    for(right = 1;right < l;right++)
    {   
        while(window.contains(str.at(right)))
        {
                window.erase(str.at(left));
                left++;
        }
        window.insert(str.at(right));
        maxLength = max(maxLength,int(window.size()));
    }
    return maxLength;
}
int main()
{
    string s = "babc";
    cout<<"Longest Substring without repeating character : "<<LongestSubstring(s)<<endl;
}