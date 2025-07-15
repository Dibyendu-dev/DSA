#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next; // pointer to the next node

    // constructor fn.
public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next; // or, mover = temp
    }
    return head;
}

void printLL(Node *head)
{
    // traversal
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int lengthOfLL(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {

        temp = temp->next;
        cnt++;
    }
    return cnt;
}

bool checkIfPresent(Node *head, int val)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == val)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

Node* deleteHead(Node* head)
{
    if(head == NULL) return head;
    Node *temp = head;
    head = head->next;
    free(temp);  // delete temp
    return head;
}

Node* deleteTail(Node* head){
    if ( head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while ( temp->next->next != NULL){
        temp= temp->next;
    }
    free (temp->next);
    temp->next = nullptr ;
    return head;
}

Node* deletekth(Node* head , int k){
    if(head==NULL) return NULL;
    if(k==1){
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
    }
    int cnt =0 ;
    Node* prev =NULL ;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp= temp->next;
    }
    return head;
}

Node* deleteElments(Node* head , int val){
    if(head==NULL) return NULL;
    if(head->data == val){
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
    }
    
    Node* prev =NULL ;
    Node* temp = head;
    while(temp != NULL){
        
        if(temp->data == val){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp= temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {2, 5, 8 ,9};

    Node *head = convertArr2LL(arr);
    
    
    printLL(head);
    // cout << lengthOfLL(head);
    // cout << checkIfPresent(head, 56);
    // head = deleteHead(head);
    // cout<< "head is :" <<head;
    // head = deleteTail(head);
    // head = deletekth(head ,10);
    // head = deleteElments(head,5);

    return 0;
}