#include<iostream>
using namespace std;
void reverse(int a[],int s)
{
    for(int i = 0;i < s/2;i++)
    {
        a[i] = a[i] + a[s-i-1];
        a[s-i-1] = a[i] - a[s-i-1];
        a[i] = a[i] - a[s-i-1];
    }
}
int main()
{
    int n[10] = {4,54,3,5,32,3,2,4,6,8};
    int max = n[0], min = n[0];
    for(int num : n)
    {
        if(max < num)
        {
            max = num;
        }
        if(min > num)
        {
            min = num;
        }
    }
    cout<<"\nMaximum Number is : "<<max;
    cout<<"\nMinimum Number is : "<<min;
    cout<<"\nOriginal array : ";
    for(int i : n)
    {
        cout<<"\t"<<i;
    }
    reverse(n,10);
    cout<<"\nReversed array : ";
    for(int i : n)
    {
        cout<<"\t"<<i;
    }
    return 0;
}