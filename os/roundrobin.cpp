#include <stdio.h>
#define MAX 10
int main() {
    int n, i, j, time_quantum;
    int pid[MAX];          // Process IDs
    int burst_time[MAX];   // Burst Time
    int remaining_time[MAX]; // Remaining Time
    int wait_time[MAX];    // Waiting Time
    int turn_time[MAX];    // Turnaround Time
    int total_wait_time = 0, total_turn_time = 0;
    int completed = 0;     // Number of completed processes
    int time = 0;          // Current time
    // Input number of processes and time quantum
printf("Enter the number of processes: ");
scanf("%d", &n);
printf("Enter time quantum: ");
scanf("%d", &time_quantum);
    // Input burst times for each process
    for (i = 0; i< n; i++) {
pid[i] = i + 1; // Assigning process IDs
printf("Enter burst time for process P%d: ", pid[i]);
scanf("%d", &burst_time[i]);
remaining_time[i] = burst_time[i]; // Initialize remaining time
    }
    // Round Robin scheduling
    while (completed < n) {
        for (i = 0; i< n; i++) {
            if (remaining_time[i] > 0) {
                if (remaining_time[i] >time_quantum) {
                    time += time_quantum; // Increment current time
remaining_time[i] -= time_quantum; // Decrease remaining time
                } else {
                    time += remaining_time[i]; // Increment time by remaining time
wait_time[i] = time - burst_time[i]; // Calculate waiting time
remaining_time[i] = 0; // Process is completed
                    completed++; // Increment completed process count
                }
            }
        }
    }
    // Calculate turnaround time
    for (i = 0; i< n; i++) {
turn_time[i] = burst_time[i] + wait_time[i];
total_wait_time += wait_time[i];
total_turn_time += turn_time[i];
    }
    // Print results
printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i< n; i++) {
printf("P%d\t%d\t\t%d\t\t%d\n", pid[i], burst_time[i], wait_time[i], turn_time[i]);
    }
    // Calculate average waiting time and turnaround time
    float avg_wait_time = (float)total_wait_time / n;
    float avg_turn_time = (float)total_turn_time / n;
printf("\nAverage Waiting Time: %.2f\n", avg_wait_time);
printf("Average Turnaround Time: %.2f\n", avg_turn_time);
    return 0;
}

