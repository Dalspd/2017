#include<stdio.h>
#include<stdlib.h>

typedef struct HTNode{
	int data;
	struct HTNode *left,*right; 
}HTNode,*HTree;

void PrintTree(HTree T){
	if(T!=NULL){
		printf("%d",T->data);
		if(T->left!=NULL||T->right!=NULL){
			printf("(");
			PrintTree(T->left);
			if(T->right!=NULL)
			printf(",");
			PrintTree(T->right);
			printf(")");
		}
	}
}

HTree CreateHuffman(int a[100],int n){
	int i,j;
	HTree *b,q;
	b=(HTree*)malloc(n*sizeof(HTNode));
	for(i=0;i<n;i++){
		b[i]=(HTree)malloc(sizeof(HTNode));
		b[i]->data=a[i];
		b[i]->left=b[i]->right=NULL;
	}
	for(i=1;i<n;i++){
		int k1=-1,k2;
		for(j=0;j<n;j++){
			if(b[j]!=NULL && k1==-1){
				k1=j;
				continue;
			}
			if(b[j]!=NULL){
				k2=j;
				break;
			}
		}
		for(j=k2;j<n;j++){
			if(b[j]!=NULL){
				if(b[j]->data<b[k1]->data){
					k2=k1;
					k1=j;
				}
				else if(b[j]->data<b[k2]->data)
				k2=j;
			}
		}
		q=(HTree)malloc(sizeof(HTNode));
		q->data=b[k1]->data+b[k2]->data;
		q->left=b[k1];
		q->right=b[k2];
		
		b[k1]=q;
		b[k2]=NULL;
	}
	free(b);
	return q;
}

int WPL(HTree FBT,int len){
	if(FBT==NULL)
	return 0;
	else{
		if(FBT->left==NULL&&FBT->right==NULL)
		return FBT->data*len;
		else
		return WPL(FBT->left,len+1)+WPL(FBT->right,len+1);
	}
}

int main(){
	int n,i;
	int *a;
	HTree fbt;
	printf("请输入要构造的哈夫曼树中带权叶子节点数：");
	while(1){
		scanf("%d",&n);
		if(n>1)
		  break;
		else
		  printf("重新输入n值：");
	}
	a=(int*)malloc(n*sizeof(HTNode));
	printf("请输入%d个数作为权值：",n);
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	fbt=CreateHuffman(a,n);
	printf("广义表形式的哈夫曼树：");
	PrintTree(fbt);
	printf("\nWPL=%d",WPL(fbt,0));
	return 0;   
}

