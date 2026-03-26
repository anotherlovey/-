#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


typedef struct LNode
{
    int data;
    struct LNode *next;
}*LinkList,LNode;
bool InintList(LinkList *L)//带头节点
{
    *L = (LinkList)malloc(sizeof(LNode));
    if( !L )
    {
        printf("false\n");
        return false;
    }
    (*L)->next = NULL;
    return true;
}
int Length(LinkList L)
{
    int len=0;
    LinkList temp = L->next;
    while(temp!=NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
LinkList LocatedList(LinkList L,int e)   //按值e查找,返回结构指针
{
    LinkList temp = L->next;
    while(temp && temp->data != e)
    {
        temp = temp->next;
    }
    return temp;
}
LinkList getElem(LinkList L,int i)   //按位，返回结构指针 1 2 3 4 5 
{
    LinkList temp = L; //
    int count = 0;
    while(temp && count< i)
    {
        temp = temp->next;
        count++;
    }
    return temp;
}
//指定位置插入
bool List_headinssert(LinkList L,int e) //每次在头节点之后插入
{
    LinkList p = (LinkList)malloc(sizeof(LNode));
    if(!p)
    {
        return false;
    }
    p->data = e;
    p->next = L->next;
    L->next = p; 
    return true;
}
bool List_insertrear(LinkList L,int e)//在第i后     1 10 9 8 7 6 5 4 3 2
{
    LinkList temp = L;
    while(temp->next)  
    {
        temp = temp->next;
    }
    LinkList p = (LinkList)malloc(sizeof(LNode));
    if(!p)
    { 
        return false;
    }
    p->data = e;
    p->next = NULL;
    temp->next = p; 
    return true;
}
bool Listinsert(LinkList L,int i, int e) // 将data为e的值查到第i位置上  L 1 2 3 4 5 6
{
    LinkList temp = L;
    int count = 0;
    while(temp && count < (i-1))
    {
        temp = temp->next;
        count++;
    }// 此时temp应该在i-1位
    if(temp)
    {
        return false;
    }
    LinkList p = (LinkList)malloc(sizeof(LNode));
    p->data = e;
    p->next = temp->next;
    temp->next = p;
    return true;
}
bool Listdelete(LinkList L,int i,int *e) //指定第i位删除
{
    LinkList temp = L;
    int count = 0;
    while(temp && count < (i-1))
    {
        temp = temp->next;
        count++;
    }// 此时temp应该在i-1位
    if(temp)
    {
        return false;
    }
    LinkList p = temp->next;
    *e = p->data;
    temp->next = p->next;
    free(p);
    return true;
}
bool printList(LinkList L)
{
    LinkList temp = L->next;
    if(!temp)
    {
        printf("NULL\n");
        return true;
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    return true;
}
bool isEmpty(LinkList L)
{
    if(L->next == NULL)
    {
        return true;
    }
    return false;
}
void destorylist(LinkList L)
{
    LinkList temp;
    while(L)
    {
        temp = L->next;
        free(L);
        L = temp;      
    }
}

int main()
{
    LinkList L;
    LinkList m;
    InintList(&L);
    InintList(&m);
    for(int i=1;i<10;i++)
    {
        List_headinssert(L,i);
    }

    printList(L);
}