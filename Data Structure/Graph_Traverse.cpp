#include<stdio.h>
#include<stdlib.h>
#include<iostream>

#define MAX_VERTEX_NUM 20
#define INITSIZE 100
#define INCREAMENT 10
#define MAXQSIZE 100

using namespace std;

typedef struct ArcNode{  /*�߱�ڵ�*/ 
	int adjvex;  
	struct ArcNode* nextarc;
}ArcNode;

typedef struct VNode{  /*�����ڵ�*/ 
	char vertex;
	ArcNode* firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct{  /*ͼ�ṹ*/ 
	AdjList vertices;
	int  vexnum,arcnum;
}ALGraph;

typedef struct /*ջ*/ 
{
	int *base;
	int *top;
	int stacksize;
}SqStack;

typedef struct /*����*/
{
	int *base;
	int front;
	int rear;
}SqQueue;

void Visit(ALGraph G,int v){
	cout<<G.vertices[v].vertex;
}

int InitStack(SqStack &S)
{
	S.base=(int *)malloc(INITSIZE * sizeof(int));
	S.top=S.base;
	S.stacksize=INITSIZE;
	return 0;
}

int Push(SqStack &S,int e)
{
	if(S.top-S.base>=S.stacksize)
	{ 
	  S.base=(int *)realloc(S.base,(S.stacksize+INCREAMENT)*sizeof(int));
	  S.top=S.base+S.stacksize;
	  S.stacksize+=INCREAMENT; 
	 } 
	*S.top++=e;
	return 0; 
}

int Pop(SqStack &S,int &e)
{
	if(S.base!=S.top)
	  e=*--S.top; 
	return 0;
}

int StackEmpty(SqStack S)
{
	if(S.base==S.top)  
       return 1;  
    else  
       return 0;  
}

int InitQueue(SqQueue &Q)//�����ն���Q 
{
	Q.base=(int *)malloc(MAXQSIZE * sizeof(int));
	Q.front=Q.rear=0;
	return 1;
}

int QueueEmpty(SqQueue Q)//�����п� 
{
	if(Q.front==Q.rear)  
       return 1;  
    else  
       return 0;  
}

int EnQueue(SqQueue &Q,int e)//��� 
{
	if((Q.rear+1)%MAXQSIZE==Q.front)
      return 0;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1) % MAXQSIZE;
	return 1;
}

int DeQueue(SqQueue &Q,int &e)//���� 
{
	if(Q.front==Q.rear)
	  return 0;
    e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXQSIZE; 
	return 1;  
}

int CreateGraph(ALGraph *alg){
	int i,j,k;
	ArcNode *s;
	cin>>alg->vexnum>>alg->arcnum;
	for(i=0;i<alg->vexnum;i++){
		cin>>alg->vertices[i].vertex;
		alg->vertices[i].firstarc=NULL;
	} 
	for(k=0;k<alg->arcnum;k++){
		cin>>i>>j;
		s=(ArcNode*)malloc(sizeof(ArcNode));
		s->adjvex=j;
		s->nextarc=alg->vertices[i].firstarc; //�����ͷ
		alg->vertices[i].firstarc=s;
		s=(ArcNode *)malloc(sizeof(ArcNode));
		s->adjvex=i;
		s->nextarc=alg->vertices[j].firstarc;
		alg->vertices[j].firstarc=s; 
	}
}

int FirstAdjVex(ALGraph G,int v){
	if(!G.vertices[v].firstarc)
	  return 0;
	else
	  return (G.vertices[v].firstarc->adjvex);  
}

int NextAdjVex(ALGraph G,int v,int w){
	ArcNode *p;
	p=G.vertices[v].firstarc;
	while(p&&p->adjvex!=w) p=p->nextarc;
	if(p->adjvex==w && p->nextarc) return(p->nextarc->adjvex);
	else return 0;
}

bool visited[1000];

void DFS(ALGraph G,int v);

void DFSTraverseR(ALGraph G){
	int k;
	for(k=0;k<G.vexnum;++k) visited[k]=false;
	for(k=0;k<G.vexnum;++k)
		if(!visited[k]) DFS(G,k);
}

void DFS(ALGraph G,int v){
	visited[v]=true;
	Visit(G,v);
	int w;
	for(w=FirstAdjVex(G,v);w>0;w=NextAdjVex(G,v,w))
		if(!visited[w]) DFS(G,w);
}

void DFSTraverseS(ALGraph G){
	SqStack S;
	InitStack(S);
    int i, j;  
    int node;   
    int count = 1;     
    node = 0;
	Push(S,0);  
    for(j=0; j<G.vexnum; j++) visited[j]=false;
	while(count < G.vexnum) //still has node not visited  
    {  
    /* ���б����ʵĽڵ�������ջ��ֻ��node���Ҳ�����һ�������Ľڵ�ʱ����ʹ�ó�ջ�ڵ� */  
        for(j=0; j<G.vexnum; j++)  
        {  
            if(visited[j] == false)  
            {  
                visited[j] = true;    
                count++;  
                Push(S,j); //push node j  
                break;  
            }  
        }  
        if(j == G.vexnum) //��node�����Ľڵ㶼�Ѿ������ʹ���������Ҫ��stack��ȡ��node����һ���ڵ㣬�ٿ��ýڵ��Ƿ��������Ľڵ�δ������  
			{
			Visit(G,node);
			Pop(S,node);
			}  
        else      //�ҵ���node��������δ�����ʵĽڵ㣬  
            node = j;  
    }  
}

void BFSTraverse(ALGraph G){
 int v,u,w;
 SqQueue Q;
 for ( v=0; v<=G.vexnum; ++v ) visited[v] = false;
 InitQueue(Q);
 for( v=0; v<=G.vexnum; ++v )
 if ( !visited[v] ){
  visited[v]=true; Visit(G,v); EnQueue(Q, v);
  while (!QueueEmpty(Q)){
   DeQueue(Q,u);
   for(w=FirstAdjVex(G, u); w>0; w=NextAdjVex(G, u, w))
    if( !visited[w] ){
	 visited[w]=true; Visit(G,w); EnQueue(Q, w); 
	 }
    } // end while
   } // end if
}

int main(){
	ALGraph* G= (ALGraph*)malloc(sizeof(ALGraph));  
	int i;
	
	printf("Please input data in form as follows\n");
	printf("|vex arc|\n");
	printf("|a b c,etc.(Several vexs)|\n");
	printf("|0 1  0 2  2 3 ,etc.(Several arcs)|\n\n");
	CreateGraph(G);
	printf("\n"); 
	while(1)
    {
    printf("\nGraph Traverse\n");
    printf("===============\n");
    printf("1.Print Graph(Adjacency List)\n");
    printf("2.Depth_First Search(Recursion)\n");
    printf("3.Depth_First Search(Stack)\n");
    printf("4.Breadth_First Search(Queue)\n");
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
        	    for (int i=0;i<G->vexnum;i++){  
                    printf("%c->",G->vertices[i].vertex);  
                    while(G->vertices[i].firstarc!=NULL){  
                            printf("%d->",G->vertices[i].firstarc->adjvex);  
                    		G->vertices[i].firstarc=G->vertices[i].firstarc->nextarc;  
                    }  
                    printf("\n");  
                }
                break;
		case 2: 
		        cout<<"Traverse result:";
				DFSTraverseR(*G);
		        cout<<endl;
                break;
        case 3:     
		        cout<<"Traverse result:";
				DFSTraverseR(*G);
		        cout<<endl;
                break;
        case 4:     
		        cout<<"Traverse result:";
				BFSTraverse(*G);
		        cout<<endl;
				break;		
        case 5:     return 0;
        default:    printf("Invalid option\n");
        }
    }
    }
    return 0;
}
