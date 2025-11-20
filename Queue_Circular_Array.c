#include <stdio.h>

#define MAX 20
int queue[MAX];
int front = -1, rear = -1;

int isEmpty() { return front == -1; }
int isFull() { return (rear + 1) % MAX == front; }

void enqueue(int x) {
    if (isFull()) return;
    if (isEmpty()) front = rear = 0;
    else rear = (rear + 1) % MAX;
    queue[rear] = x;
}

void dequeue() {
    if (isEmpty()) return;
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
}

int Front() { return isEmpty() ? -1 : queue[front]; }
int Rear() { return isEmpty() ? -1 : queue[rear]; }

int main() {
    int ch, x;
    while (1) {
        scanf("%d", &ch);
        if (ch == 1) { scanf("%d", &x); enqueue(x); }
        else if (ch == 2) dequeue();
        else if (ch == 3) printf("%d\n", isEmpty());
        else if (ch == 4) printf("%d\n", isFull());
        else if (ch == 5) printf("%d\n", Front());
        else if (ch == 6) printf("%d\n", Rear());
        else break;
    }
    return 0;
}