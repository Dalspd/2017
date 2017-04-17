#include<stdio.h>
main()
{
  void input(int *m);
  void mm(int *m);	
  void output(int *m);
  int number[10];
  printf("Please input 10 integers:"); 
  input(number);
  mm(number);
  printf("After sort:");
  output(number);
  return 0;
}
void input(int *number)
{
	int i;
	for(i=0;i<=9;i++)
	  scanf("%d",&number[i]);   
}
void mm(int *number)
{
	int temp,*max,*min,*p;
	max=min=number;
	for(p=number+1;p<number+10;p++)
	 if(*p<*min) min=p;
	 temp=number[0];number[0]=*min;*min=temp;
	for(p=number+1;p<number+10;p++)
	 if(*p>*max) max=p;
	 temp=number[9];number[9]=*max;*max=temp;
}
void output(int *number)
{
	int i;
	for(i=0;i<=9;i++)
	  printf("%d ",number[i]);
}
