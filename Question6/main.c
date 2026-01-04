#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;


void insertEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node* temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}


void insertAfter(int key, int value) {
    if (head == NULL)
        return;

    struct Node* temp = head;

    do {
        if (temp->data == key) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = value;

            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Value not found\n");
}


void deleteNode(int key) {
    if (head == NULL)
        return;

    struct Node* temp = head;
    struct Node* prev = NULL;


    if (head->data == key) {
        if (head->next == head) {
            free(head);
            head = NULL;
            return;
        }

        struct Node* last = head;
        while (last->next != head)
            last = last->next;

        last->next = head->next;
        free(head);
        head = last->next;
        return;
    }

    do {
        prev = temp;
        temp = temp->next;

        if (temp->data == key) {
            prev->next = temp->next;
            free(temp);
            return;
        }
    } while (temp != head);

    printf("Value not found\n");
}


void traverse() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main() {

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    traverse();

    insertAfter(20, 25);
    traverse();

    deleteNode(10);
    traverse();

    return 0;
}

