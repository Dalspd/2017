#include<stdio.h>
#include<math.h>
main()
{
	float s,a,b,c,area;
	printf("please input three numbers\n");
	scanf("%f %f %f",&a,&b,&c);
	if((a+b>c)&&(a+c>b)&&(b+c>a))
	  {
	    s=(a+b+c)/2;
		area=sqrt(s*(s-a)*(s-b)*(s-c));
		printf("area=%.2f",area);
	  }
	  else
	  {
	    printf("Error,the three numbers can't make a triangle.");
	  } 
		
	  return 0;
	getch();   
} 
