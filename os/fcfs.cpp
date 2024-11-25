#include <stdio.h>
int main() {
    int n, i;
    int burstTime[20], waitingTime[20], turnaroundTime[20];
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
printf("Enter the number of processes: ");
scanf("%d", &n);
    // Input burst times for each process
printf("Enter burst time for each process:\n");
    for (i = 0; i< n; i++) {
printf("Process %d: ", i + 1);
scanf("%d", &burstTime[i]);
    }
    // Waiting time for first process is 0
waitingTime[0] = 0;
    // Calculate waiting time for each process
    for (i = 1; i< n; i++) {
waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    }
    // Calculate turnaround time for each process
    for (i = 0; i< n; i++) {
turnaroundTime[i] = waitingTime[i] + burstTime[i];
totalWaitingTime += waitingTime[i];
totalTurnaroundTime += turnaroundTime[i];
    }
    // Display process details
printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i< n; i++) {
printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burstTime[i], waitingTime[i], turnaroundTime[i]);
    }
    // Calculate and display average waiting and turnaround times
printf("\nAverage Waiting Time: %.2f", (float)totalWaitingTime / n);
printf("\nAverage Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);
    return 0;
}

