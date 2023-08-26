#include <stdio.h>
#include <limits.h>
int main()
{

    int ttask,tmachine; // number of tasks , number of machines
    printf("\nEnter number of machines and tasks\n");
    scanf("%d%d", &tmachine, &ttask);

    /*
    Declare a 2d-array of sizetmachine x ttask
    Data should be in the following format :

    T1 T2 T3
    M1 | 140 | 20 | 60 |
    M2 | 100 | 100 | 70 |

    */
    int maxMin[tmachine][ttask];
    int tmp[tmachine][ttask];
    int makespan = 0;
    printf("\nEnter the  Data\n");
    for (int i = 0; i <tmachine; i++) 
        for (int j = 0; j < ttask; j++)
        {
            scanf("%d", &maxMin[i][j]);
            tmp[i][j] = maxMin[i][j];
        }

    // print  data
    printf("\tYou entered this-->\n");

    for (int i = 0; i <tmachine; i++)
    {
        for (int j = 0; j < ttask; j++)
            printf("%d ", maxMin[i][j]);
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
                if (maxMin[i][j] < minimum)
                {
                    minimum = maxMin[i][j];
                    pos = i;
                }
            }
            time[j] = minimum;
            machine[j] = pos;
        }

        // Now we find task with maximum time

        int maximum = INT_MIN;
        int pos = -1;

        for (int j = 0; j < ttask; j++)
        {
            if (time[j] > maximum && time[j] != INT_MAX)
            {
                maximum = time[j];
                pos = j;
            }
        }

        resultTask[++ptr] = pos;
        resultMachine[ptr] = machine[pos];
        resultTime[ptr] = tmp[machine[pos]][pos];
        if (maximum > makespan)
            makespan = maximum;
        // resetting states

        for (int i = 0; i <tmachine; i++)
        {
            for (int j = 0; j < ttask; j++)
            {
                if (j == resultTask[ptr])
                    maxMin[i][j] = INT_MAX;
                else if (i == resultMachine[ptr] && maxMin[i][j] != INT_MAX)
                    maxMin[i][j] += maximum;
                else
                    continue;
            }
        }
    }

    // printing answer
    printf("\nScheduled Task are :\n");
    for (int i = 0; i < ttask; i++)
    {
        printf("\nTask %d Runs on Machine %d with Time %d units\n", resultTask[i] + 1, resultMachine[i] + 1, resultTime[i]);
    }

    printf("\nTotal elapsed time : %d units\n", makespan);
    return 0;
}