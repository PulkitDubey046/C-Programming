#include <stdio.h>
# define N 5
int deque[N];
int F=-1, R=-1;

void enqueue_front(int data) {
    if (F == 0 && R == N - 1 || F == R + 1) {
        printf("Deque is full\n");
        return;
    }
    if (F == -1) {
        F = R = 0;
    } 
    else if (F == 0) {
        F = N - 1;
    } 
    else {
        F = F - 1;
    }
    deque[F] = data;
}

void enqueue_rear(int data) {
    if (F == 0 && R == N - 1 || F == R + 1) {
        printf("Deque is full\n");
        return;
    }
    if (F == -1) {
        F = R = 0;
    } 
    else if (R == N - 1) {
        R = 0;
    } 
    else {
        R = R + 1;
    }
    deque[R] = data;
}

void dequeue_front() {
    if (F == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted element from front: %d\n", deque[F]);
    if (F == R) {
        F = R = -1;
    } 
    else if (F == N - 1) {
        F = 0;
    } 
    else {
        F = F + 1;
    }
}

void dequeue_rear() {
    if (F == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted element from rear: %d\n", deque[R]);
    if (F == R) {
        F = R = -1;
    } 
    else if (R == 0) {
        R = N - 1;
    } 
    else {
        R = R - 1;
    }
}

void display() {
    int i;
    if (F == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Elements in the deque are: ");
    if (F <= R) {
        for (i = F; i <= R; i++) {
            printf("%d ", deque[i]);
        }
    } 
    else {
        for (i = F; i < N; i++) {
            printf("%d ", deque[i]);
        }
        for (i = 0; i <= R; i++) {
            printf("%d ", deque[i]);
        }
    }
    printf("\n");
}

int main() {
    enqueue_front(2);
    enqueue_front(5);
    enqueue_rear(0);
    enqueue_front(7);
    enqueue_front(4);
    display();

    dequeue_rear();
    display();

    dequeue_front();
    display();
    
    return 0;
}