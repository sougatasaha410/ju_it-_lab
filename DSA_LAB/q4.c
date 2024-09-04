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

void push(struct stack *st, int x) {
    if (st->top == st->size - 1) {
        printf("Stack overflow\n");
    } else {
        st->top++;
        st->p[st->top] = x;
    }
}

void display(struct stack s) {
    for (int i = s.top; i >= 0; i--) {
        printf("%d ", s.p[i]);
    }
    printf("\n");
}

int pop(struct stack *st) {
    int x = -1;
    if (st->top == -1) {
        printf("Stack underflow\n");
    } else {
        x = st->p[st->top];
        st->top--;
    }
    return x;
}

int peak(struct stack s, int pos) {
    if (s.top - pos + 1 < 0) {
        return -1;
    } else {
        return s.p[s.top - pos + 1];
    }
}

int stacktop(struct stack s) {
    return (s.top == -1) ? -1 : s.p[s.top];
}

int isempty(struct stack s) {
    return (s.top == -1);
}

int isfull(struct stack s) {
    return (s.top == s.size - 1);
}

int main() {
    struct stack st;
    int choice, value, pos;

    create(&st);

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if stack is full\n");
        printf("6. Check if stack is empty\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to push: ");
                scanf("%d", &value);
                push(&st, value);
                break;

            case 2:
                value = pop(&st);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;

            case 3:
                printf("Enter position from top to peek: ");
                scanf("%d", &pos);
                value = peak(st, pos);
                if (value != -1) {
                    printf("Value at position %d from top: %d\n", pos, value);
                } else {
                    printf("Invalid position!\n");
                }
                break;

            case 4:
                display(st);
                break;

            case 5:
                if (isfull(st)) {
                    printf("Stack is full\n");
                } else {
                    printf("Stack is not full\n");
                }
                break;

            case 6:
                if (isempty(st)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
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

    free(st.p);
    return 0;
}
