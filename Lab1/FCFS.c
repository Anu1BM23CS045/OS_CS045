#include<stdio.h>


int n,process[25],bt[25],wt[25],tat[25];

void calc_wt_tat();
void avg_wt_tat();

void main()
{
    printf("SJF Scheduling:\n");
    printf("Enter the number of processes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        process[i]=i;
        printf("Enter the burst time for process %d:\n",i);
        scanf("%d",&bt[i]);
    }
    calc_wt_tat();
    avg_wt_tat();
}

void calc_wt_tat()
{
   wt[0]=0;
   tat[0]=bt[0];
   printf("Process\twaiting time\tturn around time:\n");
   printf("0      \t%d           \t%d              \n",wt[0],tat[0]);
   for(int i=1;i<n;i++)
   {
    wt[i]=wt[i-1]+bt[i-1];
    tat[i]=wt[i]+bt[i];
    printf("%d     \t%d           \t%d              \n",process[i],wt[i],tat[i]);
   }
   
}

void avg_wt_tat()
{
    int wtavg=0,tatavg=bt[0];
    for(int i=1;i<n;i++)
   {
    wtavg=wtavg+wt[i];
    tatavg=tatavg+tat[i];
   }
   wtavg=wtavg/n;
   tatavg=tatavg/n;
   printf("Average waiting time:%d\nAverage turn around time:%d\n",wtavg,tatavg);
}
