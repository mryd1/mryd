#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "student.h"
LinkedList *ll;
//主菜单
void mainMenu()
{
  ll=initLinkList();
  int fn = -1;
  printf("---------请选择操作---------\n\n");
  printf("\
1.读取数据\n\
2.添加数据\n\
3.删除数据\n\
4.保存数据\n\
5.求总评成绩\n\
6.求标准差\n\
7.求平均分\n\
0.退出\n\
请选择> ");
  //清空输入缓冲避免不必要的错误
  fflush(stdin);
  //获取输入并跳转对应功能
  scanf("%d", &fn);
  switch (fn)
  {
  case 1:
    subMenu1();
    break;
  case 2:
    subMenu2();
    break;
  case 3:
    subMenu3();
    break;
  case 4:
    subMenu4();
    break;
  case 5:
    subMenu5();
    break;
  case 6:
    subMenu6();
    break;
  case 7:
    subMenu7();
    break;
  case 0:
    exit(0);
    break;
  default:
    printf("无此功能！");
    break;
  }
}
//读取数据
void subMenu1()
{
  //从文件中读取数据
  FILE *p;
  Student *s;
  ll=initLinkList(); //初始化链表
  p=fopen("info.bin","r");//打开数据文件
  while(!feof(p))
  {
    s=(Student*)malloc(sizeof(Student));//分配新的内存
    fscanf(p,"%ld,%s,%lf,%lf\n",&s->id,&s->name,&s->pscore,&s->qscore);//从文件中提取数据
    //保存到链表中
    add(ll,s);
  }
  fclose(p);//关闭文件
  //返回控制到主菜单
  return;
}
//添加数据
void subMenu2()
{
  //清空输入缓冲避免不必要的错误
  fflush(stdin);
  Student *s=(Student*)malloc(sizeof(Student));
  //从控制台中输入数据
  printf("输入格式：学号,姓名,平时成绩,期末成绩\n");
  scanf("%ld,%s,%lf,%lf",&s->id,&s->name,&s->pscore,&s->qscore);
  //保存到链表中
  add(ll,s);
  //返回控制到主菜单
  return;
}
//删除数据
void subMenu3()
{
  long id;
  Student *s;
  //清空输入缓冲避免不必要的错误
  fflush(stdin);
  //选择要删除的数据
  printf("输入要删除的学号：");
  scanf("%ld",&id);
  //从链表中删除
  resetCurr(ll);
  while(((Student*)(getCurrData(ll)))->id!=id){
    currMoveNext(ll);
  }
  removeCurr(ll,s);
  free(s);
  //返回控制到主菜单
  return;
}
//保存数据
void subMenu4()
{
  int len,i;
  FILE *p;
  Student *s;
  p=fopen("info.bin","w");//重新创建文件
  len=getLength(ll);//获取学生数量
  i=1;
  //保存数据到文件
  resetCurr(ll);//重置链表操作指针
  while(i<=len)
  {
    s=(Student *)getCurrData(ll);//获取当前操作指针指向的学生
    fprintf(p,"%ld,%s,%lf,%lf\n",s->id,s->name,s->pscore,s->qscore);//写入文件
    currMoveNext(ll);//操作指针后移
    i++;
  }
  fclose(p);//关闭文件
  destoryLinkedList(ll);//删除链表

  //刷新链表
  subMenu1();
  //返回控制到主菜单
  return;
}
//求总评成绩
void subMenu5()
{
  //求总评
  //输出
  //返回控制到主菜单
  return;
}
//求标准差
void subMenu6()
{
  //求标准差
  //输出
  //返回控制到主菜单
  return;
}
//求平均
void subMenu7()
{
  //求平均
  //输出
  //返回控制到主菜单
  return;
}
