#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct cal{
 int*shuzi;
	int point;
}cal,*calp;
void Init_L(calp&L){														//��ʼ������
	L = (calp)malloc(sizeof(cal));
	L->shuzi = (int*)malloc(20 * sizeof(int));
	L->point = -1;
}
void cals(cal *L){													//�Ժ�׺���ʽ�������㡣
	char c;
	int transfer=0;
	while ((c = getchar()) != EOF){
		if (c == ' '){														//������ֿո�˵����ǰ����������ϡ�
			L->shuzi[L->point + 1] = transfer;
			L->point++;
			transfer = 0;
		}
		else if (c == '+' || c == '*' || c == '/' || c == '-'){
			if (c == '+'){
				transfer = L->shuzi[L->point] + L->shuzi[L->point - 1];
				L->point--;
				L->shuzi[L->point] = transfer;
				transfer = 0;
			}
			else if (c=='-'){
				transfer = L->shuzi[L->point] - L->shuzi[L->point - 1];
				L->point--;
				L->shuzi[L->point] = transfer;
				transfer = 0;
			}
			else if (c == '*'){
				transfer = L->shuzi[L->point] * L->shuzi[L->point - 1];
				L->point--;
				L->shuzi[L->point] = transfer;
				transfer = 0;
			}
			else if (c == '/'){
				transfer = L->shuzi[L->point] * L->shuzi[L->point - 1];
				L->point--;
				L->shuzi[L->point] = transfer;
				transfer = 0;
			}
		}
		else{
			transfer = transfer * 10 + (c - '0');							//�Է������λ���֡�
		}
	}
	cout << L->shuzi[0];													//��������
}
int main(){
	calp new_L;
	Init_L(new_L);
	cals(new_L);
}
