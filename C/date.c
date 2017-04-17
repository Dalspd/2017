# include<stdio.h>
main()
{
	int y,m,d,s,date,leap;
	printf("请输入年月日，按逗号隔开\n");
	scanf("%d,%d,%d",&y,&m,&d);
	if(y%4==0&&y%400==0)
	{
	   leap=1;
	} 
	else
	   leap=0;
	switch(m)
		{
			case 1:s=0;break;
			case 2:s=31;break;
			case 3:s=59;break;
			case 4:s=90;break;
			case 5:s=120;break;
			case 6:s=151;break;
			case 7:s=181;break;
			case 8:s=212;break;
			case 9:s=243;break;
			case 10:s=273;break;
			case 11:s=304;break;
			case 12:s=334;break;
		}
	date=s+d+leap;
	printf("您输入的日子是当年的第%d天",date);
	getch();
	return 0;
}
