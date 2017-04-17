#include<stdio.h>
#define FORMAT "%d %s %f %f %f"
struct Student
{
	int num;
	char name[20];
	float score1,score2,score3;
	float aver,all;
};
	struct Student stu[10];
int main()
{
	int *p;

	int t,flag=0,i,m=0;
	void input(struct Student stu[]);
	void output(struct Student stu[]);
	for(i=0;i<10;i++)
	  t+=stu[i].aver;
	t/=10;
	printf("Average=%f",t);
	for(i=0;i<10;i++)
		if(stu[i].aver>stu[m].aver) m=i;
	printf("%3d %20s %3f %3f %3f %3f %3f",stu[m].num,stu[m].name,stu[m].score1,stu[m].score2,stu[m].score3,stu[m].all,stu[m].aver);	  
    return 0;
}
void input(struct Student stu[])
{
	int *p,i=0;
	for(i;i<10;i++)
	{
	  scanf(FORMAT,&stu[i].num,&stu[i].name,&stu[i].score1,&stu[i].score2,&stu[i].score3);
      stu[i].all=stu[i].score1+stu[i].score2+stu[i].score3;
	  stu[i].aver=stu[i].all/3;
    }
}
void output(struct Student stu[])
{
	int *p,i=0;
	for(i;i<10;i++)
	  printf("%3d %20s %3f %3f %3f %3f %3f",stu[i].num,stu[i].name,stu[i].score1,stu[i].score2,stu[i].score3,stu[i].all,stu[i].aver);
}

