#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct bracket{
	char data;
	struct bracket *next;
}bracket,*bracketp;
void Init_L(bracketp & L){											//初始化存储括号的链表。
	L = (bracketp)malloc(sizeof(bracket));
	if (L == NULL){
		cout << "内存空间不足，无法初始化" << endl;
		exit (0);
	}
	L->next = NULL;
}
void Input_L(bracketp L){											//输入各个字符并进行判断。
	char c;
	bracketp p = L;
	while ((c = getchar()) != EOF){
		if ((c == '(') || (c == '[') || (c == '{')){				//对于所有的左括号不进行判断。
			bracketp transfer = (bracketp)malloc(sizeof(bracket));
			if (transfer == NULL){
				cout << "内存空间不足，无法初始化" << endl;
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
		if (c == ')'){												//以下三个if语句对应对有括号的操作。
			if (L->next == NULL){
				cout << "括号不匹配" << endl;
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
				cout << "括号不匹配" << endl;
				exit(0);
			}
		}
		if (c == ']'){
			if (L->next == NULL){
				cout << "括号不匹配" << endl;
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
				cout << "括号不匹配" << endl;
				exit(0);
			}
		}
		if (c == '}'){
			if (L->next == NULL){
				cout << "括号不匹配" << endl;
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
			else{												//如果没有找到与右括号匹配的括号输出。
				cout << "括号不匹配" << endl;
				exit(0);
			}
		}

	}
	if (L->next == NULL){										//如果栈内已经没有元素说明完全匹配。
		cout << "本段文字括号匹配" << endl;
	}
	else{
		cout << "括号不匹配" << endl;
	}
}
int main(){
	bracketp new_L;
	Init_L(new_L);
	Input_L(new_L);
}
