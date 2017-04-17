#include<stdio.h>
#include<math.h>
int pm(int x)
{
	int s;
	s=(sqrt(x))*10;
	return(s-x);
 } 
 int tax(int y)
 {
 	int r;
 	r=y*1.2;
 	return(r-y);
 }
 int max(int x1,int x2)
 {
 	int t;
 	if(x1>=x2)
 	 t=x1;
 	else
	 t=x2;
	return(t);  
 }
 int main()
 {
 	int a,a1,a2;
 	printf("input=");
	scanf("%d",&a);
 	a1=pm(a);
 	a2=tax(a);
 	a=max(a1,a2);
 	printf("profit=%d",a);
    return 0; 
 }
