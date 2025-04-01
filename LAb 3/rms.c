#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 5
#define SIMULATION_TIME 20

// Task structure
typedef struct {
    int id; // Task ID
    int period; // Task period
    int execution; // Execution time (CPU burst)
    int remaining; // Remaining execution time
    int next_start; // Next activation time
} Task;

Task tasks[MAX_TASKS];
int task_count;

// Function to compare tasks based on rate-monotonic priority (shorter period first)
int compare_RMS(const void *a, const void *b) {
    return ((Task *)a)->period - ((Task *)b)->period;
}

// Rate-Monotonic Scheduling Simulation
void rate_monotonic_scheduling() {
    printf("\nRate-Monotonic Scheduling (RMS) Simulation:\n");
    qsort(tasks, task_count, sizeof(Task), compare_RMS); // Sort tasks by period

    for (int time = 0; time < SIMULATION_TIME; time++) {
        int selected_task = -1;
        
        // Find the highest priority task that can execute
        for (int i = 0; i < task_count; i++) {
            if (time >= tasks[i].next_start && tasks[i].remaining > 0) {
                selected_task = i;
                break; // Pick the first available (highest priority) task
            }
        }

        if (selected_task != -1) {
            tasks[selected_task].remaining--;
            printf("Time %d: Task %d executing\n", time, tasks[selected_task].id);
            
            // If task finishes execution
            if (tasks[selected_task].remaining == 0) {
                tasks[selected_task].next_start += tasks[selected_task].period;
                tasks[selected_task].remaining = tasks[selected_task].execution;
            }
        } else {
            printf("Time %d: CPU idle\n", time);
        }
    }
}

int main() {
    printf("Enter number of tasks (max %d): ", MAX_TASKS);
    scanf("%d", &task_count);

    if (task_count > MAX_TASKS || task_count <= 0) {
        printf("Invalid number of tasks!\n");
        return 1;
    }

    // Read task details
    for (int i = 0; i < task_count; i++) {
        printf("Enter Task %d execution time and period: ", i + 1);
        scanf("%d %d", &tasks[i].execution, &tasks[i].period);
        tasks[i].id = i + 1;
        tasks[i].remaining = tasks[i].execution;
        tasks[i].next_start = 0;
    }

    // Run Rate-Monotonic Scheduling
    rate_monotonic_scheduling();

    return 0;
}
