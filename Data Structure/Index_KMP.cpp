#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

#define MAXSTRLEN 255
typedef unsigned char SString[MAXSTRLEN + 1];

int StrAssign(SString &T)
{
	char s[MAXSTRLEN];
	cout<<"������һ���ַ���:";
	cin>>s;
	T[0]=strlen(s);
	for(int i=1;i<=MAXSTRLEN;i++)
	  T[i]=s[i-1];
	return 0;
}

int get_nextval(SString T,int nextval[MAXSTRLEN])//get_nextval
{
	int i=1,j=0;
	nextval[0]=0;
	while(i<T[0]){
		if(j==0||T[i]==T[j]){
			++i;
			++j;
		if(T[i]!=T[j]) nextval[i]=j;
		else nextval[i]=nextval[j];
		}
	else j=nextval[j];
	}
}

int Index_KMP(SString S,SString T,int nextval[MAXSTRLEN])//KMP�㷨 
{
	int i=1,j=1;
	get_nextval(T,nextval);
	while(i<=S[0] && j<=T[0]){
		if(j==0||S[i]==T[j]){
			++i;
			++j;
		}
		else j=nextval[j];
	} 
	if(j>T[0]) return i-T[0];
	else return 0;
}

int main()
{
	SString a,b;
	cout<<"����-";
	StrAssign(a);
	cout<<"ģʽ-";
	StrAssign(b);
	int nextval[MAXSTRLEN];
	//get_nextval(b,nextval[]);
	int result=Index_KMP(a,b,nextval);
	if(result==0) cout<<"δ�ҵ�";
	else cout<<"�ӵ�"<<result<<"λ���Ӵ�ƥ��";
	return 0;
}
