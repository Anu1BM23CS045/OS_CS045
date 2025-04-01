#include <stdio.h>
#define MAX 5

int mutex = 1, full = 0, empty = MAX, x; // mutex 1 is availabe

void wait(int *s)
{
    --(*s);
}

void signal(int *s)
{
    ++(*s);
}

void producer()
{
    if (empty != 0)
    {
        wait(&empty);
        wait(&mutex);
        x++;
        printf("Producer has produced:Item %d\n", x);
        signal(&full);
        signal(&mutex);
    }
    else
    {
        printf("Buffer full");
    }
}

void consumer()
{
    if (full != 0)
    {
        wait(&full);
        wait(&mutex);
        printf("Consumer has consumed:Item %d\n", x);
        x--;
        signal(&empty);
        signal(&mutex);
    }
    else
    {
        printf("Buffer empty");
    }    
}

void main()
{
    int ch;
    printf("1.Producer\t2.Consumer\t3.Exit\n");
    do
    {
        printf("Enter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            producer();
            break;
        case 2:
            consumer();
            break;
        case 3:
            printf("Exiting");
        }

    } while (ch != 3);
}
