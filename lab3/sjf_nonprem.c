#include <stdio.h>
#include <conio.h>


// Processes Id	Burst Time	  Waiting Time	Turn Around Time
//       1	       6	3	9
//       2	       8	16	25
//       3	       7	9	16
//       4	       3	0	3
struct process
{
    int process_id;
    int arrival_time;
    int burst_time;
};

int main()
{
    int i, j, n, total = 0;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    for (i = 0; i < n; i++)
    {
        p[i].process_id = i + 1;
        printf("Enter the arrival time of process %d: ", p[i].process_id);
        scanf("%d", &p[i].arrival_time);
        printf("Enter the burst time of process %d: ", p[i].process_id);
        scanf("%d", &p[i].burst_time);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (p[i].burst_time < p[j].burst_time)
            {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    total = 0;
    for (i = 0; i < n; i++)
    {
        total += p[i].burst_time;
        avg_waiting_time += total - p[i].arrival_time - p[i].burst_time;
        avg_turnaround_time += total - p[i].arrival_time;
    }
    avg_waiting_time = avg_waiting_time / n;
    avg_turnaround_time = avg_turnaround_time / n;
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].process_id, p[i].arrival_time, p[i].burst_time, total - p[i].arrival_time - p[i].burst_time, total - p[i].arrival_time);
    }
    printf("\nAverage Waiting Time: %f\n", avg_waiting_time);
    printf("Average Turnaround Time: %f\n", avg_turnaround_time);
    return 0;
}
