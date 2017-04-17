#include<stdio.h>
#include<stdlib.h>

#define MAXQSIZE 100
#define ERROR 1
#define OK 0

typedef struct
{
	int *base;
	int front;
	int rear;
}SqQueue;

int InitQueue(SqQueue &Q)//构建空队列Q 
{
	Q.base=(int *)malloc(MAXQSIZE * sizeof(int));
	Q.front=Q.rear=0;
	return OK;
}

int QueueLength(SqQueue &Q)//队列长度 
{
	return (Q.rear-Q.front+MAXQSIZE) % MAXQSIZE;
}

int EnQueue(SqQueue &Q,int e)//入队 
{
	if((Q.rear+1)%MAXQSIZE==Q.front)
      return ERROR;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1) % MAXQSIZE;
	return OK;
}

int DeQueue(SqQueue &Q,int &e)//出队 
{
	if(Q.front==Q.rear)
	  return ERROR;
    e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXQSIZE; 
	return OK;  
}


int main()
{
	SqQueue Q;
	int i,e,length,p;
	InitQueue(Q);
	while(1)
    {
    printf("\nQueue Operations\n");
    printf("===============\n");
    printf("1.Clear\n");
    printf("2.EnQueue\n");
    printf("3.DeQueue\n");
    printf("4.Length\n");
    printf("5.Exit\n");
    printf("\n"); 
    printf("Enter your choice : ");
    if(scanf("%d",&i)<=0){
        printf("Enter only an Integer\n");
        exit(0);
    } else {
        printf("\n"); 
		switch(i)
        {
        case 1: 
		        InitQueue(Q);
                break;
        case 2:     
		        printf("Please input the number you want to enqueue:");
		        scanf("%d",&e);
				EnQueue(Q,e);
                break;
        case 3:     
		        p=DeQueue(Q,e);
				if(p==OK)
				printf("The result is:%d\n",e);
				else
				printf("There is no member in queue.\n");
				break;
		case 4:
		        length=QueueLength(Q);
		        printf("The length is:%d\n",length);
				break;		
        case 5:     return 0;
        default:    printf("Invalid option\n");
        }
    }
    }
    return 0;
}


