#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// insert at end
void insert_linked_list(void)
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

// display list
void display_linked_list(void)
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

// delete by value
void delete_linked_list(void)
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
            insert_linked_list();
            break;
        case 2:
            display_linked_list();
            break;
        case 3:
            delete_linked_list();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
