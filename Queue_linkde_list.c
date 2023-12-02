/*
In queue, unlike stacks, Queue has 2 open ends.
from one you incert and from other it deletes.
we can emplement it as perority Queue
in Perority Queue, We can put perority task in the end of the Queue.*/
/*to get rare to rare=(rare+1)%max*/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define max1 5
int rare = -1, front = -1;
int queue[max1];
void en_queue(int n)
{
    if ((rare == max1 - 1 && front == 0) || (front > 0 && rare == front - 1))
    {
        printf("Over flow");
    }

    else
    {
        if (front == -1)
        {
            rare = front = 0;
            queue[rare] = n;
        }

        else
        {
            rare = (rare + 1) % max1;
            queue[rare] = n;
        }
    }
}
void del_queue()
{
    if (front == -1)
    {
        printf("Under flow");
    }
    else
    {
        if (rare == front)
        {
            printf("You have deleted %d\n", queue[front]);
            rare = front = -1;
        }

        else
        {
            printf("You have deleted %d\n", queue[front]);
            front = (front + 1) % max1;
        }
    }
}
void display()
{
    if (rare == -1)
    {
        printf("Under Flow");
    }
    else
    {
        int i = front;
        while (i != rare)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % max1;
        }
        printf("%d ", queue[i]);
    }
}
int main()
{
    int choice;
    int x = 1, data;
    while (x == 1)
    {
        printf("\nChoose any one\npress 1 to incert\npress 2 to delete\npress 3 to travers\npress 4 to exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            en_queue(data);
            break;
        case 2:
            del_queue();
            break;
        case 3:
            display();
            break;
        case 4:
            x = 0;
            break;
        default:
            printf("Invalid input\n");
        }
    }
}
