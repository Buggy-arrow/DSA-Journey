#include<iostream>
using namespace std;
typedef struct ListNode
{
    int data;
    ListNode* next;    
}node;

bool isCycle(node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return false;
    }
    node* slow = head;
    node* fast = head->next;
    while(slow != fast)
    {
        if(slow == NULL || fast == NULL || fast->next == NULL || (fast->next)->next == NULL)
        {
            return false;
        }
        slow = slow->next;
        fast = (fast->next)->next;
    }
    return true;
}
int main()
{
    ListNode* n1 = new ListNode{1, nullptr};
    ListNode* n2 = new ListNode{2, nullptr};
    ListNode* n3 = new ListNode{3, nullptr};
    ListNode* n4 = new ListNode{4, nullptr};
    ListNode* n5 = new ListNode{5, nullptr};

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    n5->next = n3;

    ListNode* head = n1;

    if(isCycle(head))
    {
        cout<<"There is cycle.\n";
    }
    else
    {
        cout<<"No cycle.\n";
    }
}