#include<stdio.h> 
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
char Nil=' ';
typedef int Status; 
typedef enum{Link,Thread}PointerTag; 
typedef struct BiThrNode
{
  char data;
  struct BiThrNode *lchild,*rchild; /* 左右孩子指针 */
  PointerTag LTag,RTag; /* 左右标志 */
}BiThrNode,*BiThrTree;

Status CreateBiThrTree(BiThrTree *T)
{ 
  char h;
  scanf("%c",&h);
  if(h==Nil)
    *T=NULL;
  else
  {
    *T=(BiThrTree)malloc(sizeof(BiThrNode));
    if(!*T)
      exit(OVERFLOW);
    (*T)->data=h; /* 生成根结点(先序) */
    CreateBiThrTree(&(*T)->lchild); /* 递归构造左子树 */
    if((*T)->lchild) /* 有左孩子 */
      (*T)->LTag=Link;
    CreateBiThrTree(&(*T)->rchild); /* 递归构造右子树 */
    if((*T)->rchild) /* 有右孩子 */
      (*T)->RTag=Link;
  }
  return OK;
}

BiThrTree pre; /* 全局变量,始终指向刚刚访问过的结点 */

void InThreading(BiThrTree p)
{ 
  if(p)
  {
    InThreading(p->lchild); /* 递归左子树线索化 */
    if(!p->lchild) /* 没有左孩子 */
    {
      p->LTag=Thread; /* 前驱线索 */
      p->lchild=pre; /* 左孩子指针指向前驱 */
    }
    if(!pre->rchild) /* 前驱没有右孩子 */
    {
      pre->RTag=Thread; /* 后继线索 */
      pre->rchild=p; /* 前驱右孩子指针指向后继(当前结点p) */
    }
    pre=p; /* 保持pre指向p的前驱 */
    InThreading(p->rchild); /* 递归右子树线索化 */
  }
}

Status InOrderThreading(BiThrTree *Thrt,BiThrTree T)
{ /* 中序遍历二叉树T,并将其中序线索化,Thrt指向头结点。*/
  *Thrt=(BiThrTree)malloc(sizeof(BiThrNode));
  if(!*Thrt)
    exit(OVERFLOW);
  (*Thrt)->LTag=Link; /* 建头结点 */
  (*Thrt)->RTag=Thread;
  (*Thrt)->rchild=*Thrt; /* 右指针回指 */
  if(!T) /* 若二叉树空，则左指针回指 */
    (*Thrt)->lchild=*Thrt;
  else
  {
    (*Thrt)->lchild=T;
    pre=*Thrt;
    InThreading(T); /* 中序遍历进行中序线索化 */
    pre->rchild=*Thrt;
    pre->RTag=Thread; /* 最后一个结点线索化 */
    (*Thrt)->rchild=pre;
  }
  return OK;
}

Status InOrderTraverse_Thr(BiThrTree T,Status(*Visit)(char))
{ /* 中序遍历二叉线索树T(头结点)的非递归算法。*/
  BiThrTree p;
  p=T->lchild; /* p指向根结点 */
  while(p!=T)
  { /* 空树或遍历结束时,p==T */
    while(p->LTag==Link)
      p=p->lchild;
    if(!Visit(p->data)) /* 访问其左子树为空的结点 */
      return ERROR;
    while(p->RTag==Thread&&p->rchild!=T)
    {
      p=p->rchild;
      Visit(p->data); /* 访问后继结点 */
    }
    p=p->rchild;
  }
  return OK;
}

Status vi(char c)
{
  printf("%c ",c);
  return OK;
}
int main()
{
  BiThrTree H,T;
  printf("请按先序输入二叉树(如:ab三个空格表示a为根结点,b为左子树的二叉树)\n");
  CreateBiThrTree(&T); /* 按先序产生二叉树 */
  InOrderThreading(&H,T); /* 中序遍历，并中序线索化二叉树 */
  printf("中序遍历(输出)二叉线索树:\n");
  InOrderTraverse_Thr(H,vi); /* 中序遍历(输出)二叉线索树 */
  printf("\n");
  return 0;
}
