#include <stdio.h>
int c = 0;
void remaining(int n, int bt[], int time, int pr[], int TAT[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (bt[i] > time)
        {
            bt[i] = bt[i] - time;
            printf("%d\t", pr[i]);
        }
        else if (bt[i] != 0)
        {
            bt[i] = 0;
            TAT[i] = bt[i] + c * 3;
            printf("%d\t", pr[i]);
        }
        else
        {
            bt[i] = 0;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (bt[i] != 0)
        {
            c++;
            remaining(n, bt, time, pr, TAT);
        }
    }
}
int main()
{
    int pr[10], bt[10], TAT[10], remaning[10], totaltat = 0, avgtat, n, i, time = 3;
    printf("Enter the number of process you are executing\n");
    scanf("%d", &n);
    printf("Enter your process sequence\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pr[i]);
    }
    printf("Enter the bust time of the process\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    for (i = 0; i < n; i++)
    {
        printf("%d\t", pr[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", bt[i]);
    }
    printf("\n");
    printf("sequence of process executed : \n");
    remaining(n, bt, time, pr, TAT);
    for (i = 0; i < n; i++)
    {
        totaltat = totaltat+TAT[i];
    }
    avgtat = totaltat / n;
    printf("\nAverage turn around time = %d\n", avgtat);
    return 0;
}