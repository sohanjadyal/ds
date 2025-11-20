#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
int stack[MAX];
int top = -1;

void push(int x) { stack[++top] = x; }
int pop() { return stack[top--]; }

int evaluate(char exp[]) {
    int n = strlen(exp);
    for (int i = n - 1; i >= 0; i--) {
        char c = exp[i];
        if (isdigit(c))
            push(c - '0');
        else {
            int a = pop();
            int b = pop();
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
