#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct trans{
	char * fuhao;
	int point;
}trans,*transp;
void Init_L(transp &L){														//��ʼ����ŷ��ŵ�����
	L = (transp)malloc(sizeof(trans));
	L->fuhao = (char*)malloc(20 * sizeof(char));
	L->point = -1;
}
void Compelete_L(transp L){
	char perform[100];														//���������ڴ�����е�����ַ���
	int count = 0;
	char transfer;
	while ((transfer=getchar())!='$'){										//ֻҪ������ַ�����$�ͼ������롣
		if ((transfer == '*') || (transfer == '/') || (transfer == '+') || (transfer == '-') || (transfer == '(') || transfer == ')'){
			if ((transfer == '(')){											//��������ַ��Ƿ���ʱ���е����ķֱ�ô���
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
	while ((L->point) != -1){															//��ʣ������з���ȫ����� ��
		perform[count] = L->fuhao[L->point];
		count++;
		L->point--;
	}
	for (int i = 0; i < count; i++){													//�����Ÿ����ַ�����������ݡ�
		cout << perform[i]<<" ";
	}
}
int main(){
	transp new_L ;
	Init_L(new_L);
	Compelete_L(new_L);
}
