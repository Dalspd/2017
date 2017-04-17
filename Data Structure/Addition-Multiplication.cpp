#define NULL 0
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
int op;
typedef struct
{
     int coef;//ϵ��
     int expn;//ָ��
}term;
 
typedef struct Lnode
{
    term data;
    Lnode *next;
}*Link,*Linklist;
 
int cmp(term a,term b)//��ָ����С��������
{
    if (a.expn==b.expn)
        return 0;
    else
        return (a.expn-b.expn)/abs(a.expn-b.expn);
}
void Orderinsert(Linklist &L,term e,int (*comp)(term,term))//ֱ�ӽ������������ָ����������û�п��Ժϲ����
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
void chengfa(Linklist &L1,Linklist &L2,Linklist &L3)//�����������ʽ
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
int LocateElem(Linklist L,term e,Link &s,Link &q,int (*comp)(term,term))//�ж��Ƿ��п��Ժϲ�����
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
 
void Orderinsertmerge(Linklist &L,term e,int (*compara)(term,term))//��ͬһ������ʽ����ͬ����ϲ�
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
 
void Creatpolyn (Linklist &p,int m)//�������ʽ��ϵ����ָ��
{
     term e;
     int i;
     p=(Link)malloc(sizeof(Lnode));//�������ؿռ�
     p->next=NULL;
     printf("\n������%d��ϵ����ָ��,�ÿո�������\n",m*2);
     for(i=1;i<=m;i++)
    {
        scanf("%d%d",&e.coef,&e.expn);
        Orderinsertmerge(p,e,cmp);//������Ķ���ʽ�п��Ժϲ�����ϲ�
    }
}
void add(Linklist &La,Linklist Lb)//�����������ʽ
{
    Link qb;term b;
     qb=Lb->next;
     while(qb)
     {
         b=qb->data;
         Orderinsertmerge(La,b,cmp);
         qb=qb->next;
     }
     //��������Lb
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
void printpolyn(Linklist p)//��ӡ����Ӻ�Ķ���ʽ
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
    printf("\n�������һ��һԪ����ʽ������:");
    scanf("%d",&x);
    Creatpolyn(L1,x);
    printf("\n������ڶ���һԪ����ʽ������:");
    scanf("%d",&x);
    Creatpolyn(L2,x);
    fuzhi(L3,L1);
    printf("\n����Ժ��һԪ����ʽΪ��\n");
	add(L3,L2);
	printpolyn(L3);
    printf("\n����Ժ��һԪ����ʽΪ��\n");
    chengfa(L1,L2,L3);
    fuzhi(L4,L3);
    printpolyn(L4);
    return 0;
}
