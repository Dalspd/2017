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

int StrLength(SString T)
{
	int n;
	for(int i=0;i<MAXSTRLEN;i++)
		if(T[i]=='\0')
		{
			n=i;
			break;
		}
	return (n);
}

int PrintStr(SString T)
{
	for(int i=1;i<=T[0];i++)
	  cout<<T[i];
}

int Concat(SString &T,SString s1,SString s2)//TΪS1��S2������ɵ��´� 
{
	if(s1[0]+s2[0]<=MAXSTRLEN)
	{
		T[0]=s1[0]+s2[0];
		for(int i=1;i<=s1[0];i++)
		  T[i]=s1[i];
		for(int i=1;i<=s2[0];i++)
		  T[s1[0]+i]=s2[i];  
	 } 
	else if(s1[0]<MAXSTRLEN) 
	{
		T[0]=MAXSTRLEN;
		for(int i=1;i<=s1[0];i++)
		  T[i]=s1[i];
		for(int i=1;i<=(MAXSTRLEN-s1[0]);i++)
		  T[s1[0]+i]=s2[i];   
	}
	else
	{
	  T[0]=MAXSTRLEN;
	  for(int i=0;i<=MAXSTRLEN;i++)
		  T[i]=s1[i];  
	} 
	PrintStr(T);
	return 0;
}

int SubString(SString &Sub,SString S,int pos,int len)
{
	if(pos<1||pos>S[0]||len<0||len>S[0]-pos+1)
	  {
	   cout<<"ERROR";
	   return 0;
      }
      for(int i=1;i<=len;i++)
        Sub[i]=S[pos+i-1];
      Sub[0]=len;
	  return 0;  
}

int main()
{
	SString Sub,T,s1,s2;
	int a,b;
	cout<<"�����봮1��";
	StrAssign(s1);
	cout<<"�����봮2��";
	StrAssign(s2);
	cout<<"�ϲ���Ϊ:" ;
	Concat(T,s1,s2);
	cout<<"\n������Ҫȡ���ִ���λ�ü�����:";
	cin>>a>>b;
	SubString(Sub,T,a,b);
	cout<<"�Ӵ�Ϊ:"; 
	PrintStr(Sub);
	return 0;
}
