#include<stdio.h>//���0~n֮�䲻�ܱ�3�������� 
main()
{
	int n,s;
	scanf("%d",&s);
	for(n=0;n<=s;n++)
	  {
	  	if(n%3==0)
	  	  continue;
	  	printf("%d ",n);  
	  }
 } 
