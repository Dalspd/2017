#include"stdio.h"
#include"stdlib.h"
#include<iostream>

using namespace std;

typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

int CreateBiTree(BiTree &T){
	char ch;
	scanf("%c",&ch);
	if(ch==' ') T=NULL;
	else{
		if(!(T=(BiTree)malloc(sizeof(BiTNode)))) exit(0);
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return 0;
}

void CountLeaf(BiTree T,int &count){
	if(T){
		if((!T->lchild)&&(!T->rchild)) count++;
		CountLeaf(T->lchild,count);
		CountLeaf(T->rchild,count);
	}
}

void GetDepth(BiTree T,int &count){
	if(T){
		if(T->lchild || T->rchild) count++;
		CountLeaf(T->lchild,count);
		CountLeaf(T->rchild,count);
	}
}

int main(){
	BiTree tree;
	int leaf=0,depth=1;
	CreateBiTree(tree);
	CountLeaf(tree,leaf);
	cout<<"Leaf:"<<leaf<<endl;
	GetDepth(tree,depth);
	cout<<"Depth:"<<depth;
}
