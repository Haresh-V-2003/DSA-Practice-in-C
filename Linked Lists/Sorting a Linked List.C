#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to merge two sorted lists
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->val < l2->val) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

// Function to find the middle of the linked list
struct ListNode* findMiddle(struct ListNode* head) {
    if (!head) return head;

    struct ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to sort the linked list using Merge Sort
struct ListNode* mergeSort(struct ListNode* head) {
    if (!head || !head->next) return head;

    struct ListNode* middle = findMiddle(head);
    struct ListNode* nextToMiddle = middle->next;

    middle->next = NULL; // Split the list into two halves

    struct ListNode* left = mergeSort(head);
    struct ListNode* right = mergeSort(nextToMiddle);

    return merge(left, right);
}

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct ListNode* head = createNode(4);
    head->next = createNode(2);
    head->next->next = createNode(1);
    head->next->next->next = createNode(3);

    printf("Original list: ");
    printList(head);

    head = mergeSort(head);

    printf("Sorted list: ");
    printList(head);

    return 0;
}
