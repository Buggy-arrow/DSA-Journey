#include<iostream>
using namespace std;

typedef struct ListNode
{
    int data;
    ListNode* next;    
}node;

node* Merge(node* a, node* b)
{
    node* head = NULL;
    node** temp = &head; 
    while(a != NULL || b != NULL)
    {
        node* n;
        if(a == NULL)
        {
            n = new node{b->data,nullptr};
            b = b->next;
        }
        else if(b == NULL)
        {
            n = new node{a->data,nullptr};
            a = a->next;
        }
        else if(a->data >= b->data)
        {
            n = new node{b->data,nullptr};
            b = b->next;
        }
        else
        {
            n = new node{a->data,nullptr};
            a = a->next;
        }
        if((*temp) == NULL)
        {
            (*temp) = n;
        }
        else
        {
            (*temp)->next = n;
        }
        temp = &((*temp)->next);
    }
    return head;
}

int main()
{
    ListNode* a1 = new ListNode{1, nullptr};
    ListNode* a2 = new ListNode{3, nullptr};
    ListNode* a3 = new ListNode{5, nullptr};
    ListNode* a4 = new ListNode{7, nullptr};

    a1->next = a2;
    a2->next = a3;
    a3->next = a4;

    ListNode* head1 = a1;


    ListNode* b1 = new ListNode{2, nullptr};
    ListNode* b2 = new ListNode{4, nullptr};
    ListNode* b3 = new ListNode{6, nullptr};
    ListNode* b4 = new ListNode{8, nullptr};

    b1->next = b2;
    b2->next = b3;
    b3->next = b4;

    ListNode* head2 = b1;

    node* merged = Merge(head1,head2);

    node* temp = merged;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}