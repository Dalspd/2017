#define N 100
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;

typedef struct Data
{
	char city;
	float x;
	float y;
}data;

typedef struct CNode
{
	data data;
	struct CNode *next;
}node, *City;

void CreateList(City &L)//创建链表 
{
	int value;
	printf("开始创建，初始要输入几个城市：\n");
	scanf("%d", &value);
	L = (City)malloc(sizeof(node));
	L->next = NULL;
	for (int i = 0; i<value; i++)
	{
		City p = (City)malloc(sizeof(node));
		printf("请输入%d个城市的数据：\n", i+1);
		cin >> p->data.city >> p->data.x >> p->data.y;
		p->next = L->next;
		L->next = p;
	}
}

void search(City L)//查找 
{
	char name;
	City p;
	p = L;
	printf("请输入要查找的城市：\n");
	scanf("%c", &name);
	printf("坐标为：");
	while (p)
	{
		if (p->data.city == name)
			printf("%f,%f", p->data.x, p->data.y);
		p = p->next;
	}
}

void Insert(City L)//插入 
{
	City p = L->next;
	City ss = (City)malloc(sizeof(node));
	printf("请输入要插入的城市名及坐标：");
	scanf("%c %f %f", &ss->data.city, &ss->data.x, &ss->data.y);
	ss->next = p->next;
	p->next = ss;
}

void Delete(City L)//删除 
{
	City q, p = L->next;
	char c;
	printf("请输入要删除的城市名：");
	scanf("%c", &c);
	while (p->data.city != c)
	{
		q = p;
		p = p->next;
	}
	q->next = p->next;
	free(p);
	printf("已删除\n");
}

void print(City L)//打印 
{
	int i = 0;
	City a;
	char name[N];
	float x[N], y[N];
	a = L->next;
	while (a)
	{
		name[i] = a->data.city;
		x[i] = a->data.x;
		y[i] = a->data.y;
		a = a->next;
		printf("%c %f,%f\n", name[i], x[i], y[i]);
		i++;
	}
}

void distance(City L)//距离 
{
	float s, d;
	float x1, x2, y1, y2;
	City p;
	p = L->next;
	printf("请输入位置坐标P:");
	scanf("%f %f", &x1, &y1);
	printf("请输入距离D:");
	scanf("%f", &d);
	while (p)
	{
		x2 = p->data.x;
		y2 = p->data.y;
		s = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
		if (s <= d)
			printf("%c %f,%f\n", p->data.city, x2, y2);
		p = p->next;
	}
	
}

void alter(City L)//修改 
{
	char a, b;
	float c, d;
	int i = 0;
	City p = L;
	printf("请输入需要替换的城市名：");
	scanf("%c", &a);
	while (p->data.city != a)
	{
		p = p->next;
	}
	printf("请输入新的城市名：");
	scanf("%c", &b);
	printf("请输入城市坐标：");
	scanf("%f %f", &c, &d);
	p->data.city = b; p->data.x = c; p->data.y = d;
}

int main()
{
	City new_l;
	int i;
	CreateList(new_l);
	do
	{
		printf("\n");
		printf("----------------------------------------\n");
		printf("       请选择需要操作的功能：        \n");
		printf("  1->输出城市链表信息\n");
		printf("  2->查找\n");
		printf("  3->插入\n");
		printf("  4->删除\n");
		printf("  5->修改\n");
		printf("  6->与坐标P距离小于D的城市\n");
		printf("  0->退出程序\n");
		printf("----------------------------------------\n");
		printf("\n");
		printf("请输入您选择的功能号：");
		scanf("%d", &i);
		getchar();
		if (i>0)
			switch (i)
		{
			case 1:print(new_l); break;
			case 2:search(new_l); break;
			case 3:Insert(new_l); break;
			case 4:Delete(new_l); break;
			case 5:alter(new_l); break;
			case 6:distance(new_l); break;
		}
		printf("\n");
		if (i<0)
			printf("数值不正确，请重新输入！\n");
	} while (i != 0);
	return 0;
}
