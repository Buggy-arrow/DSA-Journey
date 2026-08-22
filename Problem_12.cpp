#include<iostream>
#include<vector>
using namespace std;
class Stack
{
    private : vector<int>stck,minStck;
    public :
        void Push(int n)
        {
            stck.push_back(n);
            if(stck.size() == 1 || n <= minStck.back())
                minStck.push_back(n);
            return;
        }
        int getMin()
        {
            if(minStck.size() == 0)
            {
                cout<<"Empty stack.\n";
                return -1;
            }
            return minStck.back();
        }
        int Pop()
        {
            if(stck.size() == 0)
            {
                cout<<"Underflow, Empty stack.\n";
                return -1;
            }
            int x = stck.back();
            stck.pop_back();
            if(minStck.back() == x)
            {
                minStck.pop_back();
            }
            return x;
        }
        int Top()
        {
            if(stck.size() == 0)
            {
                cout<<"Empty stack.\n";
                return -1;
            }
            return stck.back();
        }
};
int main()
{
    int op = 0;
    Stack st;
    while(op != 5)
    {
        cout<<"==== Stack Menu ====\n";
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Get Minimum\n";
        cout<<"4. Top\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice : ";
        cin>>op;
        switch(op)
        {
            case 1:{
                int x;
                cout<<"Enter number to push : ";
                cin>>x;
                st.Push(x);
                break;
            }
            case 2:{
                cout<<"Value poped : "<<st.Pop()<<endl;
                break;
            }
            case 3:
                cout<<"Minimum number : "<<st.getMin()<<endl;
                break;
            case 4:
                cout<<"Top : "<<st.Top()<<endl;
                break;
            case 5:
                cout<<"Exiting\n";
                break;
            default:
                cout<<"Invalid operation.\n"<<endl;
                break;
        }
    }
}