#include <stdio.h>

// int main()
// {   // procs bt at
//     //    1  6  2
//     //    2  2  5
//     //    3  8  1
//     //    4  3  0
//     //    5  4  4

//     int bt[10] = {0}, at[10] = {0}, tat[10] = {0}, wt[10] = {0}, ct[10] = {0};
//     int n, sum = 0;
//     float totalTAT_025 = 0, totalWT = 0;

//     printf("Enter number of processes	");
//     scanf("%d", &n);

//     printf("Enter arrival time and burst time for each process\n\n");

//     for (int i = 0; i < n; i++)
//     {

//         printf("Arrival time of process[%d]	", i + 1);
//         scanf("%d", &at[i]);

//         printf("Burst time of process[%d]	", i + 1);
//         scanf("%d", &bt[i]);

//         printf("\n");
//     }

//     // calculate completion time of processes

//     for (int j = 0; j < n; j++)
//     {
//         sum += bt[j];
//         ct[j] += sum;
//     }

//     // calculate turnaround time and waiting times

//     for (int k = 0; k < n; k++)
//     {
//         tat[k] = ct[k] - at[k];
//         totalTAT_025 += tat[k];
//     }

//     for (int k = 0; k < n; k++)
//     {
//         wt[k] = tat[k] - bt[k];
//         totalWT += wt[k];
//     }

//     printf("Solution: \n\n");
//     printf("P#\t AT\t BT\t CT\t TAT\t WT\t\n\n");

//     for (int i = 0; i < n; i++)
//     {
//         printf("P%d\t %d\t %d\t %d\t %d\t %d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
//     }

//     printf("\n\nAverage Turnaround Time = %f\n", totalTAT_025 / n);
//     printf("Average WT = %f\n\n", totalWT / n);
//    return 0;
// }
#define NUM_PROCESSES 5
 struct process {
    int id;
    int arrival_time;
    int burst_time;
};
int main() {
    struct process processes[NUM_PROCESSES] = {
        {1, 0, 8},
        {2, 1, 4},
        {3, 2, 9},
        {4, 3, 5},
        {5, 4, 2}
    }; // ID, AT, BT

    int completion_time = 0;
    int waiting_time[NUM_PROCESSES];
    int turnaround_time[NUM_PROCESSES];

    for (int i = 0; i < NUM_PROCESSES; i++) {
        if (completion_time < processes[i].arrival_time) {
            completion_time = processes[i].arrival_time;
        }
        waiting_time[i] = completion_time - processes[i].arrival_time;
        completion_time += processes[i].burst_time;
        turnaround_time[i] = completion_time - processes[i].arrival_time;
        printf("Completion time for process %d: %d\n", processes[i].id, completion_time);
    }

    for (int i = 0; i < NUM_PROCESSES; i++) {
        printf("Process %d: Waiting time = %d, Turnaround time = %d\n", processes[i].id, waiting_time[i], turnaround_time[i]);
    }

    return 0;
}
