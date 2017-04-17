#include"stdio.h"
int max(int *x,int *y)
{
	if(*x>=*y)
	return x;
	else return y;
}
int min(int *x,int *y)
{
	if(*x<=*y)
	return x;
	else return y;
}
int main()
{
	int *p1,*p2,*p3,*p,*pm,a,b,c;
	scanf("%d,%d,%d",&a,&b,&c);
	p1=&a;
	p2=&b;
	p3=&c;
	p=max(p1,p2);
	p=max(p,p3);
	pm=min(p1,p2);
	pm=min(pm,p3);
	printf("a=%d,b=%d,c=%d\n",a,b,c);
	printf("max=%d,min=%d",*p,*pm);
	return 0;
}
	
