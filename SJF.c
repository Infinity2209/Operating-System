#include<stdio.h>

int main()
{
    int pr[100], bt[100], wt[100], TAT[100], totalwt=0, totaltat=0, avgwt, avgtat, n, i, temp1, temp2, j;
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
    
    for (i = 0; i < n; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if (bt[i] > bt[j])
            {
                temp1=bt[i];
                temp2=pr[i];
                bt[i]=bt[j];
                pr[i]=pr[j];
                bt[j]=temp1;
                pr[j]=temp2;
            }
            
        }
        
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