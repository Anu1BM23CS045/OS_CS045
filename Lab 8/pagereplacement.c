
#include<stdio.h>
#include<stdlib.h>

void fifo(int ref[],int n,int fnum);
void lru(int ref[],int n,int fnum);
// void opt(int ref[],int n,int fnum);
int checkifthere(int refnum,int frame[],int fnum);
void display(int frame[],int fnum)
{
    for(int j=0;j<fnum;j++)
    {
        printf("%d ",frame[j]);
    }
    printf("\n"); 
}

void main()
{
    int n,fnum;
    printf("Enter the number of frames:");
    scanf("%d",&fnum);
    printf("Enter the length of reference string:");
    scanf("%d",&n);
    int ref[n];
    printf("Enter the refernce string:");
    for(int i=0;i<n;i++)
    {
      scanf("%d",&ref[i]);
    }
    fifo(ref,n,fnum);
    lru(ref,n,fnum);
    // opt(ref,n,fnum);
}


int checkifthere(int refnum,int frame[],int fnum)
{
    
        for(int j=0;j<fnum;j++)
        {
            if(refnum==frame[j])
            {
              return 1;
            }
        }
        return 0;   
}


void fifo(int ref[],int n,int fnum)
{
    printf("FIFO Page Replacement Process:\n");
    int frame[fnum];
    for(int i=0;i<fnum;i++)
    {
        frame[i]=-1;

    }
    int front=0,rear=-1,pgfault=0;
    
    for(int i=0;i<n;i++)
    {
        int isthere=checkifthere(ref[i],frame,fnum);
        if(isthere==1)
        {
          continue;
        }
        //insert
        
        if(rear<fnum-1)
        {
            rear++;
            frame[rear]=ref[i];
        }
        else{
            frame[front]=ref[i];
            front=(front+1)%fnum;
        }
        pgfault++;
        printf("PF No. %d:",pgfault);
        for(int j=0;j<fnum;j++)
        {
            printf("%d ",frame[j]);
        }
        printf("\n");
    }
}

void lru(int ref[],int n,int fnum)
{
    printf("LRU Page Replacement Process:\n");
    int frame[fnum],pgfault=0;
    for(int i=0;i<fnum;i++)
    {
        frame[i]=-1;

    }
    int rear=-1;
    for(int i=0;i<n;i++)
    {
       
        int isthere=checkifthere(ref[i],frame,fnum);
        if(isthere==1)
        {
          continue;
        }
        //insert
        pgfault++;
        if(rear<fnum-1)
        {
           rear++;
           frame[rear]=ref[i]; 
        }
        else{
        int count=0,j=i-1;
        do
        {
            for(int k=0;k<fnum;k++)
            {
                if(ref[j]==frame[k])
                      count++;
            }
            j--;

        }while(count<fnum && j>=0);
        if(count==fnum)
        {
           frame[j]=ref[i]; 
        }
    }
    printf("PF No. %d",pgfault);
    display(frame,fnum);
        
    } 
}
