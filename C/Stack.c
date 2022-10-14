/*
Note: Write the program with user input as menu driven program.

1.  Implement ADT of stack using  ARRAY  with user define data type stack (structure) [Marks: 10]

            - Push, Pop and so on as you feel best

Code by : Arnab Chakraborty
Github : https://github.com/ArnabC27
*/

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int cap;
    int* arr;
};
typedef struct Stack stack;

stack* createStack(int cap)
{
    stack* s = (stack*)malloc(sizeof(stack));
    s->cap = cap;
    s->top = -1;
    s->arr = (int*)malloc(s->cap * sizeof(int));
    return s;
}

int isFull(stack* s)
{
    return s->top == s->cap-1;
}

int isEmpty(stack* s)
{
    return s->top == -1;
}

void push(stack* s, int x)
{
    if(isFull(s))
    {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = x;
    printf("%d pushed into the Stack\n", x);
}

int pop(stack* s)
{
    if(isEmpty(s))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

void printStack(stack* s)
{
    int i;
    if(isEmpty(s))
    {
        printf("Stack is Empty\n");
        return;
    }
    else
    {
        for(i = s->top; i >= 0; i--)
        {
            if(i == s->top)
                printf("%d  <- TOP\n", s->arr[i]);
            else
                printf("%d\n", s->arr[i]);
        }
    }
}

int main()
{
    printf("----------STACK IMPLEMENTATION----------\n");
    int cap, ch, x, cont = 1, a;
    printf("Enter maximum capacity of the Stack you want to create : ");
    scanf("%d", &cap);
    if(cap >= 1)
    {
        stack* s = createStack(cap);

        while(cont == 1)
        {
            printf("\nOperations on Stack that can be performed here :\n");
            printf("1. Check if Stack is Empty\n");
            printf("2. Check if Stack is Full\n");
            printf("3. Push an element into the Stack\n");
            printf("4. Pop an element from the Stack\n");
            printf("5. Print the whole Stack\n");
            printf("Enter your choice(1-5) : ");
            scanf("%d", &ch);
            printf("\n");

            switch(ch)
            {
                case 1 :
                    if(isEmpty(s))
                        printf("Stack is Empty\n");
                    else
                        printf("Stack is not Empty\n");
                    break;
                case 2 :
                    if(isFull(s))
                        printf("Stack is Full\n");
                    else
                        printf("Stack is not Full\n");
                    break;
                case 3 :
                    printf("Enter an integer you want to Push into the Stack : ");
                    scanf("%d", &x);
                    push(s,x);
                    break;
                case 4 :
                    a = pop(s);
                    if(a != -1)
                        printf("Element popped : %d", a);
                    break;
                case 5 :
                    printf("Stack Status :\n");
                    printStack(s);
                    break;
                default :
                    printf("Wrong choice of option!!!\n");
            }

            printf("\nDo you want to continue? (1-YES / 0-NO) : ");
            scanf("%d", &cont);
        }
    }
    else
        printf("Stack capacity should be greater than 0!!!\n");
}