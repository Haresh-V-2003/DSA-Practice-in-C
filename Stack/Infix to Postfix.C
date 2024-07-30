#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int size;
    int top;
    char *arr;
};

int isFull(struct stack *ptr) {
    return ptr->top == ptr->size - 1;
}

int isEmpty(struct stack *ptr) {
    return ptr->top == -1;
}

char stackTop(struct stack *ptr) {
    if (!isEmpty(ptr)) {
        return ptr->arr[ptr->top];
    }
    return '\0'; // Return a null character if the stack is empty
}

void push(struct stack *ptr, char value) {
    if (isFull(ptr)) {
        printf("\nStack overflow");
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

char pop(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("\nStack underflow");
        return '\0'; // Return a null character if the stack is empty
    } else {
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int precedence(char ch) {
    if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '+' || ch == '-') {
        return 1;
    } else {
        return 0;
    }
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

char* infixToPostfix(char *infix) {
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    if (!sp) {
        printf("\nMemory allocation failed for stack");
        exit(1);
    }

    sp->size = 25;
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    if (!sp->arr) {
        printf("\nMemory allocation failed for stack array");
        exit(1);
    }

    char *postfix = (char *) malloc((strlen(infix) + 1) * sizeof(char));
    if (!postfix) {
        printf("\nMemory allocation failed for postfix array");
        exit(1);
    }

    int i = 0; // traverses infix expression
    int j = 0; // adds operands in the postfix expression

    while (infix[i] != '\0') {
        if (!isOperator(infix[i])) {
            postfix[j] = infix[i];
            i++;
            j++;
        } else {
            while (!isEmpty(sp) && precedence(infix[i]) <= precedence(stackTop(sp))) {
                postfix[j] = pop(sp);
                j++;
            }
            push(sp, infix[i]);
            i++;
        }
    }

    while (!isEmpty(sp)) {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';

    free(sp->arr);
    free(sp);

    return postfix;
}

int main() {
    char *infix = "a+b*c-d/e";
    char *postfix = infixToPostfix(infix);
    printf("The postfix of the given expression is %s\n", postfix);
    free(postfix);
    return 0;
}
