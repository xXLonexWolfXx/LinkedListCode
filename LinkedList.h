#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

class KeyValue {
    public:
        KeyValue(string k, string v): key(k), value(v) {};
        string key;
        string value;
};

class Node{
    public:
        Node(string input, Node* another = nullptr);
        Node(string k, string v, Node* another = nullptr): key(k), value(v), next(another) {};
        //Constructor builds a node with the string as it's input, and pointing to no new node
        //  by default, but enables linking together construction of multiple nodes
        string key;
        string value;
        Node* next;
};

class LinkedList{
    public:
        //Constructor builds a linked list with head and tail both being null
        LinkedList(): head(nullptr), tail(nullptr){}
        string About();
        void AddHead(string value);
        void AddTail(string value);
        bool isEmpty();
        void AddHead(KeyValue item);
        void AddTail(KeyValue item);
        KeyValue RemoveHead();
        string ToList();
    private:
        Node* head;
        Node* tail;
};
