#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next; // pointer to the next node
    Node *back; // pointer to the previous node

    // constructor fn.
public:
    Node(int data1, Node *back1, Node *next1)
    {
        data = data1;

        back = back1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *convertArrToDLL(vector<int> &arr)
{

    // algo :
    //     1. create a head node with first element , arr[0]
    //     2. initialize 'prev' to the head
    //     3. loop through end of the arr -> create a new node with data -> set 'back' to the 'prev' node
    //     4. update 'next' to 'prev->next'
    //     5. move 'prev' to new node for next iteration
    //     6. return head

    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], prev, nullptr);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void printDLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *deleteHead(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

Node *deleteKthElement(Node *head, int k)
{
    if (head == NULL)
        return NULL;
    int cnt = 0;
    Node *kNode = head;
    while (kNode)
    {
        cnt++;
        if (cnt == k)
            break;
        kNode = kNode->next;
    }
    Node *prev = kNode->back;
    Node *front = kNode->next;

    if (prev == NULL || front == NULL)
    { // single element
        return NULL;
    }
    else if (prev == NULL)
    { // head
        return deleteHead(head);
    }
    else if (front == NULL)
    { // tail
        return deleteTail(head);
    }

    prev->next = front;
    front->back = prev;
    kNode->back = nullptr;
    kNode->next = nullptr;
    delete kNode;
    return head;
}

void deleteNode(Node *temp)
{
    Node *prev = temp->back;
    Node *front = temp->next;

    if (front == NULL)
    {
        prev->next = nullptr;
        front->back = nullptr;
        delete temp;
        return;
    }

    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
}

int main()
{
    vector<int> arr = {5, 7, 9, 5};
    Node *head = convertArrToDLL(arr);

    printDLL(head);

    // head = deleteHead(head);
    //  head = deleteTail(head);
    // head = deleteKthElement(head,3);
    deleteNode(head->next->next);
    return 0;
}