#include<stdio.h>
char stack[50];
int top = -1;

void push(char ch) 
{
	stack[++top] = ch;
}

char pop()
{
	return(stack[top--]);
}

int prcd(char ch)
{
	int p;
	switch(ch)
	{
		case '$':
		case '^': 
			p = 3;
			break;
		case '*':
		case '/':
			p = 2;
			break;
		case '+':
		case '-':
			p = 1;
			break;
		case '(':
			p = -1;
			break;
	}
	return p;
}

void conversion(char infix[],char postfix[])
{
	int i = 0, p = 0;
	char ch;
	while((ch=infix[i])!='\0')
	{
		switch(ch)
		{
			default:
				postfix[p++] = ch;
				break;
			case '(':
				push(ch);
				break;
			case ')':
				while(top!=-1&&stack[top]!='(')
				postfix[p++] = pop();
				pop();
				break;
			case '*':
			case '/':
			case '+':
			case '-':
				while(top!=-1&&prcd(stack[top])>=prcd(ch))
					postfix[p++] = pop();
				push(ch);
				break;
			case '$':
			case '^':
				while(top!=-1&&prcd(stack[top])>prcd(ch))
					postfix[p++] = pop();
				push(ch);
				break;
			}
		i++;
		}
		while(top!=-1)
		postfix[p++] =pop();
		postfix[p] = '\0';
	}
	
	int main()
	{
		char infix[50], postfix[50];
		printf("Enter valid infix expression:");
		scanf("%s",infix);
		conversion(infix,postfix);
		printf("Postfix expression = %s \n",postfix);
	}
					


