#include <stdio.h>
#include <limits.h>

#define MAX 100

// Function to check if a page is already in memory
int isPageInMemory(int memory[], int frames, int page) {
    for (int i = 0; i < frames; i++) {
        if (memory[i] == page) {
            return 1;
        }
    }
    return 0;
}

// Function for FIFO page replacement
int fifo(int frames, int *front) {
    int pos = *front;
    *front = (*front + 1) % frames; // Update front to the next position
    return pos;
}

// Function for LRU page replacement
int lru(int memory[], int frames, int referenceString[], int current, int n) {
    int least_recent[MAX], lru_index = -1, min_time = INT_MAX;

    for (int i = 0; i < frames; i++) {
        least_recent[i] = -1;
        for (int j = current - 1; j >= 0; j--) {
            if (memory[i] == referenceString[j]) {
                least_recent[i] = j;
                break;
            }
        }

        if (least_recent[i] < min_time) {
            min_time = least_recent[i];
            lru_index = i;
        }
    }

    return lru_index;
}

// Function for Optimal page replacement
int optimal(int memory[], int frames, int referenceString[], int current, int n) {
    int future[MAX], opt_index = -1, max_time = -1;

    for (int i = 0; i < frames; i++) {
        future[i] = -1;
        for (int j = current + 1; j < n; j++) {
            if (memory[i] == referenceString[j]) {
                future[i] = j;
                break;
            }
        }

        if (future[i] == -1) {
            return i; // Page not used in future, replace this
        }

        if (future[i] > max_time) {
            max_time = future[i];
            opt_index = i;
        }
    }

    return opt_index;
}

// Function to simulate page replacement algorithms
void simulate(int referenceString[], int n, int frames, char algorithm[]) {
    int memory[frames], pageFaults = 0, front = 0;

    for (int i = 0; i < frames; i++) {
        memory[i] = -1; // Initialize memory with -1
    }

    printf("\nSimulating %s Algorithm:\n", algorithm);
    printf("Reference String: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", referenceString[i]);
    }
    printf("\nFrames State:\n");

    for (int i = 0; i < n; i++) {
        if (!isPageInMemory(memory, frames, referenceString[i])) {
            int pos;

            if (strcmp(algorithm, "FIFO") == 0) {
                pos = fifo(frames, &front);
            } else if (strcmp(algorithm, "LRU") == 0) {
                pos = lru(memory, frames, referenceString, i, n);
            } else if (strcmp(algorithm, "Optimal") == 0) {
                pos = optimal(memory, frames, referenceString, i, n);
            } else {
                printf("Invalid algorithm selected.\n");
                return;
            }

            memory[pos] = referenceString[i];
            pageFaults++;

            // Print current state of memory
            printf("Step %2d: ", i + 1);
            for (int j = 0; j < frames; j++) {
                if (memory[j] == -1) {
                    printf("[ ] ");
                } else {
                    printf("[%d] ", memory[j]);
                }
            }
            printf("\n");
        }
    }

    printf("\nTotal Page Faults using %s: %d\n", algorithm, pageFaults);
}

int main() {
    int n, frames;
    int referenceString[MAX];

    printf("Enter the number of pages in the reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string (space-separated):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &referenceString[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    // Simulate each algorithm
    simulate(referenceString, n, frames, "FIFO");
    simulate(referenceString, n, frames, "LRU");
    simulate(referenceString, n, frames, "Optimal");

    return 0;
}
