#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff, exp;
    struct Node *next;
} Node;

Node* insertTerm(Node *h, int c, int e) {
    Node *n = malloc(sizeof(Node));
    n->coeff = c;
    n->exp = e;
    n->next = NULL;

    if (!h || e > h->exp) {
        n->next = h;
        return n;
    }
    Node *t = h;
    while (t->next && t->next->exp > e)
        t = t->next;
    n->next = t->next;
    t->next = n;
    return h;
}

Node* add(Node *p1, Node *p2) {
    Node *r = NULL;
    while (p1 && p2) {
        if (p1->exp > p2->exp) {
            r = insertTerm(r, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p2->exp > p1->exp) {
            r = insertTerm(r, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            r = insertTerm(r, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1) { r = insertTerm(r, p1->coeff, p1->exp); p1 = p1->next; }
    while (p2) { r = insertTerm(r, p2->coeff, p2->exp); p2 = p2->next; }
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

    Node *res = add(p1, p2);
    display(res);
    return 0;
}
