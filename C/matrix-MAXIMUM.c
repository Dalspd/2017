#include<stdio.h>
main()
{
	int a,b,i,j,max;
	scanf("%d %d",&a,&b);
	int c[a][b];
	for(i=0;i<a;i++)
	   for(j=0;j<b;j++)
	   	 scanf("%d",&c[i][j]);
	max=c[0][0];
	for(i=0;i<a;i++)
	  {
	   for(j=0;j<b;j++)
	    {
		  if(c[i][j]>=max)
		  max=c[i][j];
	    }
	  }
	printf("max=%d",max);
}	  
