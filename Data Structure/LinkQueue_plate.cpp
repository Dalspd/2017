#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int Status;

typedef struct QNode
{
	int data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
	QueuePtr head;
	QueuePtr tail;
}LinkQueue;

Status InitQueue (LinkQueue &Q) //创建一个队列 
{
	Q.head=Q.tail=(QueuePtr)malloc(sizeof(QNode));
	if (!Q.head) exit (OVERFLOW);
	Q.head->next=NULL;
	return OK;
}

Status EnQueue (LinkQueue &Q,int e)//入队 
{
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if(!p) exit (OVERFLOW);
	p->data=e;
	p->next=NULL;
	Q.tail->next=p;
	Q.tail=p;
	return OK;
}

Status DeQueue (LinkQueue &Q)//出队 
{
	QueuePtr p;
	int e;
	if(Q.head==Q.tail) return ERROR;
	p=Q.head->next;
	e=p->data;
	Q.head->next=p->next;
	if(Q.tail==p)
	  Q.tail=Q.head;
	free(p);
	return (e);
}

Status ClearQueue (LinkQueue &Q)//清空队列 
{
	while(!Q.head)
	{
		DeQueue(Q);
	}
	return OK;
}

Status DestroyQueue (LinkQueue &Q)//摧毁队列
{
	while(Q.head)
	{
		Q.tail=Q.head->next;
		free(Q.head);
		Q.head=Q.tail;
	}
	return OK;
}
 
int main()
{
	int i,e;
    LinkQueue Q;
    InitQueue(Q);
    while(1)
    {
    printf("\nQueue Operations\n");
    printf("===============\n");
    printf("1.Clear\n");
    printf("2.EnQueue\n");
    printf("3.DeQueue\n");
    printf("4.Destroy\n");
    printf("5.Exit\n");
    printf("\n"); 
    printf("Enter your choice : ");
    if(scanf("%d",&i)<=0){
        printf("Enter only an Integer\n");
        exit(0);
    } else {
        switch(i)
        {
        case 1: 
		        ClearQueue(Q);
                break;
        case 2:     
		        printf("Please input the number you want to enqueue:\n");
		        scanf("%d",&e);
				EnQueue(Q,e);
                break;
        case 3:     
		        e=DeQueue(Q);
				printf("The result is:%d\n",e);
				break;
		case 4:
		        DestroyQueue(Q);
				break;		
        case 5:     return 0;
        default:    printf("Invalid option\n");
        }
    }
    }
    return 0;
}
