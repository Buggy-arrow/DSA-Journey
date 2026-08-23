#include<iostream>
using namespace std;
typedef struct ListNode
{
    int data;
    ListNode* next;    
}node;

node* ReverseList(node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    node* temp = ReverseList(head->next);
    (head->next)->next = head;
    head->next = NULL;
    return temp;
}
void printList(ListNode* head)
{
    ListNode* current = head;

    while (current != nullptr)
    {
        std::cout << current->data << " -> ";
        current = current->next;
    }

    std::cout << "NULL\n";
}
int main()
{
    ListNode* n1 = new ListNode{1, nullptr};
    ListNode* n2 = new ListNode{2, nullptr};
    ListNode* n3 = new ListNode{3, nullptr};
    ListNode* n4 = new ListNode{4, nullptr};

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    ListNode* head = n1;

    printList(head);

    node* newNode = ReverseList(head);

    cout<<"\nAfter using reverse function : \n";
    printList(newNode);
}