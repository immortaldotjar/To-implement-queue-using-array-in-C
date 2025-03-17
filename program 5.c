#include <stdio.h>
#include <stdlib.h>

// creating global variables for queue
int front = -1,rear = -1; 

void Insert(int Msize, int Q[]) 
{
    //declaring variables
    int i;

    //checking overflow condition
    if (rear == Msize - 1) 
    {
        printf("Queue OVERFLOW!\n");
    } 
    else 
    {
        if(front == -1)
        {
            front = 0;
        }
        //taking inputs
        printf("Enter the value: ");
        scanf("%d", &i);
        rear++;

        //inserting value in queue
        Q[rear] = i;
    }
}

void Delete(int Q[]) 
{
    //checking underflow condition
    if (front == -1) 
    {
        printf("Queue UNDERFLOW!\n");
    } 
    else 
    {
        //removing element from queue
        printf("Deleted element: %d\n", Q[front]);
        front++;
        if(front > rear)
        {
            front = rear = -1;
        }
    }
}

void Display(int Q[])
{
    //declaring variable
    int i;
    if(front == -1)
    {
        printf("Queue UNDERFLOW!\n");
    }
    else
    {
        //displaying queue
        printf("[ ");
        for(i = front;i <= rear;i++)
        {
            printf("%d,",Q[i]);
        }
        printf("]\n");
    }
}

int main() 
{

    int Msize;
    //taking subscript value from user
    printf("Enter the size of Queue: ");
    scanf("%d", &Msize);

    int Q[Msize], ch;
    char op;

    //infinite loop
    while (1) 
    {
        printf("\nDo you want to enter the menu? [Y/n]): ");
        scanf(" %c",&op); 

        //checking condition for YES
        if (op == 'Y' || op == 'y') 
        {
            printf("Menu:\n1. Insert an element\n2. Delete an element\n3. Display the Queue\n4. Exit\nChoose an option: ");
            scanf("%d", &ch);
            
            //cases
            switch (ch) 
            {
                case 1:
                    Insert(Msize, Q);
                    break;
                case 2:
                    Delete(Q);
                    break;
                case 3:
                    Display(Q);
                    break;
                case 4:
                    exit(0);
                default:
                    printf("Entered wrong choice!\n");
                    break;
            }
        } 
        else 
        {
            printf("Exiting...\n");
            break;
        }
    }

    return 0;
}
