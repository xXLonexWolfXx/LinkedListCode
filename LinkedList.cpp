#include "LinkedList.h"

string LinkedList::About(){
    return "This code was created and \"maintained\" by Jacob McFatter\nUniversity : CSUS (Sac State)\nFall Semester of 2025 : Csc130\n";
}

void LinkedList::AddHead(string value) {
//    reassigns head to a new node with the value-string, and pointing to the original head
    this->head = new Node(value, this->head);
    if(tail == nullptr) {
        // in the instance of the first item of the list, we can set the tail equal to the head node
        tail = head;
    }
}

void LinkedList::AddTail(string value){
    if(head == nullptr){
        //Pulled code from AddHead function, as when head and/or tail are null pointers <=> list is empty
        this->head = new Node(value, this->head);
        tail = head;
        return;
    }
    //we know that there is a head-value so we the tail can not be a null pointer as well
    this->tail->next = new Node(value);
    this->tail = this->tail->next;
}

bool LinkedList::isEmpty(){
    //if head is nullpointer, we know that the linked-list is empty, as both AddHead and Add
    //Tail functions (which goes back to AddHead) re-assigns the head (and tail) to a pointer
    return (head == nullptr);
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
    retString += to_string(t) + ". " + traversal->value + "\n";
    while (traversal = traversal->next){
        //while loop terminating on a nullptr
        ++t;
        retString += to_string(t) + ". " + traversal->value + "\n";
    }
    //end of loop, thus retString should contain all instances of the LinkedList
    return retString;
}

