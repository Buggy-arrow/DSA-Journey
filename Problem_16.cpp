#include<iostream>
using namespace std;

typedef struct ListNode
{
    int data;
    ListNode* next;    
}node;

void printList(node* head)
{
    node* current = head;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL\n";
}

node* DelNth(node* head,int n)
{
    node* t;
    node* a = head;
    node* b = head;
    int i = 0;
    while(b != NULL)
    {
        i++;
        b = b->next;
    }
    if(n <= 0 || n > i)
        return head;
    for(int j = 0; j < i-n;j++)
    {
        if(a == NULL)
        {
            return NULL;
        }
        t = a;
        a = a->next;
    }
    if(a == head)
    {
        a = a->next;
        delete head;
        return a;
    }
    else
    {
        t->next = a->next;
        delete a;
        return head;
    }
}
int main()
{
    node* n1 = new node{1, nullptr};
    node* n2 = new node{2, nullptr};
    node* n3 = new node{3, nullptr};
    node* n4 = new node{4, nullptr};
    node* n5 = new node{5, nullptr};

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    node* head = n1;

    cout << "Original list:\n";
    printList(head);

    int n = 2;

    head = DelNth(head, n);

    cout << "After deleting " << n << "nd node from end:\n";
    printList(head);

    return 0;
}