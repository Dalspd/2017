#include<stdio.h>//�˳�������Ѱ�������������Լ�� 
main()
{
    int a,b,t,i;
	scanf("%d %d",&a,&b);
	if(a>=b)
	  t=b;
	else
	  t=a;  
	for(i=t;i>=1;i--)
	{
		if(a%i==0 && b%i==0)
		  break;
	}
	printf("max=%d",i);
}
