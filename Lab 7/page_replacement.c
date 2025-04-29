#include <stdio.h>

int findOptimal(int pages[], int frames[], int n, int index, int capacity) {
    int farthest = index;
    int result = -1;
    for (int i = 0; i < capacity; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    result = i;
                }
                break;
            }
        }
        if (j == n)
            return i;
    }
    return result == -1 ? 0 : result;
}

int search(int key, int frame[], int size) {
    for (int i = 0; i < size; i++)
        if (frame[i] == key)
            return i;
    return -1;
}

void fifo(int pages[], int n, int capacity) {
    printf("FIFO Page Replacement Process:\n");
    int frame[capacity];
    int front = 0, count = 0, faults = 0;

    for (int i = 0; i < capacity; i++)
        frame[i] = -1;

    for (int i = 0; i < n; i++) {
        if (search(pages[i], frame, capacity) == -1) {
            frame[front] = pages[i];
            front = (front + 1) % capacity;
            faults++;
        }
        printf("PF No. %d: ", i + 1);
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }
        printf("\n");
    }
    printf("FIFO Page Faults: %d\n\n", faults);
}

void lru(int pages[], int n, int capacity) {
    printf("LRU Page Replacement Process:\n");
    int frame[capacity], used[capacity];
    int faults = 0;

    for (int i = 0; i < capacity; i++)
        frame[i] = -1;

    for (int i = 0; i < n; i++) {
        int pos = search(pages[i], frame, capacity);
        if (pos == -1) {
            int lru = 0;
            for (int j = 1; j < capacity; j++) {
                if (used[j] < used[lru])
                    lru = j;
            }
            for (int j = 0; j < capacity; j++)
                if (frame[j] == -1) {
                    lru = j;
                    break;
                }
            frame[lru] = pages[i];
            used[lru] = i;
            faults++;
        } else {
            used[pos] = i;
        }
        printf("PF No. %d: ", i + 1);
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }
        printf("\n");
    }
    printf("LRU Page Faults: %d\n\n", faults);
}

void optimal(int pages[], int n, int capacity) {
    printf("Optimal Page Replacement Process:\n");
    int frame[capacity], faults = 0;

    for (int i = 0; i < capacity; i++)
        frame[i] = -1;

    for (int i = 0; i < n; i++) {
        if (search(pages[i], frame, capacity) == -1) {
            int index = -1;
            for (int j = 0; j < capacity; j++) {
                if (frame[j] == -1) {
                    index = j;
                    break;
                }
            }
            if (index == -1)
                index = findOptimal(pages, frame, n, i + 1, capacity);
            frame[index] = pages[i];
            faults++;
        }
        printf("PF No. %d: ", i + 1);
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }
        printf("\n");
    }
    printf("Optimal Page Faults: %d\n", faults);
}

int main() {
    int capacity, n, pages[100];
    printf("Enter the number of Frames: ");
    scanf("%d", &capacity);
    printf("Enter the length of reference string: ");
    scanf("%d", &n);
    printf("Enter the reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    fifo(pages, n, capacity);
    lru(pages, n, capacity);
    optimal(pages, n, capacity);
    return 0;
}                                                                                                     
