/*============================================================================

Title:   Expression Evaluuation with implementation of Stack using Array

============================================================================*/

#include<iostream>
#include<string.h>
#include<bits/stdc++.h>

using namespace std;
class ExpEva
{

	int max=10;
	int st[10];
	int top;

public:

	ExpEva()
	{
		top=-1;
	}

	int isempty()
	{
		if(top==-1)
		{
			return 1;
		}
		else
            return 0;
	}

	int isfull()
	{
		if(top==max-1)
		{
			return 1;
		}
		else
            return 0;
	}

    void push(int data)
	{
		if(isfull()==0)
		{
			top++;
			st[top]=data;
		}
		else
        {
			cout<<"Stack is full!"<<endl;;
		}
	}

    int pop()
	{
		int data;

		if(isempty()==0)
		{
            data=st[top];
			top--;
			return data;
		}
		else
        {
			cout<<"Stack is empty!"<<endl;
			return -1;
		}

	}

	int calc(int s1,int s2,char ch)
	{
		if(ch=='*')
        {
            return s1*s2;
        }
        if(ch=='/')
        {
            return s1/s2;
        }
        if(ch=='+')
        {
            return s1+s2;
        }
        if(ch=='-')
        {
            return s1-s2;
        }
	}
};
int main()
{
	ExpEva s;
	int val,s1,s2,result;
	char postfix[30];

        cout<<"-----POSTFIX TO INFIX-----\n\n"<<endl;
		cout<<"Enter postfix expression: ";
		cin>>postfix;

		for(int i=0;i<strlen(postfix);i++)
		{
			if(isdigit(postfix[i]))
			{
				val=postfix[i]-'0';
				s.push(val);

			}
			else if(postfix[i]=='*'||postfix[i]=='/'||postfix[i]=='+'||postfix[i]=='-')
			{
				s1=s.pop();
				s2=s.pop();
				result=s.calc(s2,s1,postfix[i]);
				s.push(result);
			}
		}
		cout<<"Infix Expression: "<<s.pop();

	return 0;
}
