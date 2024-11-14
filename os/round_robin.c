#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum) {
    int rem_bt[n]; // Remaining burst times
    for (int i = 0; i < n; i++) {
        rem_bt[i] = bt[i];
    }

    int t = 0; // Current time

    while (1) {
        int done = 1; // Flag to check if all processes are done

        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0; // There is a pending process

                if (rem_bt[i] > quantum) {
                    t += quantum; // Increment time by quantum
                    rem_bt[i] -= quantum; // Reduce remaining burst time
                } else {
                    t += rem_bt[i]; // Increment time by remaining burst time
                    wt[i] = t - bt[i]; // Calculate waiting time
                    rem_bt[i] = 0; // Mark as complete
                }
            }
        }

        if (done == 1) {
            break; // All processes are done
        }
    }
}

void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i]; // Turnaround time = burst time + waiting time
    }
}

void findAverageTime(int processes[], int n, int bt[], int quantum) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt, quantum);
    findTurnaroundTime(processes, n, bt, wt, tat);

    printf("\nProcesses\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / n);
}

int main() {
    int n, quantum;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n];
    printf("Enter burst times for the processes:\n");
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1; // Process IDs
        printf("P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    // Input time quantum
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    // Calculate average times
    findAverageTime(processes, n, burst_time, quantum);

    return 0;
}
