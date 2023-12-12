#include <stdio.h>

#define MAX_PAGES 10
#define INFINITY 999999

void initialize(int frame[], int n)
{
    for (int i = 0; i < n; i++)
    {
        frame[i] = -1;
    }
}

void printPages(int frame[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (frame[i] == -1)
        {
            printf(" _ ");
        }
        else
        {
            printf(" %d ", frame[i]);
        }
    }
    printf("\n");
}

int pageFault(int frame[], int n, int page, int referenceString[])
{
    for (int i = 0; i < n; i++)
    {
        if (frame[i] == page)
        {
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (frame[i] == -1)
        {
            frame[i] = page;
            return 1;
        }
    }

    int futureIndex[MAX_PAGES];
    for (int i = 0; i < n; i++)
    {
        futureIndex[i] = INFINITY;
        for (int j = page + 1; j < MAX_PAGES; j++)
        {
            if (referenceString[j] == frame[i])
            {
                futureIndex[i] = j;
                break;
            }
        }
    }

    int maxIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (futureIndex[i] > futureIndex[maxIndex])
        {
            maxIndex = i;
        }
    }

    frame[maxIndex] = page;
    return 1;
}

void optimal(int referenceString[], int n, int frameSize)
{
    int frame[frameSize];
    int pageFaultCount = 0;

    initialize(frame, frameSize);

    printf("Reference String: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", referenceString[i]);
    }
    printf("\n");

    printf("\nExecution:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Frames:");
        printPages(frame, frameSize);

        if (pageFault(frame, frameSize, referenceString[i], referenceString))
        {
            printf("Page Fault!\n");
            pageFaultCount++;
        }
        else
        {
            printf("No Page Fault\n");
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaultCount);
}

int main()
{
    int referenceString[] = {1, 3, 0, 3, 5, 6, 3, 4, 5, 6, 7, 8, 3, 7, 8, 9, 2};
    int n = sizeof(referenceString) / sizeof(referenceString[0]);
    int frameSize = 3;

    optimal(referenceString, n, frameSize);

    return 0;
}
