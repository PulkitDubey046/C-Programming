#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};
  
struct Node* head;

void display(){
    if(head==NULL){
        printf("List is empty...");
        return;
    }
    printf("List:");
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n\n");
}

// insert at end
void insert_end(){
    int choice;
    while (choice)
    {
        struct Node *newNode= (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the value: ");
        scanf("%d",&newNode->data);
        newNode->next=NULL;
        newNode->prev=NULL;
        struct Node * temp;
        if(head==NULL){
            head=temp=newNode;
        }
        else{
            temp->next= newNode;
            newNode->prev = temp;
            temp=newNode;
        }

        printf("Inserted Successfully..");
        printf("Do you want to enter again(0,1): ");
        scanf("%d", &choice);
    }
    
}

//insert at start
void insert_start(){
    int choice=1;
    while(choice){
        struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter value to enter:");
        scanf("%d",& newNode->data);
        newNode->prev=NULL;
        newNode->next=NULL;
        if(head==NULL){
            head=newNode;
        }
        else{
            head->prev=newNode;
            newNode->next=head;
            head=newNode;
        }

        printf("Inserted Successfully..");
        printf("Do you want to enter again(0,1):");
        scanf("%d", &choice);
    }
}

// insert calling 
void insert_option(){
    int a;
    while(1){
        printf("Choose the operation you want to perform: \n");
        printf("1. Insert at start \n");
        printf("2. Insert at end \n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&a);
        switch (a)
        {
        case 1:
            insert_start();
            display();
            break;
        case 2:
            insert_end();
            display();
            break;
        default:
            break;
        }
    }
}

int main(){
    int a;
    while(1){
        printf("Choose the operation you want to perform: \n");
        printf("1. Insert \n");
        printf("2. Display \n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&a);
        switch (a)
        {
        case 1:
            insert_option();
            break;
        case 2:
            display();
            break;
        default:
            break;
        }
    }
}