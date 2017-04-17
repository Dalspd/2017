#include<stdio.h>
#include<stdlib.h>

#define INITSIZE 100
#define INCREAMENT 10

typedef struct 
{
	int *base;
	int *top;
	int stacksize;
}SqStack;

int InitStack(SqStack &S)
{
	S.base=(int *)malloc(INITSIZE * sizeof(int));
	S.top=S.base;
	S.stacksize=INITSIZE;
	return 0;
}

int push(SqStack &S,int e)
{
	if(S.top-S.base>=S.stacksize)
	{ 
	  S.base=(int *)realloc(S.base,(S.stacksize+INCREAMENT)*sizeof(int));
	  S.top=S.base+S.stacksize;
	  S.stacksize+=INCREAMENT; 
	 } 
	*S.top++=e;
	return 0; 
}

int pop(SqStack &S,int &e)
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

int convert(SqStack &S,int n)
{
	int a=n,b,i=0,t;
	do{
		b=a%8;
		a=a/8;
		push(S,b);
	}while(a>1);
	while(i==0){
		pop(S,t);
		printf("%d",t);
		i=isEmpty(S);
	};
	return 0;
}

int main()
{ 
    SqStack S;
	int n;
	InitStack(S); 
	printf("Please input the number:\n");
	scanf("%d",&n);
	printf("The result is:\n");
	convert(S,n);
	return 0;
} 
