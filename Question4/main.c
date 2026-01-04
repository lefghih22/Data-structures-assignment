#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;



void insertMax(int value) {
    int i = size++;
    heap[i] = value;

    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void displayMax() {
    printf("Max Heap: ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}



void insertMin(int value) {
    int i = size++;
    heap[i] = value;

    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

void displayMin() {
    printf("Min Heap: ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {


    size = 0;
    insertMax(10);
    insertMax(20);
    insertMax(5);
    insertMax(30);

    displayMax();


    size = 0;
    insertMin(10);
    insertMin(20);
    insertMin(5);
    insertMin(30);

    displayMin();

    return 0;
}
