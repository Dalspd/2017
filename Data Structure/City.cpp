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

void CreateList(City &L)//�������� 
{
	int value;
	printf("��ʼ��������ʼҪ���뼸�����У�\n");
	scanf("%d", &value);
	L = (City)malloc(sizeof(node));
	L->next = NULL;
	for (int i = 0; i<value; i++)
	{
		City p = (City)malloc(sizeof(node));
		printf("������%d�����е����ݣ�\n", i+1);
		cin >> p->data.city >> p->data.x >> p->data.y;
		p->next = L->next;
		L->next = p;
	}
}

void search(City L)//���� 
{
	char name;
	City p;
	p = L;
	printf("������Ҫ���ҵĳ��У�\n");
	scanf("%c", &name);
	printf("����Ϊ��");
	while (p)
	{
		if (p->data.city == name)
			printf("%f,%f", p->data.x, p->data.y);
		p = p->next;
	}
}

void Insert(City L)//���� 
{
	City p = L->next;
	City ss = (City)malloc(sizeof(node));
	printf("������Ҫ����ĳ����������꣺");
	scanf("%c %f %f", &ss->data.city, &ss->data.x, &ss->data.y);
	ss->next = p->next;
	p->next = ss;
}

void Delete(City L)//ɾ�� 
{
	City q, p = L->next;
	char c;
	printf("������Ҫɾ���ĳ�������");
	scanf("%c", &c);
	while (p->data.city != c)
	{
		q = p;
		p = p->next;
	}
	q->next = p->next;
	free(p);
	printf("��ɾ��\n");
}

void print(City L)//��ӡ 
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

void distance(City L)//���� 
{
	float s, d;
	float x1, x2, y1, y2;
	City p;
	p = L->next;
	printf("������λ������P:");
	scanf("%f %f", &x1, &y1);
	printf("���������D:");
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

void alter(City L)//�޸� 
{
	char a, b;
	float c, d;
	int i = 0;
	City p = L;
	printf("��������Ҫ�滻�ĳ�������");
	scanf("%c", &a);
	while (p->data.city != a)
	{
		p = p->next;
	}
	printf("�������µĳ�������");
	scanf("%c", &b);
	printf("������������꣺");
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
		printf("       ��ѡ����Ҫ�����Ĺ��ܣ�        \n");
		printf("  1->�������������Ϣ\n");
		printf("  2->����\n");
		printf("  3->����\n");
		printf("  4->ɾ��\n");
		printf("  5->�޸�\n");
		printf("  6->������P����С��D�ĳ���\n");
		printf("  0->�˳�����\n");
		printf("----------------------------------------\n");
		printf("\n");
		printf("��������ѡ��Ĺ��ܺţ�");
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
			printf("��ֵ����ȷ�����������룡\n");
	} while (i != 0);
	return 0;
}
