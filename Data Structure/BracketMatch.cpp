#include<stdio.h>
#include<stdlib.h>
#include<iostream>

#define INITSIZE 100
#define INCREAMENT 10

using namespace std;

typedef struct 
{
	char *base;
	char *top;
	int stacksize;
}SqStack;

int InitStack(SqStack &S)
{
	S.base=(char *)malloc(INITSIZE * sizeof(char));
	S.top=S.base;
	S.stacksize=INITSIZE;
	return 0;
}

int push(SqStack &S,char e)
{
	if(S.top-S.base>=S.stacksize)
	{ 
	  S.base=(char *)realloc(S.base,(S.stacksize+INCREAMENT)*sizeof(char));
	  S.top=S.base+S.stacksize;
	  S.stacksize+=INCREAMENT; 
	 } 
	*S.top++=e;
	return 0; 
}

int pop(SqStack &S,char &e)
{
	if(S.base!=S.top)
	  e=*--S.top;
	return 0;
}

int isEmpty(SqStack S)
{
	if(S.base==S.top)  
       return 1;  
   else  
       return 0;  
}

int judge(SqStack &S)
{
	char c,_c;
	while((c=getchar())!=EOF)
	{
	    if(c==']' || c==')'||c=='[' || c=='(')
	    {
			if(c=='[' || c=='(')
		  	push(S,c);
		else if(c==']' || c==')')
		  {
			pop(S,_c);
			if(c==']' && _c=='(') 
			{
				printf("此串括号匹配不合法\n");
				return 0;
			}
			else if(c==')'&& _c=='[')
			{
				printf("此串括号匹配不合法\n");
				return 0;
			}
		  }
	    }
	  else continue;
	}
	printf("匹配\n");
	return 0;
}

int main()
{
	SqStack S;
	InitStack(S);
	printf("请输入一串由[]()组成的字符串:\n");
	judge(S);
	return 0;
}
