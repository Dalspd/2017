#include<stdio.h>//������Ϸ��n���˱�����3�ı����Լ���3��������,��������ֵ��˵���� 
int judge(int x)
{
	int q[5],u;
	q[1]=x/10000;
	q[2]=(x-q[1]*10000)/1000;
	q[3]=(x-q[1]*10000-q[2]*1000)/100;
	q[4]=(x-q[1]*10000-q[2]*1000-q[3]*100)/10;
	q[5]=x%10;
	for(u=1;u<=5;u++)
    {
    	if (q[u]==3)
    	{
		 return 0;
		 break;
	    }
    }
    return 1; 
}
main()
{
	int n,i;
	printf("������һ��������100000������\n");
	scanf("%d",&n);
	if(n>=100000)
    {
	  printf("error");
    }
    for(i=1;i<=n;i++)
    {
    	if (i%3!=0 && judge(i)!=0)
        printf(" %d ",i);
	}
}
