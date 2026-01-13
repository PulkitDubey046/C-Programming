#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
} *tail;

void createCll(){
    int choice;
    tail=0;
    while(choice){
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        if(tail==NULL){
            tail=newnode;
            tail->next=newnode;
        }
        else{
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        printf("1 for Continue 0 for exit:");
        scanf("%d", &choice);
    }
}

void display(){
    struct node * temp;
    if(tail==NULL){
        printf("List is empty..");
    }
    else{
        temp=tail->next;
        while(temp->next!=tail->next){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d", temp->data);
    }
}

int main(){
    createCll();
    display();
}