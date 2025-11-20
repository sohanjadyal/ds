#include <stdio.h>

#define MAX 100

typedef struct {
    int top;
    int start;
    int end;
} Stack;

int arr[MAX];
Stack s[10];
int n, total, part;

void initStacks() {
    for (int i = 0; i < n; i++) {
        s[i].start = i * part;
        s[i].end = s[i].start + part - 1;
        s[i].top = s[i].start - 1;
    }
}

int isFull(int i) {
    return s[i].top == s[i].end;
}

int isEmpty(int i) {
    return s[i].top < s[i].start;
}

void push(int i, int val) {
    if (isFull(i)) {
        printf("Stack %d Overflow!\n", i);
        return;
    }
    arr[++s[i].top] = val;
    printf("Pushed %d in Stack %d\n", val, i);
}

void pop(int i) {
    if (isEmpty(i)) {
        printf("Stack %d Underflow!\n", i);
        return;
    }
    printf("Popped %d from Stack %d\n", arr[s[i].top--], i);
}

void display(int i) {
    if (isEmpty(i)) {
        printf("Stack %d is Empty\n", i);
        return;
    }
    printf("Stack %d: ", i);
    for (int p = s[i].top; p >= s[i].start; p--)
        printf("%d ", arr[p]);
    printf("\n");
}

int main() {
    printf("Enter number of stacks: ");
    scanf("%d", &n);

    printf("Enter total array size: ");
    scanf("%d", &total);

    part = total / n;

    initStacks();

    int ch, sn, val;

    while (1) {
        printf("\n1.Push  2.Pop  3.Display  4.Exit\n");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter stack number (0 to %d): ", n - 1);
            scanf("%d", &sn);
            printf("Enter value: ");
            scanf("%d", &val);
            push(sn, val);
        }
        else if (ch == 2) {
            printf("Enter stack number: ");
            scanf("%d", &sn);
            pop(sn);
        }
        else if (ch == 3) {
            printf("Enter stack number: ");
            scanf("%d", &sn);
            display(sn);
        }
        else break;
    }

    return 0;
}
