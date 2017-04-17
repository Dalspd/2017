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
  struct BiThrNode *lchild,*rchild; /* ���Һ���ָ�� */
  PointerTag LTag,RTag; /* ���ұ�־ */
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
    (*T)->data=h; /* ���ɸ����(����) */
    CreateBiThrTree(&(*T)->lchild); /* �ݹ鹹�������� */
    if((*T)->lchild) /* ������ */
      (*T)->LTag=Link;
    CreateBiThrTree(&(*T)->rchild); /* �ݹ鹹�������� */
    if((*T)->rchild) /* ���Һ��� */
      (*T)->RTag=Link;
  }
  return OK;
}

BiThrTree pre; /* ȫ�ֱ���,ʼ��ָ��ոշ��ʹ��Ľ�� */

void InThreading(BiThrTree p)
{ 
  if(p)
  {
    InThreading(p->lchild); /* �ݹ������������� */
    if(!p->lchild) /* û������ */
    {
      p->LTag=Thread; /* ǰ������ */
      p->lchild=pre; /* ����ָ��ָ��ǰ�� */
    }
    if(!pre->rchild) /* ǰ��û���Һ��� */
    {
      pre->RTag=Thread; /* ������� */
      pre->rchild=p; /* ǰ���Һ���ָ��ָ����(��ǰ���p) */
    }
    pre=p; /* ����preָ��p��ǰ�� */
    InThreading(p->rchild); /* �ݹ������������� */
  }
}

Status InOrderThreading(BiThrTree *Thrt,BiThrTree T)
{ /* �������������T,����������������,Thrtָ��ͷ��㡣*/
  *Thrt=(BiThrTree)malloc(sizeof(BiThrNode));
  if(!*Thrt)
    exit(OVERFLOW);
  (*Thrt)->LTag=Link; /* ��ͷ��� */
  (*Thrt)->RTag=Thread;
  (*Thrt)->rchild=*Thrt; /* ��ָ���ָ */
  if(!T) /* ���������գ�����ָ���ָ */
    (*Thrt)->lchild=*Thrt;
  else
  {
    (*Thrt)->lchild=T;
    pre=*Thrt;
    InThreading(T); /* ��������������������� */
    pre->rchild=*Thrt;
    pre->RTag=Thread; /* ���һ����������� */
    (*Thrt)->rchild=pre;
  }
  return OK;
}

Status InOrderTraverse_Thr(BiThrTree T,Status(*Visit)(char))
{ /* �����������������T(ͷ���)�ķǵݹ��㷨��*/
  BiThrTree p;
  p=T->lchild; /* pָ������ */
  while(p!=T)
  { /* �������������ʱ,p==T */
    while(p->LTag==Link)
      p=p->lchild;
    if(!Visit(p->data)) /* ������������Ϊ�յĽ�� */
      return ERROR;
    while(p->RTag==Thread&&p->rchild!=T)
    {
      p=p->rchild;
      Visit(p->data); /* ���ʺ�̽�� */
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
  printf("�밴�������������(��:ab�����ո��ʾaΪ�����,bΪ�������Ķ�����)\n");
  CreateBiThrTree(&T); /* ��������������� */
  InOrderThreading(&H,T); /* ��������������������������� */
  printf("�������(���)����������:\n");
  InOrderTraverse_Thr(H,vi); /* �������(���)���������� */
  printf("\n");
  return 0;
}
