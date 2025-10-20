#include "StackandQueue.h"

Stack::Stack() {
    this->head = new LinkedList();
}

void Stack::Push(string item) {
    this->head->AddHead(item);
}

void Stack::Push(KeyValue item) {
    this->head->AddHead(item);
}

KeyValue Stack::Pop() {
    return this->head->RemoveHead();
}

bool Stack::IsEmpty() {
    return this->head->isEmpty();
}

string Stack::ToList() {
    return this->head->ToList();
}


Queue::Queue() {
    this->head = new LinkedList();
}

void Queue::Enqueue(string item) {
    this->head->AddTail(item);
}

void Queue::Enqueue(KeyValue item) {
    this->head->AddTail(item);
}

KeyValue Queue::Dequeue() {
    return this->head->RemoveHead();
}

bool Queue::IsEmpty() {
    return this->head->isEmpty();
}

string Queue::ToList() {
    return this->head->ToList();
}
