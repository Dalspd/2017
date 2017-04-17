#include"stdio.h"
#include"stdlib.h"
#include"math.h"
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

int GetDepth(BiTree T){
	int count;
	if(!T) count=0;
	else{
		int depthLeft=GetDepth(T->lchild);
		int depthRight=GetDepth(T->rchild);
		count=1+(depthLeft>depthRight?depthLeft:depthRight);
	}
	return count;
}

int main(){
	BiTree tree;
	int leaf=0,depth=0;
	CreateBiTree(tree);
	CountLeaf(tree,leaf);
	depth=GetDepth(tree);
	if(leaf==pow(2,depth-1))
	  printf("Full Binary Tree.");
    else
      printf("Not-full Binary Tree.");
    return 0;
}
