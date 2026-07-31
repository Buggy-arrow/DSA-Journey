#include<iostream>
#include<cctype>
#include<string>
using namespace std;
int main()
{
    string text = "A man, a plan, a canal: Panama";
    for(char &c : text)
    {
        c = toupper(c);
    }

    int left = 0;
    int right = text.length() - 1;
    
    while(left < right)
    {
        while(!isalnum(text[left]))
        {
            left++;
        }
        while(!isalnum(text[right]))
        {
            right--;
        }
        if(text[left] != text[right])
        {
            cout<<"Non Palindrome.\n";
            return -1;
        }
        left++;
        right--;
    }
    cout<<"Palindrome.\n";
    return 0;
}