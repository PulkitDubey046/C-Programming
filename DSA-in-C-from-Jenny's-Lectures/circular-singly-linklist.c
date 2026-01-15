#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *tail;

void display_linked_list()
{
    if (tail == 0)
    {
        printf("List is empty");
    }
    else
    {
        struct node *temp;
        temp = tail->next;
        while (temp != tail)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
    }
}

void insert_at_beg()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (tail == 0)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
    }
}

void insert_at_end()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (tail == 0)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}


int getlength()
{
    if (tail == NULL)
        return 0;

    int l = 1;
    struct node *temp = tail->next;

    while (temp != tail)
    {
        l++;
        temp = temp->next;
    }
    return l;
}


// insert at given position
void insert_pos()
{
    int pos, l;
    printf("Enter position: ");
    scanf("%d", &pos);

    l = getlength();

    if (pos < 1 || pos > l + 1)
    {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1)
    {
        insert_at_beg();
        return;
    }

    if (pos == l + 1)
    {
        insert_at_end();
        return;
    }

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    struct node *temp = tail->next;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
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
            insert_at_end();
            display_linked_list();
            printf("\n");
            break;
        case 2:
            insert_at_beg();
            display_linked_list();
            printf("\n");
            break;
        case 3:
            insert_pos();
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

void delete_from_end()
{
    struct node *current, *previous;
    current = tail->next;
    if (tail == NULL)
    {
        printf("List is empty.");
    }
    else if (current->next == current)
    {
        tail = NULL;
        free(current);
        return;
    }
    else
    {
        while (current->next != tail->next)
        {
            previous = current;
            current = current->next;
        }
        previous->next = tail->next;
        tail = previous;
        free(current);
    }
}

// Delete from begining
void delete_beg()
{
    struct node *temp = tail->next;
    if (tail == NULL)
    {
        printf("List is empty.");
    }
    else if (tail->next == tail)
    {
        tail = NULL;
        free(temp);
    }
    else
    {
        tail->next = temp->next;
        free(temp);
    }
}

// Delete from positon
void delete_from_Pos()
{
    struct node *current, *nextnode;
    int pos, i = 1, l;
    current = tail->next;
    printf("Enter position:");
    scanf("%d", &pos);
    l = getlength();
    if (l == 0)
    {
        printf("List is empty");
    }
    else if (pos < 1 || pos > l)
    {
        printf("Invalid position.");
    }
    else if (pos == 1)
    {
        delete_beg();
    }
    else
    {
        while (i < pos - 1)
        {
            current = current->next;
            i++;
        }
        nextnode = current->next;
        current->next = nextnode->next;
        free(nextnode);
    }
}

// Reverse a circular singly linked list
void reverse_linked_list()
{
    struct node *current, *nextnode, *prev;
    current = tail->next;
    nextnode = current->next;
    if (tail == 0)
    {
        printf("List is empty.");
    }
    while (current != tail)
    {
        prev = current;
        current = nextnode;
        nextnode = current->next;
        current->next = prev;
    }
    nextnode->next = tail;
    tail = nextnode;
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
        printf("3. Delete given position\n");
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
            delete_beg();
            display_linked_list();
            printf("\n");
            break;
        case 3:
            delete_from_Pos();
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

int main()
{
    while (1)
    {
        int choice, l;

        printf("\nChoose any task you want to perform on linked list:\n");
        printf("1. Insert Linked List\n");
        printf("2. Display Linked List\n");
        printf("3. Delete Linked List\n");
        printf("4. Find the length of Linked List\n");
        printf("5. Reverse a linklist\n");
        printf("6. Exit\n");
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
            l = getlength();
            printf("Length of linked list: %d\n", l);
            break;
        case 5:
            reverse_linked_list();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}