#include<stdio.h> 
int taste()
{
	int o1;
	printf("请输入你喜好的口味：（1-苦/2-辣/3-酸/4-甜/5-退出）");
	scanf("%d",&o1); 
	switch(o1)
	{ 
	  case 1:printf("您选择的口味是：苦\n");break;
	  case 2:printf("您选择的口味是：辣\n");break;
	  case 3:printf("您选择的口味是：酸\n");break;
	  case 4:printf("您选择的口味是：甜\n");break;
	  case 5:break; 
    }
    return 0;
}
int getNum()
{
	int m,x;
	printf("按1刷卡，按2输入学号:"); 
	scanf("%d",&m);
	printf("\n");
	switch(m)
	{
	 case 1:printf("请刷卡\n");printf("刷卡成功！");break;
	 case 2:printf("请输入10位学号：");
	       printf("\n");scanf("%d",&x);
	      break;
	 default:printf("请重新输入！\n");getNum();break;	    
    }
    return 0;
}
int size()
{
	float s=0;
	int a,b;
	printf("请输入你想要的米饭份量：(1-大份/2-小份)");
	scanf("%d",&a);
	if(a==1)
	  s+=1;
	else
	  s+=0.5;
	printf("请输入你想要的菜份量：(1-大份/2-中份/3-小份)");
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
  printf("你好同学，此次共消费%.1f元。欢迎下次光临！",t);
  return 0;	
}
