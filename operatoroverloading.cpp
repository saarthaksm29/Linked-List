#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};
void insertatHead(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    node *n = new node(d);
    n->next = head;
    head = n;
}

int length(node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "-> ";
        head = head->next;
    }
}

void insertatTail(node *head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }
    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = new node(data);
    return;
}

void insertatmiddle(node *&head, int d, int p)
{
    if (head == NULL or p == 0)
    {
        insertatHead(head, d);
    }
    else if (p > length(head))
    {
        insertatTail(head, d);
    }

    else
    {
        int jump = 1;
        node *temp = head;
        while (jump <= p - 1)
        {
            temp = temp->next;
            jump++;
        }
        node *n = new node(d);
        n->next = temp->next;
        temp->next = n;
    }
}

void deletehead(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head->next;
    delete head;
    head = temp;
}

void deletetail(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        delete head;
        return;
    }
    else
    {

        node *temp = head;
        node *temp2 = head;
        while (temp->next != NULL)
        {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
        delete temp;
        return;
    }
}

bool search(node *head, int key)
{
    node *temp = head;
    while (head != NULL)
    {
        if (head->data == key)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}

bool searchrecursive(node *head, int key)
{
    if (head == NULL)
    {
        return false;
    }
    if (head->data == key)
    {
        return true;
    }
    else
    {
        return searchrecursive(head->next, key);
    }
}

node *takeinput()
{
    int d;
    cin >> d;
    node *head = NULL;
    while (d != -1)
    {
        insertatHead(head, d);
        cin >> d;
    }
    return head;
}

// void operator<<(ostream &os,node*head){
//     print(head);
//     return;
// }
ostream &operator<<(ostream &os, node *head)
{
    print(head);
    return os;
}

istream &operator>>(istream &is, node *&head)
{
    head = takeinput();
    return is;
}

void reversell(node *&head)
{
    node *c = head;
    node *p = NULL;
    node *n;

    while (c != NULL)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    head = p;
}

node *recreversal(node *&head)
{
    if (head->next == NULL or head == NULL)
    {
        return head;
    }
    node *shead = recreversal(head->next);
    node *temp = shead;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    head->next = NULL;
    temp->next = head;
    return shead;
}

node *midpoint(node *head)
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    node *slow = head;
    node *fast = head->next;

    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node *kthfromend(node *head, int k)
{
    node *fast = head;
    node *slow = head;
    int temp = k;
    while (temp > 0)
    {
        fast = fast->next;
        temp--;
    }
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

node *merge(node *a, node *b)
{
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }
    node *c;
    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

node *mergesort(node *head) 
{
    if (head == NULL or head->next == NULL)
    {
        return head;
    }
    node *mid = midpoint(head);
    node *a = head;
    node *b = mid->next;

    mid->next = NULL;
    a = mergesort(a);
    b = mergesort(b);

    node *c = merge(a, b);
    return c;
}

bool detectcycle(node*head){
    node *slow=head;
    node*fast=head;
    while(fast!=NULL and fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

int main()
{
    node *head = NULL;
    node *head2 = NULL;

    // head=takeinput();
    // head2=takeinput();
    cin >> head >> head2;
    cout << head << head2 << endl;

    node *newhead = merge(head, head2);
    cout << newhead << endl;

    // node *kth = kthfromend(head, 2);
    // cout << kth->data << endl;

    // node *mid = midpoint(head);
    // cout << mid->data << endl;
    // head = recreversal(head);
    // cout << head;
}