#include<stdio.h> 
int taste()
{
	int o1;
	printf("��������ϲ�õĿ�ζ����1-��/2-��/3-��/4-��/5-�˳���");
	scanf("%d",&o1); 
	switch(o1)
	{ 
	  case 1:printf("��ѡ��Ŀ�ζ�ǣ���\n");break;
	  case 2:printf("��ѡ��Ŀ�ζ�ǣ���\n");break;
	  case 3:printf("��ѡ��Ŀ�ζ�ǣ���\n");break;
	  case 4:printf("��ѡ��Ŀ�ζ�ǣ���\n");break;
	  case 5:break; 
    }
    return 0;
}
int getNum()
{
	int m,x;
	printf("��1ˢ������2����ѧ��:"); 
	scanf("%d",&m);
	printf("\n");
	switch(m)
	{
	 case 1:printf("��ˢ��\n");printf("ˢ���ɹ���");break;
	 case 2:printf("������10λѧ�ţ�");
	       printf("\n");scanf("%d",&x);
	      break;
	 default:printf("���������룡\n");getNum();break;	    
    }
    return 0;
}
int size()
{
	float s=0;
	int a,b;
	printf("����������Ҫ���׷�������(1-���/2-С��)");
	scanf("%d",&a);
	if(a==1)
	  s+=1;
	else
	  s+=0.5;
	printf("����������Ҫ�Ĳ˷�����(1-���/2-�з�/3-С��)");
	scanf("%d",&b);
	if(b==1)
	  s+=9;
	else if(b==2)
	  s+=8;
    else
	  s+=7;
	printf("\n");  
	return(s);    
} 
int main()
{
  float t;
  getNum();
  taste();
  t=size();
  printf("���ͬѧ���˴ι�����%.1fԪ����ӭ�´ι��٣�",t);
  return 0;	
}
