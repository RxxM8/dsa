#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front=-1;
int rear=-1;

int isFull() {
    if ((front==0 && rear==SIZE-1) || (rear==(front-1)%(SIZE-1))) {
        return 1;
    }
    return 0;
}


int isEmpty() {
    if (front==-1) {
        return 1;
    }
    return 0;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow");
    } else {
        if (front == -1) { 
            front=rear=0;
        } else if (rear==SIZE-1 && front!=0) {
            rear=0; 
        } else {
            rear++;
        }
        queue[rear]=value;
        printf("Inserted %d", value);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow");
    } else {
        int data=queue[front];
        printf("Deleted element: %d", data);
        
        if (front==rear) { 
            front=rear=-1;
        } else if (front==SIZE-1) {
            front=0; 
        } else {
            front++;
        }
    }
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty.");
    } else {
        printf("Front element is: %d", queue[front]);
    }
}


void display() {
    if (isEmpty()) {
        printf("Queue is empty.");
        return;
    }
    printf("Elements in Circular Queue: ");
    if (rear>=front) {
        for (int i=front;i<=rear;i++)
            printf("%d ", queue[i]);
    } else {
        for (int i=front;i<SIZE;i++)
            printf("%d ", queue[i]);
        for (int i=0;i<=rear;i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n\n   Circular Queue Menu   ");
        printf("\n1) Enqueue");
        printf("\n2) Dequeue");
        printf("\n3) Peek");
        printf("\n4) Display");
        printf("\n5) Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                enqueue(val);
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
                exit(0);
            default:
                printf("Invalid choice! Please try again.");
        }
    }
    return 0;
}