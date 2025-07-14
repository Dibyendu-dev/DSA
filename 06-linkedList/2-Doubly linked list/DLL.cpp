#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next; //pointer to the next node
        Node* back; //pointer to the previous node

    // constructor fn.
    public:
        Node(int data1,  Node* back1, Node* next1){
            data = data1;
           
            back = back1;
            next = next1;
        }
        Node(int data1){
            data = data1;
            next = nullptr;
            back = nullptr;
        }
};

Node* convertArrToDLL(vector<int>arr){

    // algo :
    //     1. create a head node with first element , arr[0]
    //     2. initialize 'prev' to the head 
    //     3. loop through end of the arr -> create a new node with data -> set 'back' to the 'prev' node
    //     4. update 'next' to 'prev->next'
    //     5. move 'prev' to new node for next iteration
    //     6. return head

    Node* head = new Node(arr[0]);
    Node* prev = head;
        for (int i = 1; i < arr.size(); i++)
        {
           Node* temp = new Node(arr[i],prev,nullptr);
            prev->next = temp;
            prev=temp;
        }
      return head;  

}

void printDLL(Node* head){
    while (head!= nullptr)
    {
        cout<<head->data << " " ;
        head=head->next;
    }
    
}

int main (){
    vector<int> arr = {5,7,9,5,4,6,8,4,8};
    Node* head = convertArrToDLL(arr);
    printDLL(head);

    return 0 ;
}