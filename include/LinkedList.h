#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <stdlib.h>
struct LinkedList;
typedef struct LinkedList LinkedList;
//待续
LinkedList *initLinkList();
//链表判空
int isEmply(LinkedList *ll);
//链表求长
int getLength(LinkedList *ll);
//移动操作指针到下一节点
void currMoveNext(LinkedList *ll);
//移动操作指针到上一节点
void currMovePrev(LinkedList *ll);
//重设操作指针到开头
void resetCurr(LinkedList *ll);
//向链表末尾追加新的节点
void add(LinkedList *ll, void *e);
//移除链表末尾的节点
void remove(LinkedList *ll,void *e);
//在操作指针前插入新的节点
void addBefore2Curr(LinkedList *ll, void *e);
//在操作指针后插入新的节点
void addAfter2Curr(LinkedList *ll, void *e);
//移除操作指针指向的节点
void removeCurr(LinkedList *ll,void *e);
//搜索数据所在的位置
int search(LinkedList *ll, void *e);
//返回给定位置的数据
void *indexOf(LinkedList *ll, int index);
//修改操作指针指向的数据
void setCurrData(LinkedList *ll, void *e);
//获得操作指针指向的数据
void *getCurrData(LinkedList *ll);
//合并链表
void contain(LinkedList *ll1, LinkedList *ll2);
//清空链表
void clearLinkedList(LinkedList *ll);
//摧毁链表
void destoryLinkedList(LinkedList *ll);
#endif
