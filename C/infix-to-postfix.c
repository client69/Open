#define SIZE 50
#include <stdio.h>

char s[SIZE];
int top = -1;

void RemoveSpaces(char *source)
{
    char *i = source;
    char *j = source;
    while (*j != 0)
    {
        *i = *j++;
        if (*i != ' ')
            i++;
    }
    *i = 0;
}

void push(char elem)
{
    s[++top] = elem;
}

char pop()
{
    return (s[top--]);
}

int pr(char elem)
{
    switch (elem)
    {
    case '#':
        return 0;
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    }
}
int isnum(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}
int ischar(char c){
    if((c>='0'&&c<='9')||(c>='a'&&c<='z')||(c>='A'&&c<='Z'))
    return 1;
    else return 0;
}
void infix_to_postfix(char *infix, char *postfix)
{
    char ch, elem;
    int i = 0, k = 0;

    RemoveSpaces(infix);
    push('#');

    while ((ch = infix[i++]) != '\n')
    {
        if (ch == '(')
            push(ch);
        else if (ischar(ch))
            postfix[k++] = ch;
        else if (ch == ')')
        {
            while (s[top] != '(')
                postfix[k++] = pop();
            elem = pop();
        }
        else
        {
            while (pr(s[top]) >= pr(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    while (s[top] != '#')
        postfix[k++] = pop();

    postfix[k] = 0;
}

void main()
{
    char infx[50], pofx[50];
    printf("\nInput the infix expression: ");
    fgets(infx, 50, stdin);

    infix_to_postfix(infx, pofx);

    printf("\nPostfix Expression: %s", pofx);
}