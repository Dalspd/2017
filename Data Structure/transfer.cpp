#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct trans{
	char * fuhao;
	int point;
}trans,*transp;
void Init_L(transp &L){														//初始化存放符号的链表。
	L = (transp)malloc(sizeof(trans));
	L->fuhao = (char*)malloc(20 * sizeof(char));
	L->point = -1;
}
void Compelete_L(transp L){
	char perform[100];														//此数组用于存放所有的输出字符。
	int count = 0;
	char transfer;
	while ((transfer=getchar())!='$'){										//只要读入的字符不是$就继续读入。
		if ((transfer == '*') || (transfer == '/') || (transfer == '+') || (transfer == '-') || (transfer == '(') || transfer == ')'){
			if ((transfer == '(')){											//当读入的字符是符号时进行单独的分别得处理。
				L->fuhao[L->point + 1] = transfer;
				L->point++;
			}else if ((transfer == ')')){
				while ((L->point) != -1 && L->fuhao[L->point+1]!='('){
					if (L->fuhao[L->point] == '('){
						L->point--;
						//continue;
						break;
					}
					perform[count] = L->fuhao[L->point];
					count++;
					L->point--;
				}
			}else if ((transfer == '*') || (transfer == '/')){
					L->fuhao[L->point + 1] = transfer;
					L->point++;
			}else if ((transfer == '+') || (transfer == '-')){
				if (L->fuhao[L->point] == '('){
					L->fuhao[L->point + 1] = transfer;
					L->point++;
				}else if ((L->fuhao[L->point] == '*') || (L->fuhao[L->point] == '/')){
					while (((L->point) != -1) && (L->fuhao[L->point]!='(')){
						perform[count] = L->fuhao[L->point];
						count++;
						L->point--;
					}
					L->fuhao[L->point + 1] = transfer;
					L->point++;
				}
				else{
					L->fuhao[L->point + 1] = transfer;
					L->point++;
				}
			}
		}
		else{
			perform[count] = transfer;
			++count;
		}
	}
	while ((L->point) != -1){															//对剩余的所有符号全部输出 。
		perform[count] = L->fuhao[L->point];
		count++;
		L->point--;
	}
	for (int i = 0; i < count; i++){													//输出存放各种字符的数组的内容。
		cout << perform[i]<<" ";
	}
}
int main(){
	transp new_L ;
	Init_L(new_L);
	Compelete_L(new_L);
}
