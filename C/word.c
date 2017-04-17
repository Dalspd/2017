#include"stdio.h" 
int main()
{
	char str[100],c;
	int word=0,i,num;
	printf("Please input a sentence:");
	gets(str);
	for(i=0;(c=str[i])!='\0';i++)
	{
		if (c==' ') word=0;
		else if(word==0)
		{
			word=1;
			num++;
		}
	}
	printf("\nThere is %d words.",num);
	return 0;
}

