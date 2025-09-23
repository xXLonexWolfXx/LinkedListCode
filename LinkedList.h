#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

class Node{
    public:
        Node(string input, Node* another = nullptr) : value(input), next(another){}
        //Constructor builds a node with the string as it's input, and pointing to no new node
        //  by default, but enables linking together construction of multiple nodes
        Node* next;
        string value;
};

class LinkedList{
    public:
        //Constructor builds a linked list with head and tail both being null
        LinkedList(): head(nullptr), tail(nullptr){}
        string About();
        void AddHead(string value);
        void AddTail(string value);
        bool isEmpty();
        string ToList();
    private:
        Node* head;
        Node* tail;
};
