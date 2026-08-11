#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

int LongestRepeatingCharReplace(string str, int k)
{
    if(str.size() <= 1)
    {
        return str.size();
    }
    int l = str.length();
    int left = 0;
    int right = 0;
    int maxLength = 0;
    int window , maxIt;
    unordered_map<char,int> count;
    count[str.at(right)] = 1;
    for(right = 1;right < l;right++)
    {   
        window = 1 + right - left;
        auto maxIt = count.begin();
        if(count.contains(str.at(right)))
        {
            count[str.at(right)]++;             //Making of count table using unordered_map 
        }
        else
        {
            count[str.at(right)] = 1;
        }
        for (auto it = count.begin();it != count.end(); ++it) {
            if (it->second > maxIt->second) {
                maxIt = it;                                     //Finding maximum in count map
            }
        }
        while(window - maxIt->second > k)
        {
            count[str.at(left)]--;
            left++;
            window = 1 + right - left;
        }
        maxLength = max(maxLength, window);
    }
    return maxLength;
}
int main()
{
    string str = "ABAB";
    cout<<"Longest substring wit atleast k replacement for given string : "<<LongestRepeatingCharReplace(str,2)<<endl;
}