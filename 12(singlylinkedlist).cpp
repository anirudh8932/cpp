#include<iostream.h>
#include<conio.h>

class Node {
public:
    int data;
    Node* next;
};

void insertAtTheBegin(Node** start_ref, int data);
void display(Node* start);

void main() {
    clrscr();
    Node* start = NULL;

    insertAtTheBegin(&start, 7);
    insertAtTheBegin(&start, 6);
    insertAtTheBegin(&start, 3);
    insertAtTheBegin(&start, 2);
    insertAtTheBegin(&start, 1);

    cout << "Linked list is: ";
    display(start);

    getch();
}

void insertAtTheBegin(Node** start_ref, int data) {
    Node* ptr1 = new Node();
    ptr1->data = data;
    ptr1->next = *start_ref;
    *start_ref = ptr1;
}

void display(Node* start) {
    while (start != NULL) {
        cout<< start->data << " ";
        start = start->next;
    }
}
