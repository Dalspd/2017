#define NULL 0
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
int op;
typedef struct
{
     int coef;//系数
     int expn;//指数
}term;
 
typedef struct Lnode
{
    term data;
    Lnode *next;
}*Link,*Linklist;
 
int cmp(term a,term b)//将指数从小到大排序
{
    if (a.expn==b.expn)
        return 0;
    else
        return (a.expn-b.expn)/abs(a.expn-b.expn);
}
void Orderinsert(Linklist &L,term e,int (*comp)(term,term))//直接将输入的项数和指数放入链表（没有可以合并的项）
{
    Link o,p,q;
    q=L;
    p=q->next;
    while (p&&comp(p->data,e)<0)
    {
        q=p;
        p=p->next;
    }
    o=(Link)malloc(sizeof(Lnode));
    o->data=e;
    q->next=o;
    o->next=p;
}
void chengfa(Linklist &L1,Linklist &L2,Linklist &L3)//相乘两个多项式
{
    L3 = (Link)malloc(sizeof(Lnode));
    L3->next = NULL;
    Link S = L1->next;
    term s, e;
    while(S)
    {
        s.coef=S->data.coef;
        s.expn=S->data.expn;
        Link Q=L2->next;
        while(Q)
        {
            e.coef = s.coef * Q->data.coef;
            e.expn = s.expn + Q->data.expn;
            Orderinsert(L3,e,cmp);
            Q=Q->next;
        }
        S=S->next;
    }
}
int LocateElem(Linklist L,term e,Link &s,Link &q,int (*comp)(term,term))//判断是否有可以合并的项
{
    Link p;
    s=L;
    p=s->next;
    while (p&&comp(p->data,e)!=0)
    {
        s=p;
        p=p->next;
    }
    if(!p)
    {
        s=q=NULL;
        return 0;
    }
    else
    {
        q=p;
        return 1;
    }
}
void Delnext(Linklist &L,Link s)
{
    Link q=s->next;
     s->next=q->next;
     free(q);
}
 
void Orderinsertmerge(Linklist &L,term e,int (*compara)(term,term))//将同一个多项式里相同的项合并
{
    Link q,s;
    if (LocateElem(L,e,s,q,compara))
    {
        q->data.coef+=e.coef;
        if (!q->data.coef)
        {
          Delnext(L,s);
        }
    }
    else   
        Orderinsert(L,e,compara);
}
 
void Creatpolyn (Linklist &p,int m)//输入多项式的系数和指数
{
     term e;
     int i;
     p=(Link)malloc(sizeof(Lnode));//给链表开拓空间
     p->next=NULL;
     printf("\n请输入%d个系数和指数,用空格符间隔：\n",m*2);
     for(i=1;i<=m;i++)
    {
        scanf("%d%d",&e.coef,&e.expn);
        Orderinsertmerge(p,e,cmp);//将输入的多项式中可以合并的项合并
    }
}
void add(Linklist &La,Linklist Lb)//相加两个多项式
{
    Link qb;term b;
     qb=Lb->next;
     while(qb)
     {
         b=qb->data;
         Orderinsertmerge(La,b,cmp);
         qb=qb->next;
     }
     //销毁链表Lb
}
void fuzhi(Linklist &Lc,Linklist La)
{
    Lc=(Link)malloc(sizeof(Lnode));
    Lc->next=NULL;
    Link S=La->next;
    term e;
    while(S)
    {
        e.coef=S->data.coef;
        e.expn=S->data.expn;
        Orderinsertmerge(Lc,e,cmp);
        S=S->next;
    }
}
void printpolyn(Linklist p)//打印出相加后的多项式
{  
    Link q;
    q=p->next;
    int t=0;
    while(q)
    {
        if(t==0)
        {
            if(q->data.coef==1)
                printf("x^%d",q->data.expn);
            else if(q->data.coef==-1)
                printf("-x^%d",q->data.expn);
            else if(q->data.coef>0)
                printf("%d*x^%d",q->data.coef,q->data.expn);
            else if(q->data.coef<0)
                printf("%d*x^%d",q->data.coef,q->data.expn);
        }
        else
        {
            if(q->data.coef==1)
                printf("+x^%d",q->data.expn);
            else if(q->data.coef==-1)
                printf("-x^%d",q->data.expn);
            else if(q->data.coef>0)
                printf("+%d*x^%d",q->data.coef,q->data.expn);
            else if(q->data.coef<0)
                printf("%d*x^%d",q->data.coef,q->data.expn);
        }
        q=q->next;
        t++;
    }
}
int main()
{
    int x;
    Linklist L1,L2,L3,L4;
    printf("\n请输入第一个一元多项式的项数:");
    scanf("%d",&x);
    Creatpolyn(L1,x);
    printf("\n请输入第二个一元多项式的项数:");
    scanf("%d",&x);
    Creatpolyn(L2,x);
    fuzhi(L3,L1);
    printf("\n相加以后的一元多项式为：\n");
	add(L3,L2);
	printpolyn(L3);
    printf("\n相乘以后的一元多项式为：\n");
    chengfa(L1,L2,L3);
    fuzhi(L4,L3);
    printpolyn(L4);
    return 0;
}
