#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

void CreateList(LinkList &L,int n){
	L=(LNode*)malloc(sizeof(LNode));
	L->next=NULL;
	for(int i=0;i<n;i++){
		LNode *p;
		p=(LNode*)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		p->next=L->next;
		L->next=p;
	}
}

void Visit(LNode *head,int k){
	LNode *p=head;
	int cnt=0;
	int pos;
	while(p!=NULL){
		cnt++;
		p=p->next;
	}
	pos=cnt-k+1;
	if(pos>0){
		cnt=0;
		p=head;
	}
	while(p){
		cnt++;
		if(cnt==pos)
		  break;
		p=p->next;
		printf("cnt:%d,pos:%d\n",cnt,pos);  
	}
}

int main(){
	LinkList L;
	int k,n;
	printf("Please input the quantity of the list:");
	scanf("%d",&n);
	printf("Create the List:");
	CreateList(L,n);
	printf("Please input k:");
	scanf("%d",&k);
	Visit(L,k);
	return 0;
}

