#include<iostream>
#include<string>
using namespace std;
void reverse(int a[],int size)
{
    int t;
    for(int j = 0 ; j <= size/2;j++)
    {
        t = a[size-1-j];
        a[size-1-j] = a[j];
        a[j] = t;
    }
    return;
}
int main()
{
    int n;
    cout<<"Enter number of elements in your array = ";
    cin>>n;
    int num[n];
    for(int i = 0;i < n;i++)
    {
        cout<<"Enter element "<<i+1<<" = ";
        cin>>num[i];
    }
    cout<<"\nYour array = ";
    for(int e : num)
    {
        cout<<"\t"<<e;
    }
    reverse(num,n);
    cout<<"\nYour array after reverse = ";
    for(int x : num)
    {
        cout<<"\t"<<x;
    }
    return 0;
}