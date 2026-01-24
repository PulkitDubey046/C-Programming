#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int x){
    struct Node* newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->next = NULL;
    if(front==0 && rear==0){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue(){
    struct Node* temp;
    if(front==NULL){
        printf("Queue Underflow\n");
        return;
    }
    temp=front;
    printf("Dequeued %d\n", front->data);
    front=front->next;
    free(temp);
    if(front==NULL){
        rear=NULL;
    }
}

void display(){
    struct Node* temp;
    if(front==NULL){
        printf("Queue is empty\n");
        return;
    }
    temp=front;
    printf("Queue elements are:\n");
    while(temp!=NULL){
        printf("%d\n", temp->data);
        temp=temp->next;
    }
}

void peek(){
    if(front==NULL){
        printf("Queue is empty\n");
        return;
    }
    printf("Front element is %d\n", front->data);
}

int main(){
    int choice, x;
    while(1){
        printf("\n---- Queue Operations ----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
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
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}