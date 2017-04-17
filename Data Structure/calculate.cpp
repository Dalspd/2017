#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct cal{
 int*shuzi;
	int point;
}cal,*calp;
void Init_L(calp&L){														//初始化链表。
	L = (calp)malloc(sizeof(cal));
	L->shuzi = (int*)malloc(20 * sizeof(int));
	L->point = -1;
}
void cals(cal *L){													//对后缀表达式进行运算。
	char c;
	int transfer=0;
	while ((c = getchar()) != EOF){
		if (c == ' '){														//如果出现空格说明当前数字输入完毕。
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
			transfer = transfer * 10 + (c - '0');							//以防输入多位数字。
		}
	}
	cout << L->shuzi[0];													//输出结果。
}
int main(){
	calp new_L;
	Init_L(new_L);
	cals(new_L);
}
