#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void printnode(struct Node *head) {
    struct Node *p = head;
    while (p != NULL) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

struct Node *createnode(int value) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->next = NULL;
    return ptr;
}

void splitlist(struct Node *head) {
    int count = 0;
    struct Node *oddHead = NULL, *oddTail = NULL;
    struct Node *evenHead = NULL, *evenTail = NULL;
    struct Node *q = head;
    
    while (q != NULL) {
        if (count % 2 == 0) {
            if (evenHead == NULL) {
                evenHead = evenTail = createnode(q->data);
            } else {
                evenTail->next = createnode(q->data);
                evenTail = evenTail->next;
            }
        } else {
            if (oddHead == NULL) {
                oddHead = oddTail = createnode(q->data);
            } else {
                oddTail->next = createnode(q->data);
                oddTail = oddTail->next;
            }
        }
        q = q->next;
        count++;
    }

    printf("\nOdd position elements: ");
    printnode(oddHead);
    printf("Even position elements: ");
    printnode(evenHead);
}

int main() {
    struct Node *head = createnode(10);
    head->next = createnode(20);
    head->next->next = createnode(30);
    head->next->next->next = createnode(40);
    head->next->next->next->next = createnode(50);
    head->next->next->next->next->next = createnode(60);

    printf("\nBefore splitting: ");
    printnode(head);
    printf("After splitting:");
    splitlist(head);

    return 0;
}
