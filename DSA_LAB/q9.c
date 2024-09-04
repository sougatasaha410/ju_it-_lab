#include <stdio.h>
#include <stdlib.h>

struct stack {
    int top;
    int *p;
    int size;
};

void create(struct stack *st) {
    printf("Enter the size of the stack: ");
    scanf("%d", &st->size);
    st->p = (int *)malloc(st->size * sizeof(int));
    st->top = -1;
}

int isempty(struct stack *s) {
    return (s->top == -1);
}

int isfull(struct stack *s) {
    return (s->top == s->size - 1);
}

void push(struct stack *st, int x) {
    if (isfull(st)) {
        printf("Stack overflow\n");
    } else {
        st->top++;
        st->p[st->top] = x;
    }
}

int pop(struct stack *st) {
    int x = -1;
    if (isempty(st)) {
        printf("Stack underflow\n");
    } else {
        x = st->p[st->top];
        st->top--;
    }
    return x;
}

void display(struct stack *s1, struct stack *s2) {
    if (isempty(s1) && isempty(s2)) {
        printf("Queue is empty\n");
        return;
    }

    while (!isempty(s1)) {
        int x = pop(s1);
        push(s2, x);
    }

    for (int i = s2->top; i >= 0; i--) {
        printf("%d ", s2->p[i]);
    }
    printf("\n");

    while (!isempty(s2)) {
        int x = pop(s2);
        push(s1, x);
    }
}

void enqueue(struct stack *s1, int data) {
    push(s1, data);
}

void dequeue(struct stack *s1, struct stack *s2) {
    if (isempty(s2)) {
        if (isempty(s1)) {
            printf("Queue is empty\n");
        } else {
            while (!isempty(s1)) {
                int x = pop(s1);
                push(s2, x);
            }
        }
    }

    if (!isempty(s2)) {
        int x = pop(s2);
        printf("Dequeued element: %d\n", x);
    }
}

int main() {
    struct stack st1, st2;
    create(&st1);
    create(&st2);
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to enqueue: ");
                scanf("%d", &value);
                enqueue(&st1, value);
                break;

            case 2:
                dequeue(&st1, &st2);
                break;

            case 3:
                display(&st1, &st2);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);

    free(st1.p);
    free(st2.p);
    return 0;
}
