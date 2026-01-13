#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head, *tail;

void createCll(){
    struct node * newnode;
    head =0;
    int choice=1;
    while(choice){
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter data :");
        scanf("%d", &newnode->data);
        newnode->next=0;
        if(head==0){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        tail->next=head;
        printf("1 for Continue 0 for exit:");
        scanf("%d", &choice);
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct node *temp = head;
        printf("The list is: ");

        while (temp->next != head) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}

int main() {
    
    while (1) {
        int a;
        printf("\n=== Circular Linked List ===");
        printf("\n1. Insert");
        printf("\n2. Display");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &a);
  
        switch(a) {
            case 1:
                createCll();
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    

    return 0;
}