#include <stdio.h>

#define MAX 100

typedef struct {
    int heap[MAX];
    int size;
} MaxHeap;

void init(MaxHeap *h) {
    h->size = 0;
}

void heapUp(MaxHeap *h, int idx) {
    while (idx > 1) {
        int parent = idx / 2;
        if (h->heap[parent] < h->heap[idx]) {
            int temp = h->heap[parent];
            h->heap[parent] = h->heap[idx];
            h->heap[idx] = temp;
            idx = parent;
        } else {
            break;
        }
    }
}

void insert(MaxHeap *h, int value) {
    if (h->size >= MAX - 1) {
        printf("Heap is full!\n");
        return;
    }
    h->size++;
    h->heap[h->size] = value;
    heapifyUp(h, h->size);
}

void heapDown(MaxHeap *h, int idx) {
    while (idx * 2 <= h->size) {
        int left = idx * 2;
        int right = idx * 2 + 1;
        int larger = left;

        if (right <= h->size && h->heap[right] > h->heap[left]) {
            larger = right;
        }

        if (h->heap[larger] > h->heap[idx]) {
            int temp = h->heap[larger];
            h->heap[larger] = h->heap[idx];
            h->heap[idx] = temp;
            idx = larger;
        } else {
            break;
        }
    }
}

int deleteMax(MaxHeap *h) {
    if (h->size == 0) {
        printf("힙이 비었습니다.\n");
        return -1;
    }

    int maxValue = h->heap[1];
    h->heap[1] = h->heap[h->size];
    h->size--;
    heapifyDown(h, 1);

    return maxValue;
}


void printHeap(MaxHeap *h) {
    for (int i = 1; i <= h->size; i++) {
        printf("%d ", h->heap[i]);
    }
    printf("\n");
}

int main(void) {
    MaxHeap h;
    init(&h);

    insert(&h, 50);
    insert(&h, 30);
    insert(&h, 20);
    insert(&h, 15);
    insert(&h, 10);
    insert(&h, 8);
    insert(&h, 16);

    printf("힙 : ");
    printHeap(&h);

    printf("삭제 : %d\n", deleteMax(&h));
    printf("삭제 후 힙: ");
    printHeap(&h);

    return 0;
}
