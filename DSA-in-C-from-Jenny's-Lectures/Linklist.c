#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// display list
void display_linked_list()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// insert at end
void insert_linked_list()
{
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        printf("Inserted as first node.\n");
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    printf("Inserted successfully.\n");
}

// insert at start
void insert_start()
{
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;

    printf("Inserted successfully.\n");
}

// insert at given location
void insert_loc()
{
    int l;
    printf("Enter the position: ");
    scanf("%d", &l);

    int value;
    printf("Enter the value: ");
    scanf("%d", &value);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (l == 0)
    {
        newNode->next = head;
        head = newNode;
        printf("Inserted successfully.\n");
        return;
    }

    struct Node *temp = head;

    for (int i = 0; i < l - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted successfully.\n");
}

// insertion
void linkedlist_insertion()
{
    while (1)
    {
        int choice;
        printf("\nHow to insert:\n");
        printf("1. Insert at end\n");
        printf("2. Insert at beggining\n");
        printf("3. Insert at given location\n");
        printf("4. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_linked_list();
            display_linked_list();
            printf("\n");
            break;
        case 2:
            insert_start();
            display_linked_list();
            printf("\n");
            break;
        case 3:
            insert_loc();
            display_linked_list();
            printf("\n");
            break;
        case 4:
            return;
            break;
        default:
            printf("Invalid choice! Try again.");
            break;
        }
    }
}

// delete from start
void delete_from_start()
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    printf("Deleted successfully.\n");
}

void delete_from_end(){ 
    if(head==NULL){
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node *temp, *prev;
    temp=head;
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next=NULL;
    free(temp);
    printf("Deleted successfully.\n");
}

// delete by value
void delete_by_value()
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    int value;
    printf("Enter value to delete: ");
    scanf("%d", &value);

    struct Node *temp = head;
    struct Node *prev = NULL;

    // if head node itself holds the value
    if (temp != NULL && temp->data == value)
    {
        head = temp->next;
        free(temp);
        printf("Deleted %d.\n", value);
        return;
    }

    // search in the rest of the list
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted %d.\n", value);
}

// Deletion of linkedlist
void linkedlist_deletion()
{
    while (1)
    {
        int choice;
        printf("\nHow to delete:\n");
        printf("1. Delete from end\n");
        printf("2. Delete from beggining\n");
        printf("3. Delete given value\n");
        printf("4. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            delete_from_end();
            display_linked_list();
            printf("\n");
            break;
        case 2:
            delete_from_start();
            display_linked_list();
            printf("\n");
            break;
        case 3:
            delete_by_value();
            display_linked_list();
            printf("\n");
            break;
        case 4:
            return;
            break;
        default:
            printf("Invalid choice! Try again.");
            break;
        }
    }
}

int main(void)
{
    while (1)
    {
        int choice;

        printf("\nChoose any task you want to perform on linked list:\n");
        printf("1. Insert Linked List\n");
        printf("2. Display Linked List\n");
        printf("3. Delete Linked List\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            linkedlist_insertion();
            break;
        case 2:
            display_linked_list();
            break;
        case 3:
            linkedlist_deletion();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
