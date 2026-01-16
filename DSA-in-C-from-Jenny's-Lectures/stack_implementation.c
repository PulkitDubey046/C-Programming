#include<stdio.h>
# define N 10

int stack[N];
int top = -1;

void push(){
    int x;
    printf("Enter data:");
    scanf("%d",&x);
    if(top==N-1){
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top]=x;
}

void pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped element is %d\n",stack[top]);
    top--;
}

void peek(){
    if(top==-1){
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is %d\n",stack[top]);
}

void display(){
    if(top==-1){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for(int i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}   

int main(){
    int choice;
    while(1){
        printf("\n---- Stack Operations ----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
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
                printf("Invalid choice..");
        }
    }
}