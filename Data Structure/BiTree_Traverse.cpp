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

int Visit(char e){
	cout<<e;
	return 1;
}

int InOrderTraverse(BiTree T,int(*Visit)(char e)){
	if(T){
		if(InOrderTraverse(T->lchild,Visit))
		  if(Visit(T->data))
		    if(InOrderTraverse(T->rchild,Visit))
		      return 1;
		return 0;      
	}
	else return 1;
}

int PreOrderTraverse(BiTree T,int(*Visit)(char e)){
	if(T){
		if(Visit(T->data))
		  if(PreOrderTraverse(T->lchild,Visit))
		    if(PreOrderTraverse(T->rchild,Visit))
		      return 1;
		return 0;      
	}
	else return 1;
}

int PostOrderTraverse(BiTree T,int(*Visit)(char e)){
	if(T){
		if(PostOrderTraverse(T->lchild,Visit))
		  if(PostOrderTraverse(T->rchild,Visit))
		    if(Visit(T->data))
		      return 1;
		return 0;      
	}
	else return 1;
}

int main(){
	BiTree T;
	cout<<"Please input a binary tree,in Pre Order:";
	CreateBiTree(T);
	cout<<"Pre Order:";
	PreOrderTraverse(T,Visit);
	cout<<endl<<"In Order:";
	InOrderTraverse(T,Visit);
	cout<<endl<<"Post Order:";
	PostOrderTraverse(T,Visit);
	return 0;
}
