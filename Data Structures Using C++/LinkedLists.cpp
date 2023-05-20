#include <iostream>

class Node { // Node Template...
    public : 
        int info;
        Node* link;
    
    Node(int data) { // Parameterised constructor...
        info = data;
    }
};

// * FUNCTION DEFINITIONS....

void insertInBeginning(Node* &start, int data);
void insertAfter(Node* &start, int data, int key);
void insertBefore(Node* &start, int data, int key);
void insertAtEnd(Node* &start, int data);
void insertGivenPos(Node* &start, int data, int pos); // Assuming 1 based indexing...

void deleteANode(Node* &start, int key);
void deleteAtBeginning(Node* &start);
void deleteAtEnd(Node* &start);

void display(Node* start) {

    if(start == NULL) {
        std::cout << "No elements in list !" << std::endl;
    }
    Node* p = start;
    while(p != NULL) {
        std::cout << p-> info << " -> ";
        p = p-> link;
    }
    std::cout << "NULL "<< std::endl;
}

int main() {

    Node* start = NULL;
    insertInBeginning(start, 1);
    insertInBeginning(start, 0);
    insertAtEnd(start, 3);
    insertAtEnd(start, 5);
    insertBefore(start, 4, 5);
    insertAfter(start, 2, 1);
    insertGivenPos(start, 6, 7);
    // insertGivenPos(start, 1, 1);
    display(start);

    // deleteAtBeginning(start);
    // deleteAtEnd(start);
    deleteANode(start, 3);
    deleteANode(start, 1);


    display(start);

    return(0);
}
void insertInBeginning(Node* &start, int data) {

    Node* temp = new Node(data);
    temp-> link = start;
    start = temp;
}
void insertBefore(Node* &start, int data, int key) {

    if(start->info == key) {
        insertInBeginning(start, data);
        return;
    }

    Node* temp = new Node(data);
    Node* p = start;

    while(p-> link-> info != key) {
        p = p-> link;
    }
    temp-> link = p-> link;
    p-> link = temp;
}
void insertAfter(Node* &start, int data, int key) {

    if(start-> info == key) {
        insertInBeginning(start, data);
        return;
    }
    Node* temp = new Node(data);
    Node*p = start;
    while(p-> info != key) {
        p = p-> link;
    }
    temp->link = p->link;
    p->link = temp;
}
void insertGivenPos(Node* &start, int data, int pos) {

    if(pos == 0) { std::cout << std::endl << "Not '0' based indexing !" << std::endl; display(start); }
    if(pos == 1) {
        insertInBeginning(start, data);
        return;
    }
    int count = 1;
    Node* temp = new Node(data);
    Node* p = start;
    while(count+1 != pos) {
        p = p-> link;
        count++;
    }
    temp-> link = p-> link;
    p-> link = temp;
}
void insertAtEnd(Node* &start, int data) {

    Node* temp = new Node(data);
    if(start == NULL) { // No nodes present...
        start = temp;
        temp-> link = NULL;
        return;
    }
    Node* p = start;
    while(p-> link != NULL) {
        p = p-> link;
    }
    p-> link = temp;
    temp-> link = NULL;
}
void deleteAtBeginning(Node* &start) {

    Node* temp = start;
    start = start-> link;
    delete temp;
}
void deleteAtEnd(Node* &start) {

    Node* temp = start;
    Node* p = start-> link;

    while(p-> link != NULL) {
        temp = temp-> link;
        p = p-> link;
    }
    temp-> link = NULL;
    delete p;
}
void deleteANode(Node* &start, int key) {

    if(start-> info == key) {
        deleteAtBeginning(start);
    }
    Node* temp = start;
    while(temp-> link-> info != key) {
        temp = temp-> link;
    }
    Node* p = temp-> link; 
    temp-> link = p-> link;
    delete p;
}