#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>
#define max 100
int stack[max];
int top=-1;
int isEmpty()
{
	if(top==-1)
	return 1;
	return 0;
}
int isFull()
{
	if(top==max-1)
	return 1;
	return 0;
}
void push(int val)
{
	if(top==max-1)
	{
		printf("Sorry bro you can not add element\n");
		return;
	}
	stack[++top]=val;
}
char pop()
{
	char temp;
	temp=stack[top];
	top--;
	return temp;
}
int priority(char c)
{
	if(c=='+'||c=='-')
	return 0;
	else if(c=='*'||c=='/'||c=='%')
	return 1;
	else if(c=='^')
	return 2;
	else
	return -1;
}
int main()
{
	char s[max],i;
	printf("Enter a infix expression:");
	gets(s);
	printf("Postfix expression:");
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]>='0'&&s[i]<='9'||s[i]>='a'&&s[i]<='z'||s[i]>='a'&&s[i]<='z')
		printf("%c",s[i]);
		else if(s[i]=='(')
		push(s[i]);
		else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^'||s[i]=='%')
		{
			while(!isEmpty()&&priority(s[i])<=priority(stack[top]))
			{
			  printf("%c",pop());	
			}
			push(s[i]);
		}
		else if(s[i]==')')
		{
			while(!isEmpty()&&stack[top]!='(')
			{
				printf("%c",pop());
			}
			if(!isEmpty())
			{
				top--;
			}
		}
	}
	while(!isEmpty())
	printf("%c",pop());
	return 0;
}
