#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct bracket{
	char data;
	struct bracket *next;
}bracket,*bracketp;
void Init_L(bracketp & L){											//��ʼ���洢���ŵ�����
	L = (bracketp)malloc(sizeof(bracket));
	if (L == NULL){
		cout << "�ڴ�ռ䲻�㣬�޷���ʼ��" << endl;
		exit (0);
	}
	L->next = NULL;
}
void Input_L(bracketp L){											//��������ַ��������жϡ�
	char c;
	bracketp p = L;
	while ((c = getchar()) != EOF){
		if ((c == '(') || (c == '[') || (c == '{')){				//�������е������Ų������жϡ�
			bracketp transfer = (bracketp)malloc(sizeof(bracket));
			if (transfer == NULL){
				cout << "�ڴ�ռ䲻�㣬�޷���ʼ��" << endl;
				exit(0);
			}
			transfer->data = c;
			if (L->next == NULL){
				L->next = transfer;
				transfer->next = NULL;
			}
			else{
				transfer->next = p->next;
				p->next = transfer;
			}
		}
		if (c == ')'){												//��������if����Ӧ�������ŵĲ�����
			if (L->next == NULL){
				cout << "���Ų�ƥ��" << endl;
				exit(0);
			}
			if (p->next->data == '('){
				if (p->next->next == NULL){
					delete p->next;
					p->next = NULL;
				}
				else{
					bracketp stransfer = p->next;
					p->next = p->next->next;
					delete stransfer;
				}
			}
			else{
				cout << "���Ų�ƥ��" << endl;
				exit(0);
			}
		}
		if (c == ']'){
			if (L->next == NULL){
				cout << "���Ų�ƥ��" << endl;
				exit(0);
			}
			if (p->next->data == '['){
				if (p->next->next == NULL){
					delete p->next;
					p->next = NULL;
				}
				else{
					bracketp stransfer = p->next;
					p->next = p->next->next;
					delete stransfer;
				}
			}
			else{
				cout << "���Ų�ƥ��" << endl;
				exit(0);
			}
		}
		if (c == '}'){
			if (L->next == NULL){
				cout << "���Ų�ƥ��" << endl;
				exit(0);
			}
			if (p->next->data == '{'){
				if (p->next->next == NULL){
					delete p->next;
					p->next = NULL;
				}
				else{
					bracketp stransfer = p->next;
					p->next = p->next->next;
					delete stransfer;
				}
			}
			else{												//���û���ҵ���������ƥ������������
				cout << "���Ų�ƥ��" << endl;
				exit(0);
			}
		}

	}
	if (L->next == NULL){										//���ջ���Ѿ�û��Ԫ��˵����ȫƥ�䡣
		cout << "������������ƥ��" << endl;
	}
	else{
		cout << "���Ų�ƥ��" << endl;
	}
}
int main(){
	bracketp new_L;
	Init_L(new_L);
	Input_L(new_L);
}
