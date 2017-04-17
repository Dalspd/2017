#include<stdio.h>
main()
{
	int s,i;
	i=1;
	do{
		s+=i;
		i++;
	}while(i<101);
	printf("s=%d",s);
}
