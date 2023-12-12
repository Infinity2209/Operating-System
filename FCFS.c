#include<stdio.h>
int main()
{
    int pr[10],bt[10],wt[10],TAT[10],totalwt=0,totaltat=0,avgwt,avgtat,n,i;
    printf("Enter the number of process you are executing\n");
    scanf("%d",&n);
    printf("Enter your process sequence\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&pr[i]);
    }
    printf("Enter the bust time of the process\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&bt[i]);
    }
    wt[0]=0;
    for ( i = 1; i < n; i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        totalwt=totalwt + wt[i];
    }
    avgwt=totalwt/n;
    for ( i = 0; i < n; i++)
    {
        printf("%d\t", pr[i]);
    }
    printf("\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d\t", bt[i]);
    }
    printf("\n");
    printf("Average waiting time of the proceses = %d\n",avgwt);
    for ( i = 0; i < n; i++)
    {
        TAT[i]=wt[i]+bt[i];
        totaltat=totaltat + TAT[i];
    }
    avgtat=totaltat/n;
    printf("Average turn around time of the proceses = %d\n",avgtat);

    return 0;
}