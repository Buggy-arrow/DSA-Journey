#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

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

node* RemoveDuplicates(node* head)
{
    if(head == NULL || head->next == NULL)
        return head;

    node* sol = head;
    node* temp;

    while(head != NULL)
    {
        while(head->next != NULL && head->data == head->next->data)
        {
            temp = head->next->next;
            delete head->next;
            head->next = temp;
        }
        head = head->next;
    }
    return sol;
}

int main()
{
    // 1 -> 1 -> 1 -> 2 -> 3 -> 3 -> NULL

    node* n1 = new node{1, nullptr};
    node* n2 = new node{1, nullptr};
    node* n3 = new node{1, nullptr};
    node* n4 = new node{2, nullptr};
    node* n5 = new node{3, nullptr};
    node* n6 = new node{3, nullptr};

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    node* head = n1;

    cout << "Original list:\n";
    printList(head);

    head = RemoveDuplicates(head);

    cout << "After removing duplicates:\n";
    printList(head);

    return 0;
}