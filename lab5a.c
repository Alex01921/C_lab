#include<stdio.h>
#include<math.h>
#include<ctype.h>

float evaluatePostfix(char postfix[]);
float oper(char symb, float op1, float op2);
void push(float x);
float pop();
float stack[50];
int top = -1;

int main()
{
	char postfix[50];
	int choice;
	float res;
	
	do
	{
		printf("Enter postfix expression:");
		scanf("%s",postfix);
		res = evaluatePostfix(postfix);
		printf("Result = %.2f \n", res);
		printf("Do you want to enter another expression? (1 for Yes/ 0 for No) :");
		scanf("%d",&choice);
	}while(choice!=0);
	return 0;
}

float evaluatePostfix(char postfix[]) 
{
	float op1, op2, res;
	char ch;
	int i = 0;
	while ((ch = postfix[i]) != '\0') 
	{
	if (isdigit(ch)) 
	{
		push(ch - '0'); 
	} 
	else 
	{
		op2 = pop();
		op1 = pop();
		res = oper(ch, op1, op2);
		push(res);
	}
i++;
}
return pop(); 
}

float oper(char symb, float op1, float op2)
{
	switch(symb)
	{
		case '$':
		case '^':
			return pow(op1,op2);
		case '*':
			return op1*op2;
		case '/':
			return op1/op2;
		case '+':
			return op1+op2;
		case '-':
			return op1-op2;
		default:
			printf("Invalid operator \n");
		return 0;
	}
}

void push(float x) 
{
	if (top < 49) 
	{ 
		stack[++top] = x;
	} 
	else 
	{
		printf("Stack Overflow\n");
	}
}

float pop() 
{
	if (top >= 0) 
	{ 
		return stack[top--];
	} 
	else 
	{
		printf("Stack Underflow\n");
	return 0; 
	}
}
