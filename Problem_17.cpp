#include<iostream>
using namespace std;

typedef struct ListNode
{
    int data;
    ListNode* next;    
}node;
node* reverse(node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    node* temp = reverse(head->next);
    (head->next)->next = head;
    head->next = NULL;
    return temp;
}
void ReorderList(node* head)
{
    /*int l = 0;
    node* a = head;
    node* x = head;
    node* y;
    while(a != NULL)
    {
        l++;
        y = a;
        a = a->next;
    }
    if(l < 3)
        return;
    
    y->next = x;
    node* firsti;
    node* lasti;
    while(x->next != y && x != y)
    {
        firsti = x;
        lasti = y;
        y = x;
        x = x->next;
        while(y->next != lasti)
        {
            y = y->next;
        }
        lasti->next = firsti->next;
        firsti->next = lasti;
    }
    y->next = NULL;*/

    node* slow = head;
    node* fast = head;
    node* first = head;
    while(fast->next != NULL && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node* second = reverse(slow->next);
    slow->next = NULL;
    while(first != NULL && second != NULL)
    {
        node* nextA = first->next;
        node* nextB = second->next;

        first->next = second;
        second->next = nextA;

        first = nextA;
        second = nextB; 
    }
}
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

    ReorderList(head);

    cout << "Reordered list:\n";
    printList(head);

    return 0;
}