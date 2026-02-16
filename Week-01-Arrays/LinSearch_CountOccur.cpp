#include<iostream>
using namespace std;
void Search(int a[],int s,int key)
{
    for(int i = 0;i < s;i++)
    {
        if(a[i] == key)
        {
            cout<<"\nYour element is present at index : "<<i;
        }
    }
    return;
}
int countOccurence(int a[],int s, int key)
{
    int count = 0;
    for(int i = 0;i < s;i++)
    {
        if(a[i] == key)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int n[10] = {4,54,3,5,32,3,2,4,6,8};
    int key;
    cout<<"Enter a integer to be find and count its occurences : ";
    cin>>key;
    Search(n,10,key);
    cout<<"\nNumber of times "<<key<<" occurs : "<<countOccurence(n,10,key);
    return 0;
}