#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size) {
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int x) {
    if (q->rear == q->size - 1) {
        printf("Queue is Full\n");
    } else {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q) {
    int x = -1;

    if (q->front == q->rear) {
        printf("Queue is Empty\n");
    } else {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q) {
    for (int i = q.front + 1; i <= q.rear; i++)
        printf("%d ", q.Q[i]);
    printf("\n");
}

int count(struct Queue q) {
    int c = 0;
    for (int i = q.front + 1; i <= q.rear; i++)
        c++;
    return c;
}

int overflow(struct Queue q) {
    return q.rear == q.size - 1;
}

int underflow(struct Queue q) {
    return q.rear == q.front;
}

int main() {
    struct Queue q;
    int choice, value;

    printf("Enter the size of the queue: ");
    scanf("%d", &q.size);
    create(&q, q.size);

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Count elements\n");
        printf("5. Check if queue is full\n");
        printf("6. Check if queue is empty\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;

            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;

            case 3:
                Display(q);
                break;

            case 4:
                printf("Number of elements in the queue: %d\n", count(q));
                break;

            case 5:
                if (overflow(q)) {
                    printf("Queue is full\n");
                } else {
                    printf("Queue is not full\n");
                }
                break;

            case 6:
                if (underflow(q)) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;

            case 7:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 7);

    free(q.Q);
    return 0;
}
