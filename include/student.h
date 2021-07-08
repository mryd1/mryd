#ifndef STUDENT_H_
#define STUDENT_H_
typedef struct Student
{
  //学号
  long id;
  //姓名
  char name[10];
  //平时成绩
  double pscore;
  //期末成绩
  double qscore;
}Student;
#endif
