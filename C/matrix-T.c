#include<stdio.h>
main()
{
	int a,b,i,j;
	scanf("%d %d",&a,&b);
	int c[a][b],d[b][a];
	for(i=0;i<a;i++)
	  for(j=0;j<b;j++)
	    scanf("%d",&c[i][j]);
	for(i=0;i<a;i++)
	  {
	   for(j=0;j<b;j++)
	   {
		d[j][i]=c[i][j];   
	   }
      }
    for(i=0;i<b;i++)
	  {
	   for(j=0;j<a;j++)
		printf("%d ",d[i][j]);
	   printf("\n");
      }
}
