#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    char *arr;
};

int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr, char value){
    if(isFull(ptr)){
        printf("\n Stack overflow");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=value;
    }
}
char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("\n Stack underflow");
        return 0;
    }
    else{
        char value=ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int isBalanced(char *exp){
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=25;
    sp->top=-1;
    sp->arr=(char*)malloc(sp->size*sizeof(char));
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            push(sp,'(');
        }
        else{
            if(exp[i]==')'){
                if(isEmpty(sp)){
                    return 0;
                }
                else{
                    pop(sp);
                }
            }
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
}
int main()
{
    char *exp= "8((9+1))";
    if(isBalanced(exp)){
        printf("\n The parantheses are balanced");
    }
    else{
        printf("\n The parantheses are not balanced");
    }
    return 0;
}
