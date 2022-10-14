/*
QUEUE : ADT using Array of integer
[MARKS: 15]

Prob 1: Implement the abstract data type of queue

- enqueue

- dequeue

- peek : CHECK THE WHO IS AT THE FRONT

-isFull

-IsEmpty


Code by : Arnab Chakraborty
Github : https://github.com/ArnabC27
*/

#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int front, rear, cap;
    int *arr;
};
typedef struct Queue queue;

queue* createQueue(int cap)
{
    queue* q = (queue*)malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    q->cap = cap;
    q->arr = (int*)malloc(q->cap * sizeof(int));
    return q;
}

int isFull(queue* q)
{
    return q->rear == q->cap - 1;
}

int isEmpty(queue* q)
{
    return q->front == -1 || q->front > q->rear;
}

void enqueue(queue* q, int x)
{
    if(isFull(q))
    {
        printf("Queue Overflow!!!\n");
        return;
    }
    else
    {
        if(q->front == -1)
            q->front = 0;
        q->rear = q->rear + 1;
        q->arr[q->rear] = x;
    }
    printf("%d is Enqueued to the Queue\n", x);
}

int dequeue(queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue Underflow!!!\n");
        return -1;
    }
    return q->arr[q->front++];
}

void printQueue(queue* q)
{
    int i, j;
    if(isEmpty(q))
    {
        printf("\nQueue is Empty!!!\n");
        return;
    }
    else
    {
        for(i = 0; i < q->front; i++)
            printf("|__|\n");
        for(j = q->front; j <= q->rear; j++)
        {
            if(j == q->front && j == q->rear)
                printf("%d\t<- FRONT and REAR\n", q->arr[j]);
            else if(j == q->front)
                printf("%d\t<- FRONT\n", q->arr[j]);
            else if(j == q->rear)
                printf("%d\t<- REAR\n", q->arr[j]);
            else
                printf("%d\n", q->arr[j]);
        }
    }
}

int peek(queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue is Empty!!!\n");
        return -1;
    }
    return q->arr[q->front];
}

int main()
{
    printf("----------QUEUE IMPLEMENTATION----------\n");
    int cap, ch, x, cont = 1, a;
    printf("Enter maximum capacity of the Queue you want to create : ");
    scanf("%d", &cap);
    if(cap >= 1)
    {
        queue* q = createQueue(cap);

        while(cont == 1)
        {
            printf("\nOperations on Queue that can be performed here :\n");
            printf("1. Check if Queue is Empty\n");
            printf("2. Check if Queue is Full\n");
            printf("3. Insert an element into the Queue\n");
            printf("4. Delete an element from the Queue\n");
            printf("5. Print the whole Queue\n");
            printf("6. Print the element at the Front of the Queue\n");
            printf("7. Re-initialize the Queue\n");
            printf("Enter your choice(1-7) : ");
            scanf("%d", &ch);
            printf("\n");

            switch(ch)
            {
                case 1 :
                    if(isEmpty(q))
                        printf("Queue is Empty!!!\n");
                    else
                        printf("Queue is Not Empty!!!\n");
                    break;
                case 2 :
                    if(isFull(q))
                        printf("Queue is Full!!!\n");
                    else
                        printf("Queue is Not Full!!!\n");
                    break;
                case 3 :
                    printf("Enter an Integer you want to Insert into the Queue : ");
                    scanf("%d", &x);
                    enqueue(q, x);
                    break;
                case 4 :
                    a = dequeue(q);
                    if(a != -1)
                        printf("Element deleted : %d\n", a);
                    break;
                case 5 :
                    printf("Queue Status :\n");
                    printQueue(q);
                    break;
                case 6 :
                    printf("Element present at Front of Queue : %d\n", peek(q));
                    break;
                case 7 :
                    q = createQueue(cap);
                    printf("Queue is Re-intialized!!!\n");
                    break;
                default :
                    printf("Invalid Choice!!!\n");
            }

            printf("Do you want to Continue? (1-YES / 0-NO) : ");
            scanf("%d", &cont);
        }
    }
    else
        printf("Queue capacity should be greater than 0!!!\n");
}