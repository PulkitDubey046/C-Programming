#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
}*head=NULL,*tail=NULL;

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

void insert_at_begining(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    if(head==NULL){
        head=tail=newnode;  
        head->next=head;
        head->prev=head;
    }
    else{
        newnode->next=head;
        newnode->prev=tail;
        head->prev=newnode;
        tail->next=newnode;
        head=newnode;
    }
}

void insert_at_end(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
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
}

void insert_at_given_pos(){
    int pos,i;
    struct node *newnode,*temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    printf("Enter position to insert: ");
    scanf("%d",&pos);

    if(pos==1){
        insert_at_begining();
        return;
    }

    for(i=1;i<pos-1;i++){
        temp=temp->next;
        if(temp==head){
            printf("Position out of bounds..\n");
            return;
        }
    }

    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next->prev=newnode;
    temp->next=newnode;

    if(temp==tail){
        tail=newnode;
    }
}

void insertion(){
    int choice;
    while(1){
        printf("\nChoose how to insert in doubly linked-list \n");
        printf("1. Insert at begining\n");
        printf("2. Insert at end\n");
        printf("3. Insert at given position\n");
        printf("4. Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                insert_at_begining();
                break;
            case 2:
                insert_at_end();
                break;
            case 3:
                insert_at_given_pos();
                break;
            case 4:
                return;
                break;
            default:
                printf("Invalid choice..");
        }
    }
}

void delete_from_begining(){
    struct node *temp;
    if(head==NULL){
        printf("List is empty..\n");
        return;
    }
    else if(head==tail){
        free(head);
        head=tail=NULL;
    }
    else{
        temp=head;
        head=head->next;
        head->prev=tail;
        tail->next=head;
        free(temp);
    }
}

void delete_from_end(){
    struct node *temp;
    if(head==NULL){
        printf("List is empty..\n");
        return;
    }
    else if(head==tail){
        free(head);
        head=tail=NULL;
    }
    else{
        temp=tail;
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        free(temp);
    }
}


void delete_from_given_pos(){
    struct node * temp;
    int pos, i=1, l;
    temp=head;
    printf("Enter position:");
    scanf("%d",&pos);
    if(head==NULL){
        printf("List is empty..\n");
        return;
    }
    if(pos==1){
        delete_from_begining();
        return;
    }
    while(i<pos-1){
        temp=temp->next;
        if(temp==head){
            printf("Position out of bounds..\n");
            return;
        }
        i++;
    }
    struct node *delnode=temp->next;
    temp->next=delnode->next;
    delnode->next->prev=temp;
    free(delnode);
}

void deletion(){
    int choice;
    while(1){
        printf("\nChoose how to insert in doubly linked-list \n");
        printf("1. Delete from begining\n");
        printf("2. Delete from end\n");
        printf("3. Delete from given position\n");
        printf("4. Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                delete_from_begining();
                break;
            case 2:
                delete_from_end();
                break;
            case 3:
                delete_from_given_pos();
                break;
            case 4:
                return;
                break;
            default:
                printf("Invalid choice..");
        }
    }
}

int main(){
    int choice;
    while(1){
        printf("\n---- Doubly linked-list ----\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Delete\n");
        printf("4. Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                insertion();
                break;
            case 2:
                displayDLL();
                break;
            case 3:
                deletion();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice..");
        }
    }
}

