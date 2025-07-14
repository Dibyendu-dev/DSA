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

int main()
{
    vector<int> arr = {2, 5, 8};

    Node *y = new Node(arr[0], nullptr);
    cout << y->data << "\n";
    cout << y;

    return 0;
}