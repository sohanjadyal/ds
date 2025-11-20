#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff, exp;
    struct Node *next;
} Node;

Node* insertTerm(Node *h, int c, int e) {
    if (c == 0) return h;
    Node *n = malloc(sizeof(Node));
    n->coeff = c;
    n->exp = e;
    n->next = NULL;

    if (!h || e > h->exp) {
        n->next = h;
        return n;
    }

    Node *t = h, *prev = NULL;

    while (t && t->exp > e) {
        prev = t;
        t = t->next;
    }

    if (t && t->exp == e) {
        t->coeff += c;
        free(n);
        return h;
    }

    n->next = t;
    prev->next = n;
    return h;
}

Node* multiply(Node *p1, Node *p2) {
    Node *r = NULL;
    for (; p1; p1 = p1->next)
        for (Node *q = p2; q; q = q->next)
            r = insertTerm(r, p1->coeff * q->coeff, p1->exp + q->exp);
    return r;
}

void display(Node *p) {
    while (p) {
        printf("%dx^%d ", p->coeff, p->exp);
        p = p->next;
    }
    printf("\n");
}

int main() {
    Node *p1 = NULL, *p2 = NULL;
    int c, e;

    while (1) {
        scanf("%d", &c);
        if (c == -1) break;
        scanf("%d", &e);
        p1 = insertTerm(p1, c, e);
    }

    while (1) {
        scanf("%d", &c);
        if (c == -1) break;
        scanf("%d", &e);
        p2 = insertTerm(p2, c, e);
    }

    Node *res = multiply(p1, p2);
    display(res);

    return 0;
}
