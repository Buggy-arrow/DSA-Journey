#include<iostream>
using namespace std;
int main()
{
    int n[10] = {4,54,3,5,32,3,2,4,6,8};
    int max = n[0];
    for(int num : n)
    {
        if(max < num)
        {
            max = num;
        }
    }
    cout<<"\nMaximum Number is : "<<max;
    return 0;
}