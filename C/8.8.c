#include<stdio.h>
main()
{
	int c=0,nc=0,b=0,n=0,o=0,i=0;
	char *p,s[20];
	while((s[i]=getchar())!='\n') i++;
	p=&s[0];
	while(*p!='\n')
	{
		if((*p>='A')&&(*p<='Z')) c++;
		else if((*p>='a')&&(*p<='z')) nc++;
		else if(*p==' ') b++;
		else if((*p>='0')&&(*p<='9')) n++;
		else o++;
		p++; 
	}
	printf("��д��ĸ��%d,Сд��ĸ��%d,�ո�%d,���֣�%d,������%d\n",c,nc,b,n,o);
	return 0;
}
