#include<stdio.h>
#include<stdlib.h>
#define N 25

void banker(int n,int m,int alloc[n][m],int max[n][m],int ava[m])
{
  int seq[n];
  int finish[n];
  for(int i=0;i<n;i++)
  {
    finish[i]=0;
  }
  int need[n][m];
  int sat=-1;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
        need[i][j]=max[i][j]-alloc[i][j];
    }      
  }
  int count =0;
  while(count<n)
  {
   
    for(int i=0;i<n;i++)
    {
        if(finish[i]==0)
        {
            sat=1;
            for(int j=0;j<m;j++)
            {
                
                if(need[i][j]>ava[j])
                {
                    sat=0;
                    break;
                }
            }
            if(sat==1)
            {
                printf("P%d is visited (",i);
               for(int j=0;j<m;j++)
               {
                ava[j]=ava[j]+alloc[i][j];
                printf("%d ",ava[j]);
               }
               printf(")\n");
                seq[count++]=i;
                finish[i]=1;
                
                
                
            }
        }
    }

  }
  printf("Safe state\n");
  printf("The safe sequence--(");
  for(int i=0;i<n;i++)
  {
    printf("P%d ",seq[i]);
  }
  printf(")\n");

  printf("Process\tAllocation\tMax   \tNeed  \n");
  for(int i=0;i<n;i++)
  {
  printf("P%d    \t",i);
  for(int j=0;j<m;j++)
  {
    printf("%d ",alloc[i][j]);
  }
  printf("    \t");
  for(int j=0;j<m;j++)  
  {
    printf("%d ",max[i][j]);
  }
  printf("\t");
  for(int j=0;j<m;j++)
  {
    printf("%d ",need[i][j]);
  }
  printf("\n");
  }
    
}

void  main()
{
    int n,m;
    printf("Enter number of proceses:");
    scanf("%d",&n);
    printf("Enter number of resources:");
    scanf("%d",&m);
    int alloc[n][m],max[n][m],ava[m];
    for(int i=0;i<n;i++)
    {
        printf("Enter details for P%d\n",i);
        printf("Enter allocation -");
        for(int j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
        printf("Enter max -");
        for(int j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
        printf("enter available resources --");
        for(int j=0;j<m;j++)
        {
            scanf("%d",&ava[j]);
        }
        banker(n,m,alloc,max,ava);
    
}
