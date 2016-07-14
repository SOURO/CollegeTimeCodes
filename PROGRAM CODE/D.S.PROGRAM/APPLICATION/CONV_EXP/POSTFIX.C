#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>

char stack[50],exp_in[50],exp_post[50];
float num_stk[30];
int top=0,num_top=-1;

void push(char);
char pop();
int precedance(char);
float evaluate_post();

void main()
{
	char ch,t;
	int i,l,j;
	stack[top]='#';

	clrscr();

	printf("ENTER A MATHEMATICAL EXPRESSION::\n");
	printf("----------------------------------\n");
	gets(exp_in);

	printf("\nINFIX EXPRESSION IS::\n");
	printf("---------------------\n");
	printf("\t\t\t\t");
	puts(exp_in);

	j=0;
	for(i=0;exp_in[i]!='\0';i++)
	{
		ch=exp_in[i];
		switch(ch)
		{
			case '(':
						push(ch);
						break;
			case ')':
						t=pop();
						while(t!='(' && top>=1)
						{
							exp_post[j++]=t;
							t=pop();
						}
						break;
			case '*':
			case '^':
			case '/':
			case '+':
			case '-':
						while(precedance(ch)<=precedance(stack[top]))
						{
							t=pop();
							exp_post[j++]=t;
						}
						push(ch);
						break;
			default:
						exp_post[j++]=ch;
		}
	}
	while(top>=1)
	{
		t=pop();
		exp_post[j++]=t;
	}
	exp_post[j]='\0';

	printf("\n\n\nPREFIX EXPRESSION IS::\n");
	printf("----------------------\n");
	printf("\t\t\t\t");
	puts(exp_post);

	printf("\n\nYOUR ANSWER IS::\t%f",evaluate_post());
	printf("\n----------------");

	getch();
}
void push(char ch)
{
	stack[++top]=ch;
}
char pop()
{
	--top;
	return stack[top+1];
}
int precedance(char ch)
{
	switch(ch)
	{

		case '^':
			return 5;
		case '/':
		case '*':
			return 4;

		case '+':
		case '-':
			return 3;
		case '(':
			return 2;
		default:
			 return 1;
	}
}
void num_push(float n)
{
	num_stk[++num_top]=n;
}
float num_pop()
{
	--num_top;
	return num_stk[num_top+1];
}
float evaluate_post()
{
	int i;
	float op1,op2;
	char ch;

	for(i=0;exp_post[i]!='\0';i++)
	{
		ch=exp_post[i];
		switch(ch)
		{
			case '+':
				op2=num_pop();
				op1=num_pop();
				num_push(op1+op2);
				break;
			case '-':
				op2=num_pop();
				op1=num_pop();
				num_push(op1-op2);
				break;
			case '*':
				op2=num_pop();
				op1=num_pop();
				num_push(op1*op2);
				break;
			case '/':
				op2=num_pop();
				op1=num_pop();
				num_push(op1/op2);
				break;
			case '^':
				op2=num_pop();
				op1=num_pop();
				num_push(pow(op1,op2));
				break;
			case '0':
				num_push(0);
				break;
			case '1':
				num_push(1);
				break;
			case '2':
				num_push(2);
				break;
			case '3':
				num_push(3);
				break;
			case '4':
				num_push(4);
				break;
			case '5':
				num_push(5);
				break;
			case '6':
				num_push(6);
				break;
			case '7':
				num_push(7);
				break;
			case '8':
				num_push(8);
				break;
			case '9':
				num_push(9);
		}
	}
	return num_pop();
}