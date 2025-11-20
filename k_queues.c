#include <stdio.h>

#define MAX 100

typedef struct {
    int front;
    int rear;
    int start;
    int end;
} Queue;

int arr[MAX];

Queue q[10];
int k, n, qsize;


void initQueues() {
    for (int i = 0; i < k; i++) {
        q[i].front = q[i].rear = -1;
        q[i].start = i * qsize;
        q[i].end   = q[i].start + qsize - 1;
    }
}

int isFull(int i) {
    return (q[i].rear == q[i].end);
}

int isEmpty(int i) {
    return (q[i].front == -1);
}

void enqueue(int i, int val) {
    if (isFull(i)) {
        printf("Queue %d is FULL!\n", i);
        return;
    }

    if (isEmpty(i)) {
        q[i].front = q[i].rear = q[i].start;
    } else {
        q[i].rear++;
    }

    arr[q[i].rear] = val;
    printf("Enqueued %d in Queue %d\n", val, i);
}

void dequeue(int i) {
    if (isEmpty(i)) {
        printf("Queue %d is EMPTY!\n", i);
        return;
    }

    printf("Dequeued %d from Queue %d\n", arr[q[i].front]);

    if (q[i].front == q[i].rear)
        q[i].front = q[i].rear = -1;
    else
        q[i].front++;
}

void display(int i) {
    if (isEmpty(i)) {
        printf("Queue %d is empty\n", i);
        return;
    }

    printf("Queue %d: ", i);
    for (int p = q[i].front; p <= q[i].rear; p++)
        printf("%d ", arr[p]);
    printf("\n");
}

int main() {
    printf("Enter number of queues (k): ");
    scanf("%d", &k);

    printf("Enter total array size (n): ");
    scanf("%d", &n);

    qsize = n / k;

    initQueues();

    int ch, qi, x;

    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter queue number (0 to %d) and value: ", k - 1);
            scanf("%d %d", &qi, &x);
            enqueue(qi, x);
        }
        else if (ch == 2) {
            printf("Enter queue number: ");
            scanf("%d", &qi);
            dequeue(qi);
        }
        else if (ch == 3) {
            printf("Enter queue number: ");
            scanf("%d", &qi);
            display(qi);
        }
        else break;
    }

    return 0;
}
