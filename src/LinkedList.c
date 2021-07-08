
#include <stdlib.h>
//节点结构
typedef struct Node
{
    struct Node *next;
    struct Node *prev;
    void *data;
} Node;
//链表结构
typedef struct
{
    Node *head;
    Node *tail;
    Node *curr;
    int length;
} LinkedList;
//初始化链表
LinkedList *initLinkList()
{
    LinkedList *ll = (LinkedList *)malloc(sizeof(LinkedList));
    if (ll == NULL)
    {
        return NULL;
    }
    ll->curr = ll->tail = ll->head = NULL;
    ll->length = 0;
    return ll;
}
//链表判空
int isEmply(LinkedList *ll)
{
    if (ll == NULL)
    {
        return -1;
    }
    return ll->head == NULL;
}
//链表求长
int getLength(LinkedList *ll)
{
    return ll->length;
}
//移动操作指针到下一节点
void currMoveNext(LinkedList *ll)
{
    if (ll->curr != ll->tail)
    {
        ll->curr = ll->curr->next;
    }
}
//移动操作指针到上一节点
void currMovePrev(LinkedList *ll)
{
    if (ll->curr != ll->head)
    {
        ll->curr = ll->curr->prev;
    }
}
//重设操作指针到开头
void resetCurr(LinkedList *ll)
{
    ll->curr = ll->head;
}
//向链表末尾追加新的节点
void add(LinkedList *ll, void *e)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->prev = ll->tail;
    ll->tail->next = n;
    ll->tail = n;
    ll->tail->data = e;
    if (ll->head == NULL)
    {
        ll->curr = ll->head = ll->tail;
    }
    ll->length++;
    ll->tail->next = NULL;
}
//移除链表末尾的节点
void remove(LinkedList *ll)
{
    if (isEmply(ll))
    {
        return;
    }
    Node *n = ll->tail;
    free(n->data);
    ll->tail = ll->tail->prev;
    ll->tail = NULL;
    free(n);
    ll->length--;
}
//在操作指针前插入新的节点
void addBefore2Curr(LinkedList *ll, void *e)
{
    if (isEmply(ll))
    {
        add(ll, e);
        return;
    }
    Node *n = (Node *)malloc(sizeof(Node));
    n->prev = ll->curr->prev;
    n->next = ll->curr;
    ll->curr->prev->next = n;
    ll->curr->prev = n;
    n->data = e;
    ll->length++;
}
//在操作指针后插入新的节点
void addAfter2Curr(LinkedList *ll, void *e)
{
    if (isEmply(ll) || ll->tail == ll->curr)
    {
        add(ll, e);
        return;
    }
    Node *n = (Node *)malloc(sizeof(Node));
    n->prev = ll->curr;
    n->next = ll->curr->next;
    ll->curr->next->prev = n;
    ll->curr->next = n;
    n->data = e;
    ll->length++;
}
//移除操作指针指向的节点
void removeCurr(LinkedList *ll)
{
    if (ll->curr != NULL && ll->length != 0)
    {
        Node *n = ll->curr;
        ll->curr->prev->next = ll->curr->next;
        ll->curr->next->prev = ll->curr->prev;
        ll->curr = ll->curr->prev;
        free(n->data);
        free(n);
    }
}
//搜索数据所在的位置
int search(LinkedList *ll, void *e)
{
    resetCurr(ll);
    int n = 0;
    void *p = ll->curr->data;
    while (ll->curr != NULL && p == e)
    {
        moveCurr2Next(ll);
        p = ll->curr->data;
        n++;
    }
    return n;
}
//返回给定位置的数据
void *indexOf(LinkedList *ll, int index)
{
    int index_p = 0;
    if (index > ll->length || index < 0)
    {
        return NULL;
    }
    if (index == ll->length)
    {
        ll->curr = ll->tail;
        return ll->curr->data;
    }
    resetCurr(ll);
    while (index_p != index)
    {
        moveCurr2Next();
        index_p++;
    }
    return ll->curr->data;
}
//修改操作指针指向的数据
void setCurrData(LinkedList *ll, void *e)
{
    ll->curr->data = e;
}
//获得操作指针指向的数据
void *getCurrData(LinkedList *ll)
{
    return ll->curr->data;
}
//合并链表
void contain(LinkedList *ll1, LinkedList *ll2)
{
    ll1->tail->next = ll2->head->prev;
    ll1->length += ll2->length;
    free(ll2);
    return;
}
//清空链表
void clearLinkedList(LinkedList *ll)
{
    if (isEmply(ll))
    {
        return;
    }
    resetCurr(ll);
    while (ll->curr != NULL)
    {
        free(ll->curr->data);
        ll->curr->data = NULL;
        moveCurr2Next(ll);
    }
    return;
}
//摧毁链表
void destoryLinkedList(LinkedList *ll)
{
    if (isEmply(ll))
    {
        return;
    }
    resetCurr(ll);
    Node *p = ll->head;
    while (ll->curr != NULL)
    {
        p = p->next;
        free(ll->curr->data);
        free(ll->curr);
        ll->curr = p->next;
    }
    free(ll);
}
