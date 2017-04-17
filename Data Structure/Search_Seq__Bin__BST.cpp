#include<stdio.h>
#include<stdlib.h>

#define FALSE 0
#define TRUE 1

typedef int KeyType;

typedef struct{
	KeyType key;
}ElemType; 

typedef struct{
	ElemType* elem;
	int length;
}SSTable;

int CreateSSTable(SSTable &T,int n){
	T.elem=(ElemType*)malloc((n+1)*sizeof(ElemType));
	T.length=n;
	for(int i=1;i<=T.length;i++) scanf("%d",&T.elem[i].key);
	return 0;
}

typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

int Search_Seq(SSTable T,KeyType key){
	T.elem[0].key=key;
	int i=T.length;
	while(key!=T.elem[i].key)
		--i;
	return i;	
}//Sequential Search

int Search_Bin(SSTable T,KeyType key){
	int low=1,high=T.length,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(key==T.elem[mid].key) return mid;
		else if(key<T.elem[mid].key) high=mid-1;
		else low=mid+1;
	}
	return 0;
}//Binary Search

int SearchBST(BiTree T,KeyType key,BiTree f,BiTree &p){
	if(!T) {p=f; return FALSE;}
	else if(key==T->data.key) {p=T; return TRUE;}
	else if(key<T->data.key) return SearchBST(T->lchild,key,T,p);
	else return SearchBST(T->rchild,key,T,p);
}//SearchBST

int InsertBST(BiTree &T,ElemType e,BiTree p){
	if(!SearchBST(T,e.key,NULL,p)){
		BiTree s=(BiTree)malloc(sizeof(BiTNode));
		s->data=e; s->lchild=s->rchild=NULL;
		if(!p) T=s;
		else if(e.key<T->data.key) p->lchild=s;
		else p->rchild=s;
		return TRUE;
	}
	else return FALSE;
}//InsertBST

int main(){
	int i,n,key,res;
	ElemType e;
	SSTable ST;
	BiTree BT,f,p;
	while(1)
    {
    printf("\nSearch Operations\n");
    printf("===============\n");
    printf("1.Sequential Search\n");
    printf("2.Binary Search\n");
    printf("3.SearchBST\n");
    printf("4.InsertBST\n");
    printf("5.Exit\n");
    printf("Enter your choice : ");
    if(scanf("%d",&i)<=0){
        printf("Enter only an Integer\n");
        exit(0);
    } else {
        switch(i)
        {
        case 1:  printf("Please input the quantity of the Table,and which number to search:\n");
                 scanf("%d",&ST.length);
				 scanf("%d",&key);
				 printf("Create a SSTable(Disorder):\n");
                 CreateSSTable(ST,ST.length);
                 res=Search_Seq(ST,key);
                 printf("Search result is(0 if not found): %d \n",res);
                 break;
        case 2:  printf("Please input the quantity of the Table,and which number to search:\n");
                 scanf("%d",&ST.length);
				 scanf("%d",&key);
				 printf("Create a SSTable(Inorder):\n");
                 CreateSSTable(ST,ST.length);
                 res=Search_Bin(ST,key);
                 printf("Search result is(0 if not found): %d \n",res);
                 break;
        case 3:  printf("Enter the number you want to search:");
                 scanf("%d",&key);
                 res=SearchBST(BT,key,f,p);
		         printf("Search result is(0 for not found,1 for found): %d \n",res);
				 break;   
        case 4:     
		        printf("Enter the number you want to insert:");
		        scanf("%d",&e);
				InsertBST(BT,e,p);
                break;
        case 5:     return 0;
        default:    printf("Invalid option\n");
        }
    }
    }
    return 0;
}
