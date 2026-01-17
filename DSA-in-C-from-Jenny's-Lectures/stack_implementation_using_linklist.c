// Implementaion of stack using linked list

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node{
    int data;
    struct node* link;
};
struct node* top = NULL;

void push(int x){
    if(top != NULL && top->data == INT_MAX){
        printf("Stack Overflow\n");
        return;
    }
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->link = top;
    top = newnode;
}

void pop(){
    if(top == NULL){
        printf("Stack Underflow\n");
        return;
    }
    struct node* temp = top;
    top = top->link;
    free(temp);
}

void peek(){
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("%d",top->data);
}

void display(){
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }
    struct node* temp = top;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->link;
    }
}

int main(){
    int choice, x;
    while(1){
        printf("\n---- Stack Operations ----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the value to push:");
                scanf("%d",&x);
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice..");
        }
    }
}