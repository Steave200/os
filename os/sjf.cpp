#include <stdio.h>
#define MAX 10
int main() {
    int n, i, j;
    int pid[MAX];         // Process IDs
    int burst_time[MAX];  // Burst Time
    int wait_time[MAX];   // Waiting Time
    int turn_time[MAX];   // Turnaround Time
    int total_wait_time = 0, total_turn_time = 0;
    // Input number of processes
printf("Enter the number of processes: ");
scanf("%d", &n);
    // Input burst times for each process
    for (i = 0; i< n; i++) {
pid[i] = i + 1; // Assigning process IDs
printf("Enter burst time for process P%d: ", pid[i]);
scanf("%d", &burst_time[i]);
    }
    // Sorting processes based on burst time (SJF)
    for (i = 0; i< n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (burst_time[j] >burst_time[j + 1]) {
                // Swap burst times
                int temp_burst = burst_time[j];
burst_time[j] = burst_time[j + 1];
burst_time[j + 1] = temp_burst;
                // Swap process IDs
                int temp_pid = pid[j];
pid[j] = pid[j + 1];
pid[j + 1] = temp_pid;
            }
        }
    }
    // Calculate waiting time and turnaround time
wait_time[0] = 0; // First process has no waiting time
    for (i = 1; i< n; i++) {
wait_time[i] = wait_time[i - 1] + burst_time[i - 1];
    }
    for (i = 0; i< n; i++) {
turn_time[i] = wait_time[i] + burst_time[i];
total_wait_time += wait_time[i];
total_turn_time += turn_time[i];
    }
    // Print results
printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i< n; i++) {
printf("P%d\t%d\t\t%d\t\t%d\n", pid[i], burst_time[i], wait_time[i], turn_time[i]);
    }
    // Print Gantt Chart
printf("\nGantt Chart:\n");
    for (i = 0; i< n; i++) {
printf("| P%d ", pid[i]);
    }
printf("|\n");
    for (i = 0; i< n; i++) {
        if (i == 0) {
printf("0 ");
        }
printf("%d ", wait_time[i] + burst_time[i]);
    }
printf("\n");
    // Calculate average waiting time and turnaround time
    float avg_wait_time = (float)total_wait_time / n;
    float avg_turn_time = (float)total_turn_time / n;
printf("\nAverage Waiting Time: %.2f\n", avg_wait_time);
printf("Average Turnaround Time: %.2f\n", avg_turn_time);
    return 0;
}

