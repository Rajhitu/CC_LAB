#include <stdio.h>
#include <limits.h>
int main()
{
   /*
    Declare a 2d-array of sizetmachine x ttask
    Data should be in the following format :

         nn T1 T2 T3
    M1 | 140 | 20 | 60 |
    M2 | 100 | 100 | 70 |

    */
    int ttask,tmachine; // number of tasks , number of machines
    printf("\nEnter number of machines and tasks\n");
    scanf(" %d %d", &tmachine, &ttask);

    int minMin[tmachine][ttask];
    int tmp[tmachine][ttask];
    int makespan = 0; 
    printf("\nFill Data\n");
    for (int i = 0; i <tmachine; i++)
        for (int j = 0; j < ttask; j++)
        {
            scanf("%d", &minMin[i][j]);
            tmp[i][j] = minMin[i][j];
        }

    //printing table
    printf("\nThe original Data\n");

    for (int i = 0; i <tmachine; i++)
    {
        for (int j = 0; j < ttask; j++)
            printf("%d ", minMin[i][j]);
        printf("\n");
    }

    // This array will hold the answer

    int resultTask[ttask];
    int resultMachine[ttask];
    int resultTime[ttask];
    int ptr = -1; // Indicates if result set is full or not

    while (ptr < ttask - 1)
    {
        int time[ttask], machine[ttask]; // stores minimum time w.r.t machine of each task
        for (int j = 0; j < ttask; j++)
        {
            int minimum = INT_MAX;
            int pos = -1;
            for (int i = 0; i <tmachine; i++)
            {
                if (minMin[i][j] < minimum)
                {
                    minimum = minMin[i][j];
                    pos = i;
                }
            }
            time[j] = minimum;
            machine[j] = pos;
        }

        // Now we find task with minimum time

        int minimum = INT_MAX;
        int pos = -1;

        for (int j = 0; j < ttask; j++)
        {
            if (time[j] < minimum)
            {
                minimum = time[j];
                pos = j;
            }
        }

        resultTask[++ptr] = pos;
        resultMachine[ptr] = machine[pos];
        resultTime[ptr] = tmp[machine[pos]][pos];
        if (minimum > makespan)
            makespan = minimum;
        // resetting states

        for (int i = 0; i <tmachine; i++)
        {
            for (int j = 0; j < ttask; j++)
            {
                if (j == resultTask[ptr])
                    minMin[i][j] = INT_MAX;
                else if (i == resultMachine[ptr] && minMin[i][j] != INT_MAX)
                    minMin[i][j] += minimum;
                else
                    continue;
            }
        }
    }

    // printing answer
    printf("\nScheduled Task are :\n");
    for (int i = 0; i < ttask; i++)
    {
        printf("\nTask selectd : %d and Machine : %d --> Time :%d units\n", resultTask[i] + 1, resultMachine[i] + 1, resultTime[i]);
    }

    printf("\n minimum time to  : %d units\n", makespan);
    return 0;
}