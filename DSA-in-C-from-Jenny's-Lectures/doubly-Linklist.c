#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};
  
struct Node* head, *tail = NULL;

// display function
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
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next= newNode;
            newNode->prev = tail;
            tail=newNode;
        }
        printf("Inserted Successfully..\n");
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
            head=tail=newNode;
        }
        else{
            head->prev=newNode;
            newNode->next=head;
            head=newNode;
        }

        printf("Inserted Successfully..\n");
        printf("Do you want to enter again(0,1):");
        scanf("%d", &choice);
    }
}

// insert at given position
void insert_position(){
    int pos, i=1;
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to enter:");
    scanf("%d",& newNode->data);
    newNode->prev=NULL;
    newNode->next=NULL;
    printf("Enter position to insert:");
    scanf("%d",&pos);
    struct Node *temp=head;
    while(i<pos-1 && temp!=NULL){
        temp=temp->next;
        i++;
    }
    if(temp==NULL){
        printf("Position not found\n");
    }
    else{
        newNode->next=temp->next;
        newNode->prev=temp;
        if(temp->next!=NULL){
            temp->next->prev=newNode;
        }
        temp->next=newNode;
        printf("Inserted Successfully..\n");
    }
}

// insert calling 
void insert_option(){
    int a;
    while(1){
        printf("Choose the operation you want to perform: \n");
        printf("1. Insert at start \n");
        printf("2. Insert at end \n");
        printf("3. Insert at given position \n");
        printf("4. Exit\n");
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
        case 3:
            insert_position();
            display();
            break;
        case 4:
            return;
            break;
        default:
            break;
        }
    }
}

// delete from start
void delete_start(){
    if(head==NULL){
        printf("List is empty, deletion not possible..\n");
        return;
    }
    struct Node *temp=head;
    head=head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
    else{
        tail=NULL;
    }
    free(temp);
    printf("Deleted Successfully..\n");
}

//delete from given position
void delete_position(){
    int pos, i=1;
    printf("Enter position to delete:");
    scanf("%d",&pos);
    struct Node *temp=head;
    if(head==NULL){
        printf("List is empty, deletion not possible..\n");
        return;
    }
    if(pos==1){
        delete_start();
        return;
    }
    while(i<pos && temp!=NULL){
        temp=temp->next;
        i++;
    }
    if(temp==NULL){
        printf("Position not found\n");
    }
    else{
        temp->prev->next=temp->next;
        if(temp->next!=NULL){
            temp->next->prev=temp->prev;
        }
        else{
            tail=temp->prev;
        }
        free(temp);
        printf("Deleted Successfully..\n");
    }
}

// delete from end
void delete_end(){
    if(head==NULL){
        printf("List is empty, deletion not possible..\n");
    }
    struct Node *temp=tail;
    tail=tail->prev;
    if(tail!=NULL){
        tail->next=NULL;
    }
    else{
        head=NULL;
    }
    free(temp);
    printf("Deleted Successfully..\n");   
}



// delete calling 
void delete_option(){
    int a;
    while(1){
        printf("Choose the operation you want to perform: \n");
        printf("1. Delete from start \n");
        printf("2. Delete from end \n");
        printf("3. Delete from given position \n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&a);
        switch (a)
        {
        case 1:
            delete_start();
            display();
            break;
        case 2:
            delete_end();
            display();
            break;
        case 3:
            delete_position();
            display();
            break;
        case 4:
            return;
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
        printf("3. Delete\n");
        printf("4. Exit\n");
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
        case 3:
            delete_option();
            break;
        case 4:
            return 0;
            break;
        default:
            break;
        }
    }
}