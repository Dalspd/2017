typedef struct node
{
     ElemType data;
    struct node * next;
}linknode,*linklist;

void connect(linklist &hc,linklist ha,linklist hb)
{//hb����׽��������ha������һ�����֮��hcָ�����Ӻ�ĵ�����
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
