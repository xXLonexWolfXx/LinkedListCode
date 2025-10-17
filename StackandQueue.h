#include "LinkedList.cpp"

class Stack {
    public:
        Stack();
        void Push(string item);
        void Push(KeyValue item);
        KeyValue Pop();
        bool IsEmpty();
        string ToList();
    private:
        LinkedList* head;
};

class Queue {
    public:
        Queue();
        void Enqueue(string item);
        void Enqueue(KeyValue item);
        KeyValue Dequeue();
        bool IsEmpty();
        string ToList();
    private:
        LinkedList* head;
};
