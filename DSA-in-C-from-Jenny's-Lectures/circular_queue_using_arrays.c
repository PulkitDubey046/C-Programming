#include<stdio.h>
#include<stdlib.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;

void enqueue(int x){
    if(front==-1 && rear==-1){
        front=0;
        rear=0;
    }
    else if((rear+1)%N==front){
        printf("Queue Overflow\n");
        return;
    }
    else{
        rear=(rear+1)%N;
    }
    queue[rear]=x;
}

void dequeue(){
    if(front==-1 && rear==-1){
        printf("Queue Underflow\n");
        return;
    }
    else if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        printf("Deleted element is %d\n",queue[front]);
        front=(front+1)%N;
    }
}

void display(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
        return;
    }
    int i=front;
    printf("Elements in the queue are: ");
    while(1){
        printf("%d ",queue[i]);
        if(i==rear){
            break;
        }
        i=(i+1)%N;
    }
    printf("\n");
}

int main(){
    int choice, value;
    while(1){
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}