//编辑注意！！！
//此文件需要重构，有可能会完全重写
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define LEN sizeof(struct stu)

struct stu
{
	long num;
	char name[10];
	int mscore;
	int pscore;
	struct stu*next;
};
int n;
struct stu*head=NULL,*end;

void cd()                  //一级菜单界面 
{
    void creat();
    void insert();
    void del();
    void cd4();
    void cd5();
    void check();
	printf("---------请选择操作---------\n\n");
    printf("1.新建数据\n2.添加数据\n3.删除数据\n4.求总评成绩\n5.求标准差\n6.求平均分\n7.退出\n----------------------------------------\n!!!请输入序号进行选择!!!\n"); /*显示菜单*/
	int a;
	scanf("%d",&a); /*输入选择*/
	switch(a)   /*读取选择并转入下一步工作即各个函数*/
	{
	case 1:
		creat();break;
	case 2:
		insert();break;
	case 3:
		del();break;
	case 4:
		cd4();break;
	case 5:
		cd5();break;
	case 6:
	    check();break;
    case 7:
		printf("*欢迎下次使用*\n");break;
	}
}

void cd4()                  //4菜单界面 
{
	printf("\n 请输入计算总成绩时使用平时成绩与期末成绩的比例，用整数表示(百分比例 如：30 70):");    
	scanf("%d%d",&a1,&a2);
    
}

void cd5()                  //标准差界面 
{
    
}

void creat()//新建数据 1.creat 
{
	struct stu*p1,*p2;
	printf("请输入学生数目\n");
	scanf("%d",&n);
	printf("请依次输入\n学号  姓名  平时成绩 期末成绩\n"); 
	int count=1;
	p1=p2=(struct stu*)malloc(LEN);
	scanf("%ld %s %d %d",&p1->num,&p1->name,&p1->mscore,&p1->pscore);
	head=p1;
	while(count<n)
	{
		p1=(struct stu*)malloc(LEN);
		p2->next=p1;
		p2=p1;
		scanf("%10ld %s %d %d",&p1->num,&p1->name,&p1->mscore,&p1->pscore);
		count++;
	}
	end=p1;
	p1->next=NULL;
		p1=head;                                                 // here 
	printf("\n当前成绩\n");
	for(int i=1;i<=n;i++)
	{
		printf("%ld %5s %4d %4d\n",p1->num,p1->name,p1->mscore,p1->pscore);
		p1=p1->next;
	}
	p1=head;
	printf("\n是否返回菜单\n1.是      2.否\n"); 
	int z;
	scanf("%d",&z);
	switch(z)
	{
	case 1:
		cd();break;
	case 2:
		printf("*欢迎下次使用*\n");break;
	}
}

void insert()//添加数据 2.insert
{
	printf("请输入学生的\n学号   姓名  平时成绩 期末成绩\n");
	n++;
	struct stu*p1,*p2;
	p1=(struct stu*)malloc(LEN);
	end->next=p1;
	scanf("%ld %s %d %d",&p1->num,&p1->name,&p1->mscore,&p1->pscore);
	end=p1;
	p1->next=NULL;
	p1=head;                                                 // here 
	printf("\n当前成绩\n");
	for(int i=1;i<=n;i++)
	{
		printf("%ld %5s %4d %4d\n",p1->num,p1->name,p1->mscore,p1->pscore);
		p1=p1->next;
	}
	p1=head;
	printf("\n是否返回菜单\n1.是      2.继续添加\n");
	int z;
	scanf("%d",&z);
	switch(z)
	{
	case 1:
		cd();break;
	case 2:
	    insert();break;
	}
}

void del()//删除数据 3.del 
{
	 struct stu*p1,*p2;
	p1=head;                                                 // here 
	printf("\n当前成绩\n");
	for(int i=1;i<=n;i++)
	{
		printf("%ld %5s %4d %4d\n",p1->num,p1->name,p1->mscore,p1->pscore);
		p1=p1->next;
	}
	int d,flag=0;
	printf("请输入需要删除的学生学号\n");
	scanf("%ld",&d);
	p1=head;p2=p1;
	if(p1->num==d){head=p1->next;free(p1);flag++;}
	else {p1=p1->next;
	      for(int i=2;i<=n;i++)
          {if(p1->num==d){p2->next=p1->next;free(p1);flag++;break;}    
		   p2=p1;p1=p1->next;
          }
	}
	if(flag==0){printf("输入数据不存在或有误，按1重新输入，0返回菜单\n");
	if(getchar()==1)del();
	else if(getchar()==0)cd();}
	else n--;
	p1=head;                                                     //here 
	printf("\n当前成绩\n");
	for(int i=1;i<=n;i++)
	{
		printf("%ld %5s %4d %4d\n",p1->num,p1->name,p1->mscore,p1->pscore);
		p1=p1->next;
	}
	p1=head;
	printf("\n是否返回菜单\n1.是      2.否\n");
	int z;
	scanf("%d",&z);
	switch(z)
	{
	case 1:
		cd();break;
	case 2:
		printf("*欢迎下次使用*\n");break;
	}
}

