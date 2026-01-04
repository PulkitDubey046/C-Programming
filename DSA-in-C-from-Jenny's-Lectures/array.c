#include <stdio.h>
int arr[50];
int size = 0;

void array_insertion_end()
{
    int a = 1;
    while (a)
    {
        if (size < 50)
        {
            int element;
            printf("Enter element to insert at end:");
            scanf("%d", &element);
            arr[size] = element;
            size++;
            printf("Element %d inserted at end successfully.\n", element);
        }
        else
        {
            printf("Array is full!!!\n Array size limit reached.");
        }
        printf("Do you want to enter again(1 for yes/0 for no): ");
        scanf("%d", &a);
    }
}

void array_insertion()
{
    while (1)
    {
        int choice;
        printf("How to insert:\n");
        printf("1. Insert at end\n");
        printf("2. Insert at beggining\n");
        printf("3. Insert at given location\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            array_insertion_end();
            printf("\n");
            break;

        default:
            printf("Invalid choice! Try again.");
            break;
        }
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("Select task to perform on array:\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Delete\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            array_insertion();
            printf("\n");
            break;

        default:
            printf("Invalid choice! Try again.");
            break;
        }
    }
    return 0;
}