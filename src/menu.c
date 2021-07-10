#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "student.h"
#include "util.h"
LinkedList *ll=NULL;
//读取数据
void subMenu1()
{
  //从文件中读取数据
  FILE *p;
  Student *s;
  p=fopen("info.bin","r");//打开数据文件
  while(!feof(p))
  {
    s=(Student*)malloc(sizeof(Student));//分配新的内存
    fscanf(p,"%ld,%lf,%lf,%s\n",&s->id,&s->pscore,&s->qscore,&s->name);//从文件中提取数据
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
  printf("输入学号 >");
  scanf("%d",&s->id);
  printf("输入姓名 >");
  scanf("%s",&s->name);
  printf("输入平时成绩 >");
  scanf("%lf",&s->pscore);
  printf("输入期末成绩 >");
  scanf("%lf",&s->qscore);
  //保存到链表中
  add(ll,s);
}
//删除数据
void subMenu3()
{
  long id;
  Student *s;
  //清空输入缓冲避免不必要的错误
  fflush(stdin);
  //选择要删除的数据
  printf("输入要删除的学号 >");
  scanf("%ld",&id);
  //从链表中删除
  resetCurr(ll);
  while(((Student*)(getCurrData(ll)))->id!=id){
    currMoveNext(ll);
  }
  removeCurr(ll,s);
  free(s);
  resetCurr(ll);
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
    fprintf(p,"%d,%f,%f,%s\n",s->id,s->pscore,s->qscore,s->name);//写入文件
    currMoveNext(ll);//操作指针后移
    i++;
  }
  fclose(p);//关闭文件
  //返回控制到主菜单
  resetCurr(ll);
  return;
}
//输出数据
void subMenu5()
{
  int len,i;
  Student *s;
  len=getLength(ll);
  i=1;
  while(i<=len){
    s=(Student *)getCurrData(ll);
    printf("%d,%s,%f,%f\n",s->id,s->name,s->pscore,s->qscore);
    currMoveNext(ll);
    i++;
  }
  resetCurr(ll);
  return;
}
//查找数据
void subMenu6()
{
  int id;
  printf("输入要查找的学号 >");
  scanf("%ld",&id);
  while(((Student*)(getCurrData(ll)))->id!=id){
    currMoveNext(ll);
  }
  printf("%d,%s,%f,%f\n",((Student*)(getCurrData(ll)))->id,((Student*)(getCurrData(ll)))->name,((Student*)(getCurrData(ll)))->pscore,((Student*)(getCurrData(ll)))->qscore);
  resetCurr(ll);
  return;
}
//分析数据
void subMenu7()
{
  double p1,p2;
  int pdc[5]={0},qdc[5]={0},zdc[5]={0},i;
  double *ps = malloc(sizeof(double)*getLength(ll));
  double *qm = malloc(sizeof(double)*getLength(ll));
  double *zp = malloc(sizeof(double)*getLength(ll));
  printf("平时成绩占比 >");
  scanf("%lf",&p1);
  printf("期末成绩占比 >");
  scanf("%lf",&p2);
  i=0;
  while(i<getLength(ll)){
    ps[i]=((Student *)(getCurrData(ll)))->pscore;
    qm[i]=((Student *)(getCurrData(ll)))->qscore;
    zp[i]=total(ps[i],qm[i],p1,p2);
    currMoveNext(ll);
    i++;
  }
  i=0;
  while(i<getLength(ll)){
    if(ps[i]<60){
      pdc[0]++;
    }else if(ps[i]<70){
      pdc[1]++;
    }else if(ps[i]<80){
      pdc[2]++;
    }else if(ps[i]<90){
      pdc[3]++;
    }else{
      pdc[4]++; 
    }
    if(qm[i]<60){
      qdc[0]++;
    }else if(qm[i]<70){
      qdc[1]++;
    }else if(qm[i]<80){
      qdc[2]++;
    }else if(qm[i]<90){
      qdc[3]++;
    }else{
      qdc[4]++; 
    }
    if(zp[i]<60){
      zdc[0]++;
    }else if(zp[i]<70){
      zdc[1]++;
    }else if(zp[i]<80){
      zdc[2]++;
    }else if(zp[i]<90){
      zdc[3]++;
    }else{
      zdc[4]++; 
    }
    i++;
  }
  printf("平时成绩\t 不及格\t60-69分\t70-79分\t80-89分\t90-100分\t平均分\t标准差\n");
  printf("人数    \t%d\t%d\t%d\t%d\t%d\t%.2f\t%d\n",pdc[0],pdc[1],pdc[2],pdc[3],pdc[4],average(ps,getLength(ll)),sd(ps,getLength(ll)));
  
  printf("期末成绩\t 不及格\t60-69分\t70-79分\t80-89分\t90-100分\t平均分\t标准差\n");
  printf("人数    \t%d\t%d\t%d\t%d\t%d\t%.2f\t%d\n",qdc[0],qdc[1],qdc[2],qdc[3],qdc[4],average(qm,getLength(ll)),sd(qm,getLength(ll)));
  
  printf("总评成绩\t 不及格\t60-69分\t70-79分\t80-89分\t90-100分\t平均分\t标准差\n");
  printf("人数    \t%d\t%d\t%d\t%d\t%d\t%.2f\t%d\n",zdc[0],zdc[1],zdc[2],zdc[3],zdc[4],average(zp,getLength(ll)),sd(zp,getLength(ll)));
  printf("期末及格率：%.2f,最高分：%.2f,最低分：%.2f\n",percent(qm,getLength(ll),60),getMax(qm,getLength(ll)),getMin(qm,getLength(ll)));
  free(ps);
  free(qm);
  free(zp);
  resetCurr(ll);
  return;
}
//主菜单
void mainMenu()
{
  ll=initLinkList();
  int fn = -1;
  for(;;){
  printf("---------请选择操作---------\n\n");
  printf("\
1.读取数据\n\
2.添加数据\n\
3.删除数据\n\
4.保存数据\n\
5.输出数据\n\
6.查找数据\n\
7.分析数据\n\
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
}