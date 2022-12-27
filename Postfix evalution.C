#include<stdio.h>
#include<math.h>
#define max 100
int stack[max];
int top=-1;
void push(int val)
{
	stack[++top]=val;
}
int pop()
{
	int temp;
	temp=stack[top];
	top--;
	return temp;
}
int posteval(char s[max])
{
	int i,a,b;
	for(i=0;i<s[i]!='\0';i++)
	{
	  if(s[i]>='0'&&s[i]<='9')
	  push(s[i]-'0');
	  else
	  {
	  	b=pop();
	  	a=pop();
	  	switch(s[i])
	  	{
	  	 case '+':
		   push(a+b);
		   break;
		 case '-':
		   push(a-b);
		   break;
		 case '*':
		   push(a*b);
		   break;
		 case '/':
		   push(a/b);
		   break;
		 case '%':
		   push(a%b);
		   break;
		 case '^':
		   push(pow(a,b));
		   break;   	
		}
	  }
	}
	return stack[top];
}
int main()
{
	char s[max];
	printf("Enter a postfix expression:");
	gets(s);
	printf("Final Result: %d\n",posteval(s));
	return 0;
}
