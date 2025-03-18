#include <stdio.h>

struct process
{
    int pno[25], bt[25], wt[25], tat[25];
    int n;
};
typedef struct process proc;

proc sysp, userp;

void cal_wt_tat();
void avg_wt_tat();

void main()
{
    printf("System process:\n");
    printf("Enter number of system processes:");
    scanf("%d", &sysp.n);
    for (int i = 0; i < sysp.n; i++)
    {
        sysp.pno[i] = i;
        printf("\nEnter burst time of process %d:", i);
        scanf("%d", &sysp.bt[i]);
    }
    printf("User process:\n");
    printf("Enter number of user processes:");
    scanf("%d", &userp.n);
    for (int i = 0; i < userp.n; i++)
    {
        userp.pno[i] = i + sysp.n;
        printf("\nEnter burst time of process %d:", (i + sysp.n));
        scanf("%d", &userp.bt[i]);
    }

    cal_wt_tat();
    avg_wt_tat();
}

void cal_wt_tat()
{
    int i;
    printf("High priority:System processes\n");
    sysp.wt[0] = 0;
    sysp.tat[0] = sysp.bt[0];
    printf("Process\tburst time\twaiting time\tturn around time:\n");
    printf("0      \t%d           \t%d           \t%d              \n",sysp.bt[0],sysp.wt[0], sysp.tat[0]);
    for (i = 1; i < sysp.n; i++)
    {
        sysp.wt[i] = sysp.wt[i - 1] + sysp.bt[i - 1];
        sysp.tat[i] = sysp.wt[i] + sysp.bt[i];
        printf("%d      \t%d           \t%d           \t%d              \n",sysp.pno[i],sysp.bt[i],sysp.wt[i], sysp.tat[i]);
    }
    printf("Low priority:User processes\n");
    userp.wt[0] = sysp.wt[i-1]+sysp.bt[i-1];
    userp.tat[0] = userp.bt[0]+userp.wt[0];
    printf("%d      \t%d           \t%d           \t%d              \n",userp.pno[0],userp.bt[0],userp.wt[0], userp.tat[0]);
    for (i = 1; i < userp.n; i++)
    {
        userp.wt[i] = userp.wt[i - 1] + userp.bt[i - 1];
        userp.tat[i] = userp.wt[i] + userp.bt[i];
        printf("%d      \t%d           \t%d           \t%d              \n",userp.pno[i],userp.bt[i],userp.wt[i], userp.tat[i]);
    }
}

void avg_wt_tat()
{
    float wtavg=0,tatavg=sysp.bt[0];
    for(int i=1;i<sysp.n;i++)
    {
        wtavg=sysp.wt[i]+wtavg;
        tatavg=sysp.tat[i]+tatavg;
    }
    for(int i=0;i<userp.n;i++)
    {
        wtavg=userp.wt[i]+wtavg;
        tatavg=userp.tat[i]+tatavg;
    }
    wtavg=wtavg/(sysp.n+userp.n);
    tatavg=tatavg/(sysp.n+userp.n);
    printf("\nAverage waiting time:%f\nAverage Turn around time:%f",wtavg,tatavg);
}
