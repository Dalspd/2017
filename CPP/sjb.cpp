#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
char s;
class Suiji{
	public:
	int computer=rand()%3;
};
class Loop{
	public:
    int computer=s%3;
};
int main()
{
 char choose,h,t,s=0;
 cout<<endl;
 cout<<"即将载入的是石头-剪刀-布游戏,1代表石头，2代表剪刀，0代表布"<<endl;
 cout<<"----Loading----"<<endl;
 cout<<"Are you ready?yes or no(Y/N)";
 cin>>choose;
 if(choose!='N'&& choose!='n')
 {
  s++;
  int win(0),lose(0),draw(0),me,computer;
  do
  {
   cout<<"请输入你的选择："<<endl;
   cin>>me;
   srand((unsigned)time(NULL));
   cout<<"请输入电脑的算法，1代表随机，2代表循环"<<endl;
   cin>>t;
 switch(t)
 {
  case 1:Suiji();
  case 2:Loop();
 }
    switch(computer)
    {
     case 1:
      if(me==1)
      {
       cout<<"电脑出的是石头，你出的也是石头，此局为平局"<<endl;
       draw++;
      }
      else if(me==2)
      {
       cout<<"电脑出的是石头，你出的是剪刀，很不幸，此局你输了"<<endl;
       lose++;
      }
      else if(me==0)
      {
       cout<<"电脑出的是石头，你出的是布，恭喜你，此局你赢了"<<endl;
       win++;
      }
      break;
     case 2:
      if(me==1)
      {
       cout<<"电脑出的是剪刀，你出的是石头，恭喜你，此局你赢了"<<endl;
      win++;
      }
      else if(me==2)
      {
       cout<<"电脑出的是剪刀，你出的也是剪刀，此局为平局"<<endl;
       draw++;
      }
      else if(me==0)
      {
       cout<<"电脑出的是剪刀，你出的是布，很不幸，此局你输了"<<endl;
       lose++;
      }
      break;
     case 3:
      if(me==1)
      {
       cout<<"电脑出的是布，你出的是石头，很不幸，此局你输了"<<endl;
       lose++;
      }
      else if(me==2)
      {
       cout<<"电脑出的是布，你出的剪刀，恭喜你，此局你赢了"<<endl;
       win++;
      }
      else if(me==0)
      {
       cout<<"电脑出的是布，你出的也是布，此局为平局"<<endl;
       draw++;
      }
      break;
  default :
   break;
   // computer=rand()%3+1;
   }
    cout<<"你还要继续吗？Yes/No(Y/N)"<<endl;
    cin>>h;
  }while(h!='N'&& h!='n');
  cout<<"你一共进行了 "<<win+lose+draw<<"次游戏，其中："<<endl;
  cout<<"你胜出"<<win<<"次"<<endl;
  cout<<"你输了"<<lose<<"次"<<endl;
  cout<<"你和电脑打平"<<draw<<"次";
 }
}
