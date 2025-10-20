#include "LinkedList.h"
Node::Node(string input, Node* another) {
    int parser = input.find(":");
    this->key = input.substr(0, parser);
    this->value = input.substr(parser + 2);
    this->next = another;
}

string LinkedList::About(){
    return "This Code was created and \"maintained\" by Jacob McFatter\nUniversity : CSUS (Sac State)\nFall Semester of 2025 : Csc130\n";
}

void LinkedList::AddHead(string value) {
//    reassigns head to a new node with the value-string, and pointing to the original head
    int parser = value.find(":");
    this->head = new Node(value.substr(0, parser), value.substr(parser + 2), this->head);
    if(this->tail == nullptr) {
        // in the instance of the first item of the list, we can set the tail equal to the head node
        this->tail = this->head;
    }
}

void LinkedList::AddTail(string value){
    int parser = value.find(":");
    if(this->head == nullptr){
        //Pulled code from AddHead function, as when head and/or tail are null pointers <=> list is empty
        this->head = new Node(value.substr(0, parser), value.substr(parser + 2), this->head);
        this->tail = this->head;
        return;
    }
    //we know that there is a head-value so we the tail can not be a null pointer as well
    this->tail->next = new Node(value.substr(0, parser), value.substr(parser + 2));
    this->tail = this->tail->next;
}

bool LinkedList::isEmpty(){
    //if head is nullpointer, we know that the linked-list is empty, as both AddHead and Add
    //Tail functions (which goes back to AddHead) re-assigns the head (and tail) to a pointer
    return (this->head == nullptr);
}

void LinkedList::AddHead(KeyValue item) {
    this->head = new Node(item.key, item.value, this->head);
}

void LinkedList::AddTail(KeyValue item) {
    if (this->head == nullptr) {
        this->head = new Node(item.key, item.value);
        this->tail = this->head;
        return;
    }
    this->tail->next = new Node(item.key, item.value);
    this->tail = this->tail->next;
}

KeyValue LinkedList::RemoveHead() {
    if(this->isEmpty()){
        return KeyValue("","");
    }
    Node* holder = this->head->next;
    KeyValue retVal = KeyValue(this->head->key, this->head->value);
    delete this->head;
    this->head = holder;
    if (this->head == nullptr) {
        this->tail = nullptr;
    }
    return retVal;
}

string LinkedList::ToList() {
    string retString = "";
    if (this->isEmpty()) {
        //edge case of no items in the list
        return retString;
    }
    //otherwise at least 1 item is in list, run outer program
    int t = 1;
    Node* traversal = head;
    retString += to_string(t) + ". " + traversal->key + ": " + traversal->value + "\n";
    while (traversal = traversal->next){
        //while loop terminating on a nullptr
        ++t;
        retString += to_string(t) + ". " + traversal->key + ": " + traversal->value + "\n";
    }
    //end of loop, thus retString should contain all instances of the LinkedList
    retString += this->About();
    return retString;
}