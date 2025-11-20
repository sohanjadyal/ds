#include <stdio.h>
#include <ctype.h>

#define MAX 100
int stack[MAX];
int top = -1;

void push(int x) { stack[++top] = x; }
int pop() { return stack[top--]; }

int evaluate(char exp[]) {
    for (int i = 0; exp[i]; i++) {
        char c = exp[i];
        if (isdigit(c))
            push(c - '0');
        else {
            int b = pop();
            int a = pop();
            switch (c) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }
    return pop();
}

int main() {
    char exp[MAX];
    scanf("%s", exp);
    printf("%d\n", evaluate(exp));
    return 0;
}
