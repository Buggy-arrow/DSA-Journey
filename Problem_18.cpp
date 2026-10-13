#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};

node* GetIntersection(node* headA, node* headB)
{
    node* x = headA;
    node* y = headB;

    while(x != y)
    {
        x = (x == NULL) ? headB : x->next;
        y = (y == NULL) ? headA : y->next;
    }

    return x;
}

int main()
{
    // Shared portion: 8 -> 4 -> 5 -> NULL
    node* s1 = new node{8, nullptr};
    node* s2 = new node{4, nullptr};
    node* s3 = new node{5, nullptr};

    s1->next = s2;
    s2->next = s3;

    // List A: 4 -> 1 -> 8 -> 4 -> 5
    node* a1 = new node{4, nullptr};
    node* a2 = new node{1, s1};

    a1->next = a2;
    node* headA = a1;

    // List B: 5 -> 6 -> 1 -> 8 -> 4 -> 5
    node* b1 = new node{5, nullptr};
    node* b2 = new node{6, nullptr};
    node* b3 = new node{1, s1};

    b1->next = b2;
    b2->next = b3;
    node* headB = b1;

    node* result = GetIntersection(headA, headB);

    if (result != nullptr)
        cout << "Intersection value: " << result->data << '\n';
    else
        cout << "No intersection\n";

    return 0;
}