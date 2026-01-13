#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *newnode, *temp;

// Function to Create the Circular Linked List
void createCLL() {
    int choice = 1;
    head = NULL;

    while (choice) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
        
        // Linking the last node back to head to make it circular
        temp->next = head; 

        printf("Do you want to continue (0,1)? ");
        scanf("%d", &choice);
    }
}

// Function to Display the Circular Linked List
void display() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        temp = head;
        printf("The list is: ");
        
        // Loop runs until it reaches the last node (pointing back to head)
        while (temp->next != head) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        // Print the last node's data
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
                createCLL();
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