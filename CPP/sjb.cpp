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
 cout<<"�����������ʯͷ-����-����Ϸ,1����ʯͷ��2���������0����"<<endl;
 cout<<"----Loading----"<<endl;
 cout<<"Are you ready?yes or no(Y/N)";
 cin>>choose;
 if(choose!='N'&& choose!='n')
 {
  s++;
  int win(0),lose(0),draw(0),me,computer;
  do
  {
   cout<<"���������ѡ��"<<endl;
   cin>>me;
   srand((unsigned)time(NULL));
   cout<<"��������Ե��㷨��1���������2����ѭ��"<<endl;
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
       cout<<"���Գ�����ʯͷ�������Ҳ��ʯͷ���˾�Ϊƽ��"<<endl;
       draw++;
      }
      else if(me==2)
      {
       cout<<"���Գ�����ʯͷ��������Ǽ������ܲ��ң��˾�������"<<endl;
       lose++;
      }
      else if(me==0)
      {
       cout<<"���Գ�����ʯͷ��������ǲ�����ϲ�㣬�˾���Ӯ��"<<endl;
       win++;
      }
      break;
     case 2:
      if(me==1)
      {
       cout<<"���Գ����Ǽ������������ʯͷ����ϲ�㣬�˾���Ӯ��"<<endl;
      win++;
      }
      else if(me==2)
      {
       cout<<"���Գ����Ǽ����������Ҳ�Ǽ������˾�Ϊƽ��"<<endl;
       draw++;
      }
      else if(me==0)
      {
       cout<<"���Գ����Ǽ�����������ǲ����ܲ��ң��˾�������"<<endl;
       lose++;
      }
      break;
     case 3:
      if(me==1)
      {
       cout<<"���Գ����ǲ����������ʯͷ���ܲ��ң��˾�������"<<endl;
       lose++;
      }
      else if(me==2)
      {
       cout<<"���Գ����ǲ�������ļ�������ϲ�㣬�˾���Ӯ��"<<endl;
       win++;
      }
      else if(me==0)
      {
       cout<<"���Գ����ǲ��������Ҳ�ǲ����˾�Ϊƽ��"<<endl;
       draw++;
      }
      break;
  default :
   break;
   // computer=rand()%3+1;
   }
    cout<<"�㻹Ҫ������Yes/No(Y/N)"<<endl;
    cin>>h;
  }while(h!='N'&& h!='n');
  cout<<"��һ�������� "<<win+lose+draw<<"����Ϸ�����У�"<<endl;
  cout<<"��ʤ��"<<win<<"��"<<endl;
  cout<<"������"<<lose<<"��"<<endl;
  cout<<"��͵��Դ�ƽ"<<draw<<"��";
 }
}
