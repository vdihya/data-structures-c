#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int rear,front = -1;
char cqueue[MAX];
char dequeue();
void enqueue(char c);
void display();
int main()
{
    int choice;
    while(1)
    {
        printf("\n1: enqueue elements into the circular queue\n2: dequeue elements from the circular queue\n3: display the elements of the circular queue\n4: exit\nenter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                char element;
                printf("\ninput the character to be enqueued: ");
                scanf("\n%c",&element);
                enqueue(element);
            }break;
        case 2:
            {
                dequeue();
            }  break;
        case 3: display(); break;
        case 4: exit(0);
        default: printf("invalid choice: ");

        }
    }
}
void enqueue(char c)
{
    if((rear==MAX-1 && front==0) || front == rear+1)
    {
        printf("\nqueue is full");
        return;
    }
    if(front == -1)
    {
        front = 0;
    }
    rear = (rear+1)%MAX;
    cqueue[rear] = c;
}

char dequeue()
{
    if(front==-1)
    {
        printf("\nqueue is empty");
        return;
    }

    printf("%c",cqueue[front]);
    if(front==rear)
    {
        front = -1; rear =-1;
    }
    else
        front = (front+1)%MAX;
}
void display()
{
    int i;
    if(front==-1) printf("empty queue.");
    for(i=front+1;i!=rear;i=(i+1)%MAX)
        printf("%c",cqueue[i]);
    printf("%c",cqueue[i]);

}
