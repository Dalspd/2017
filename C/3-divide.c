#include<stdio.h>//输出0~n之间不能被3整除的数 
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
