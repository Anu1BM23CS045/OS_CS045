#include <stdio.h>

#define MAX_BLOCKS 50

int main() {
    int memory[MAX_BLOCKS] = {0}; // 0 = free, 1 = allocated
    int file_count, i, j, start_block, length, flag;

    printf("Enter the number of files: ");
    scanf("%d", &file_count);

    for (i = 0; i < file_count; i++) {
        printf("\nFile %d\n", i + 1);
        printf("Enter the starting block: ");
        scanf("%d", &start_block);
        printf("Enter the length (number of blocks): ");
        scanf("%d", &length);

        if (start_block < 0 || start_block + length > MAX_BLOCKS) {
            printf("Error: Blocks out of range.\n");
            continue;
        }

        flag = 1;
        for (j = start_block; j < start_block + length; j++) {
            if (memory[j] == 1) {
                flag = 0;
                break;
            }
        }

        if (flag == 1) {
            printf("File allocated in blocks: ");
            for (j = start_block; j < start_block + length; j++) {
                memory[j] = 1;
                printf("%d ", j);
            }
            printf("\n");
        } else {
            printf("File allocation failed. Some blocks are already allocated.\n");
        }
    }

    printf("\nFinal block allocation status:\n");
    for (i = 0; i < MAX_BLOCKS; i++) {
        printf("Block %d: %s\n", i, memory[i] ? "Allocated" : "Free");
    }

    return 0;
}
