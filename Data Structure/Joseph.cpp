#include<stdio.h> 
#include<stdlib.h> 

typedef struct LNode{
	int data;
	int number;
	struct LNode *next;
}LNode, *LinkList;

void getResult(LinkList a, int x)
{
	int i,j;
	LinkList pri;
	for (i = x; i>1; i--)
	{
		a = a->next;
	}
	pri = a;
	a = a->next;
	j = a->data;
	printf("%d ", a->number);
	pri->next = a->next;
	free(a);
	if (pri->next != pri)
	getResult(pri,j);
	else
	{
		printf("%d ", pri->number);
	}
}

int main()
{
	int n, m, i;
	LinkList Joseph, top, P;
	Joseph = (LinkList)malloc(sizeof(LNode));
	top = (LinkList)malloc(sizeof(LNode));
	printf("请输入总人数：");
	scanf("%d", &n);
	printf("请输入报数上限值：");
	scanf("%d", &m);


	printf("请输入第1个人所持的密码：");
	P = (LinkList)malloc(sizeof(LNode));
	scanf("%d", &P->data);
	P->number = 1;
	Joseph->next = P;
	top = Joseph;
	Joseph = Joseph->next;

	for (i = 1; i<n; i++)
	{
		printf("请输入第%d个人所持的密码：", i + 1);
		P = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &P->data);
		P->number = i + 1;
		Joseph->next = P;
		Joseph = P;
	}
	Joseph->next = top->next;


	getResult(top, m);
	scanf("%d", &m);
	return 0;
}

