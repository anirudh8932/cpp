#include<iostream.h>
#include<conio.h>
#define MAX 5

class Queue {
    int arr[MAX];
    int front, rear;
public:
    Queue() {
	front = -1;
	rear = -1;
    }
    void enqueue(int item);
    int dequeue();
    void display();
};

void Queue::enqueue(int item) {
    if ((front == 0 && rear == MAX-1) || (rear == (front-1)%(MAX-1))) {
	cout << "Queue is Full";
	return;
    }
    else if (front == -1) {
	front = rear = 0;
	arr[rear] = item;
    }
    else if (rear == MAX-1 && front != 0) {
	rear = 0;
	arr[rear] = item;
    }
    else {
	rear++;
	arr[rear] = item;
    }
}
int INT_MIN=0;
int Queue::dequeue() {
    if (front == -1) {
	cout << "Queue is Empty";
	return INT_MIN;
    }
    int data = arr[front];
    arr[front] = -1;
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else if (front == MAX-1)
        front = 0;
    else
        front++;
    return data;
}

void Queue::display() {
    if (front == -1) {
        cout << "Queue is Empty";
        return;
    }
    cout << "Elements in Circular Queue are: ";
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            cout << arr[i];
    }
    else {
	for (int j = 0; j <= rear; j++)
	    cout << arr[j];
    }
}

void main() {
    clrscr();
    Queue q;
    q.enqueue(14);
    q.enqueue(22);
    q.enqueue(13);
    q.enqueue(-6);
    q.display();
    cout << "Deleted value = " << q.dequeue();
    cout << "Deleted value = " << q.dequeue();
    q.display();
    getch();
}
