#include<stdio.h>
#include<stdlib.h>

typedef int DataType;

typedef struct BSTNode{
	DataType data;
	struct BSTNode *lchild,*rchild;
	//int count;
}BSTNode,*BSTree;

BSTree SearchBST(BSTree *root,DataType key,int &count){
	BSTree s,p=*root;
	while(p){
		s=p;
		if(p->data==key)
			return NULL;
		p=(key<p->data)? p->lchild : p->rchild;
		count++;
	}
	return s;
}

void InsertBST(BSTree *root,DataType data,int count){
	BSTree s,p;
	s=(BSTree)malloc(sizeof(BSTNode));
	s->data=data;
	s->lchild=s->rchild=NULL;
	if(*root==NULL)
		*root=s;
	else{
		p=SearchBST(root,data,count);
		if(p==NULL){
			free(s);
			return;
		}
		if(data<p->data)
			p->lchild=s;
		else
			p->rchild=s;	
	}
}

int visit(DataType data){
	printf("%d ",data);
	return 1;
}

int InOrderTraverse(BSTree root,int(*visit)(DataType data)){
	if(root){
		if(InOrderTraverse(root->lchild,visit))
			if(visit(root->data))
				if(InOrderTraverse(root->rchild,visit))
					return 1;
		return 0;			
	}
	else
		return 1;
}

int main(){
	int i,num,count=0,input;
	BSTree root=NULL,p;
	DataType data;
	printf("Please enter the quantity of data:");
	scanf("%d",&num);
	printf("Please enter %d integers:\n",num);
	for(i=0;i<num;i++){
		scanf("%d",&data);
		InsertBST(&root,data,count);
	}
	printf("In order traverse:");
	InOrderTraverse(root,visit);
	printf("\nPlease enter the number you want to search:");
	scanf("%d",&num);
	if(SearchBST(&root,num,count)==NULL)
		printf("Found. Search length is %d.\n",count);
	else
		printf("Not Found.");
	return 0;		
}
