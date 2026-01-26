#include <stdio.h>
#include <stdlib.h>

#define N 5

int s1[N], s2[N];
int top1 = -1, top2 = -1;
int count = 0;

void push1(int data) {
    if (top1 == N - 1) {
        printf("Queue is full\n");
    } else {
        s1[++top1] = data;
    }
}

void push2(int data) {
    if (top2 == N - 1) {
        printf("Queue is full\n");
    } else {
        s2[++top2] = data;
    }
}

int pop1() {
    if (top1 == -1) {
        return -1;
    }
    return s1[top1--];
}

int pop2() {
    if (top2 == -1) {
        return -1;
    }
    return s2[top2--];
}

void enqueue(int x) {
    push1(x);
    count++;
}

void dequeue() {
    int i, a, b;

    if (top1 == -1) {
        printf("Queue is empty\n");
        return;
    }

    /* Move all elements from s1 to s2 */
    for (i = 0; i < count; i++) {
        a = pop1();
        push2(a);
    }

    /* Pop the front element */
    b = pop2();
    printf("Dequeued element: %d\n", b);
    count--;

    /* Move remaining elements back to s1 */
    for (i = 0; i < count; i++) {
        a = pop2();
        push1(a);
    }
}

void display() {
    if (top1 == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = 0; i <= top1; i++) {
        printf("%d ", s1[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    enqueue(40);
    display();

    return 0;
}
