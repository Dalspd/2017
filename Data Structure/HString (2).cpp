#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

typedef struct
{
	char ch[40];
	int length;
}HString;

int InitStr(HString &T)
{
	T.length = 0;
	return 0;
}

int StrAssign(HString &S, char *chars)
{
	int i = 0, j;
	/*if (S.ch != NULL)
		free(S.ch);*/
	while (chars[i] != '\0')
		i++;
	if (!i)
	{
		S.length = 0;
	}
	else
	{
		for (j = 0; j<i; j++)
			S.ch[j] = chars[j];
		S.length = i;
	}
	return 0;
}

int StrLength(HString T)
{
	return T.length;
}

int PrintStr(HString T)
{
	for (int i = 0; i <= T.length; i++)
		cout << T.ch[i];
	return 0;
}

int Concat(HString &T, HString s1, HString s2)//TΪS1��S2������ɵ��´� 
{
	//if (T.ch) free(T.ch);
	for (int i = 0; i <= s1.length - 1; i++)
		T.ch[i] = s1.ch[i];
	T.length = s1.length + s2.length;
	for (int i = 0; i <= s2.length - 1; i++)
		T.ch[i + s1.length] = s2.ch[i];
	PrintStr(T);
	return 0;
}

int SubString(HString &Sub, HString S, int pos, int len)//ȡ�Ӵ� 
{
	if (pos<1 || pos>S.length || len<0 || len>S.length - pos + 1)
	{
		cout << "ERROR";
		return 0;
	}
	if (Sub.ch) free(Sub.ch);
	if (!len) { Sub.length = 0; }
	else
	{

		for (int i = 0; i <= len - 1; i++)
			Sub.ch[i] = S.ch[pos + i - 1];
		Sub.length = len;
	}
	return 0;
}

int main()
{
	HString Sub, T, s1, s2;
	int a, b;
	char s[100], t[100];
	InitStr(T); InitStr(s1);InitStr(s2);
	cout << "�����봮1:";
	gets(s);
	cout << "�����봮2:";
	gets(t);
	StrAssign(s1, s);
	StrAssign(s2, t);
	cout << "�ϲ���Ϊ:";
	Concat(T, s1, s2);
	cout << "\n������Ҫȡ���Ӵ���λ�ü�����:";
	cin >> a >> b;
	SubString(Sub, T, a, b);
	cout << "�Ӵ�Ϊ:";
	PrintStr(Sub);
	return 0;
}

