#include<iostream>
#include<vector>
using namespace std;
bool validParenthesis(string str)
{
    int l = str.length();
    if(l%2 == 1)
        return false;
    vector<char> stack;
    for(int i = 0;i < l;i++)
    {
        if(str.at(i) == '(' || str.at(i) == '{' || str.at(i) == '[')
        {
            stack.push_back(str.at(i));
        }
        else
        {
            if(stack.empty())
                return false;
            if((str[i] == ')' && stack.back() == '(') ||
               (str[i] == ']' && stack.back() == '[') ||
               (str[i] == '}' && stack.back() == '{'))
            {
                stack.pop_back();
            }
        }
    }
    if(stack.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string str = "([{}])";
    cout<<"Given string is valid : "<<validParenthesis(str)<<endl;
}