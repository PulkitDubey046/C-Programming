#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
}*head=NULL,*tail=NULL;

void createDLL(){
    int choice=1;
    struct node* newnode;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head==NULL){
            head=tail=newnode;  
            head->next=head;
            head->prev=head;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            newnode->next=head;
            head->prev=newnode;
            tail=newnode;
        }
        printf("Do you want to continue(0/1): ");
        scanf("%d",&choice);
    }
}

void displayDLL(){
    struct node* temp=head;
    if(head==NULL){
        printf("List is empty..\n");
        return;
    }
    else{
        printf("Doubly Linked List: ");
        while(temp!=tail){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
        printf("\n");
    }
}

int main(){
    createDLL();
    displayDLL();
    return 0;
}