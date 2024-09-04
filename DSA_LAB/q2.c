#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createCircularList(int n) {
    struct Node *head = NULL, *temp = NULL, *last = NULL;

    for (int i = 1; i <= n; i++) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = i;
        temp->next = head;

        if (head == NULL) {
            head = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }
    last->next = head;
    return head;
}

int josephus(struct Node *head, int k) {
    struct Node *p = head;
    struct Node *q = NULL;

    while (p->next != p) {
        for (int count = 1; count < k; count++) {
            p = p->next;
        }
        
        q = p->next;
        p->next = q->next;
        printf("Removing %d\n", q->data);
        free(q);
        p = p->next;
    }
    return p->data;
}

int main() {
    int n, k;

    printf("Enter the number of people (n): ");
    scanf("%d", &n);
    printf("Enter the step count (k): ");
    scanf("%d", &k);

    struct Node *head = createCircularList(n);
    int survivor = josephus(head, k);
    printf("The survivor is: %d\n", survivor);

    return 0;
}
