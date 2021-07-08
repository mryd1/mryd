#include <stdio.h>
//主菜单
void mainMenu()
{
  int fn=-1;
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
  scanf("%d",&fn);
  switch(fn)
  {
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
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
  //保存到链表中
  //返回控制到主菜单
  return;
}
//添加数据
void subMenu2()
{
  //清空输入缓冲避免不必要的错误
  fflush(stdin);
  //从控制台中输入数据
  //保存到链表中
  //返回控制到主菜单
  return;
}
//删除数据
void subMenu3()
{
  
  //清空输入缓冲避免不必要的错误
  fflush(stdin);
  //选择要删除的数据
  //从链表中删除
  //返回控制到主菜单
  return;
}
//保存数据
void subMenu4()
{
  //保存数据到文件
  //刷新链表
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
