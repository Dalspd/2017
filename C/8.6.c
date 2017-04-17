#include<stdio.h>
int length(char *str)
{
	int n=0;
	while(*str!='\0')
	{
	 n++;str++;
    }
    return(n);
}
main()
{
	char str[20];
	int len;
	  scanf("%s",str);
	len=length(str);
	printf("%d",len);
	return 0;  
}
