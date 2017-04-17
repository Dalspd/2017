typedef struct node
{
     ElemType data;
    struct node * next;
}linknode,*linklist;

void connect(linklist &hc,linklist ha,linklist hb)
{//hb表的首结点连接在ha表的最后一个结点之后，hc指向连接后的单链表。
   int m,n;
   linknode *p;
   if(m<=n)
   {
   hc=ha;
    p=ha;
   while(p->next!=NULL)
   {
         p=p->next;
    }
   p->next=hb->next;
   }
   else
   {
   	hc=hb;
    p=hb;
   while(p->next!=NULL)
   {
         p=p->next;
    }
   p->next=ha->next;
   }
}
