#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

typedef struct
{
	char *ch;
	int length;
}HString;

int StrAssign(HString &T)
{
	char chars[100];
	cin>>chars;
	int i;
	char *c;
	if(T.ch) free(T.ch);
	for(i=0,c=chars;c;++i,++c);
	  if(!i){T.ch=NULL; T.length=0;}
	  else 
	  {
	  	for(int x=0;x<=i-1;x++)
	  	  T.ch[x]=chars[x];
	  	T.length=i;  
	  }
	return 0;
}

int StrLength(HString T)
{
	return T.length;
}

int PrintStr(HString T)
{
	for(int i=0;i<=T.length;i++)
	  cout<<T.ch[i];
}

int Concat(HString &T,HString s1,HString s2)//T为S1和S2联结而成的新串 
{
	if(T.ch) free(T.ch);
		for(int i=0;i<=s1.length-1;i++)
		  T.ch[i]=s1.ch[i];
		T.length=s1.length+s2.length;
		for(int i=0;i<=s2.length-1;i++)
		  T.ch[i+s1.length]=s2.ch[i];
	PrintStr(T);
	return 0;
}

int SubString(HString &Sub,HString S,int pos,int len)
{
	if(pos<1||pos>S.length||len<0||len>S.length-pos+1)
	  {
	   cout<<"ERROR";
	   return 0;
      }
      if(Sub.ch) free(Sub.ch);
	  if(!len) {Sub.ch=NULL; Sub.length=0;}
	  else
	  {
	  	Sub.ch=(char*) malloc (len*sizeof(char));
	  for(int i=0;i<=len-1;i++)
        Sub.ch[i]=S.ch[pos+i-1];
      Sub.length=len;
      }
	  return 0;  
}

int main()
{
	HString Sub,T,s1,s2;
	int a,b;
	cout<<"请输入串1:";
	StrAssign(s1);
	cout<<"请输入串2:";
	StrAssign(s2);
	cout<<"合并串为:" ;
	Concat(T,s1,s2);
	cout<<"\n请输入要取的字串的位置及长度:";
	cin>>a>>b;
	SubString(Sub,T,a,b);
	cout<<"子串为:"; 
	PrintStr(Sub);
	return 0;
}
