# include <stdio.h>
# define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x){
    if(rear == N - 1){
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1){
        front = 0;
    }
    rear++;
    queue[rear] = x;
    printf("Enqueued %d\n", x);
}

void dequeue(){
    if(front == -1 || front > rear){
        printf("Queue Underflow\n");
        return;
    }
    else if (front == rear){
        front= rear = -1;
        printf("Dequeued %d\n", queue[front]);
        return;
    }
    printf("Dequeued %d\n", queue[front]);
    front++;
}

void display(){
    if(front == -1 || front > rear){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are:\n");
    for(int i = front; i <= rear; i++){
        printf("%d\n", queue[i]);
    }
}

void peek(){
    if(front == -1 || front > rear){
        printf("Queue is empty\n");
        return;
    }
    printf("Front element is %d\n", queue[front]);
}

int main(){
    int choice, x;
    while(1){
        printf("\n---- Queue Operations ----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}