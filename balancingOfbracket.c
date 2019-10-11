#include<stdio.h>
#include<stdlib.h>

#include<stdbool.h>


char stack[10];
int top = -1;

void push(char ch)
{
	if (top>9)
	{
		return ;
	}

	stack[++top] = ch;
}


void pop()
{
	if (top==-1)
	{
		return;
	}
	top--;
}

char peak()
{
	return stack[top];

}

bool isEmpty()
{
	return (top==-1);
}

char element(char c)
{
	switch(c)
	{
		case '}':return '{';
		case ')':return '(';
		case ']':return '['; 
	}
}

void check(char *c)
{
	int i;
	for (i=0;*(c+i)!='\0';i++)
	{
		/* code */
		if (*(c+i)=='{'|| *(c+i)=='('||*(c+i)=='[')
		{
			
			push(*(c+i));
		
		}
		else if(*(c+i)=='}'|| *(c+i)==')'||*(c+i)==']')
		{
		 	
		 	if (peak()== element(*(c+i)))
		 	{
		 		printf("poping%c\n",peak());
		 		pop();
		 	}
		 	else
		 	{

		 		printf("not balanced\n");
		 		return;
		 	}
			
		}

	}

	if (isEmpty())
	{
		printf("balanced\n");
	}
	else
	{
		printf("not balanced\n");
	}

		
}

int main()
{
	char *c1;
	printf("enter the string\n");
	scanf("%s",c1);
	//printf("%s\n",c );
	check(c1);
	return 0;
	
}