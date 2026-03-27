//长度为n的顺序表L，编写一个时间复杂度为O(n)。空间复杂度为O(1)的算法，删除所有值为x的数据元素

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include <string.h>

#define maxsize 990

typedef struct
{
    int *data;
    int length;
}sqlist; 
// 函数原型声明
bool Empty(sqlist L);
bool nizhi(sqlist *L);
bool InitList(sqlist *L);
bool ListInsert(sqlist *L, int i, int e);
bool ListDelete(sqlist *L, int i, int *e);
int Length(sqlist L);
int LocateElem(sqlist L, int e);
bool GetElem(sqlist L, int i, int *e);
void PrintList(sqlist L);

void delete_x(sqlist*L,int x)
{
    int k = 0;
    for(int i=0;i<(L->length);i++)
    {
        if(L->data[i] != x)
        {
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->length = k;
}
int main()
{
    sqlist L;
    sqlist M;
    sqlist N;

    InitList(&L);
    InitList(&M);
    InitList(&N);

    ListInsert(&L, 1, 1);

    for(int i = 1;i <= 6;i++)
    {
        ListInsert(&M,i,i);    
    }
    for(int i = 1;i <= 7;i++)
    {
        ListInsert(&N,i,i);    
    }
    
    printf("L before: ");
    PrintList(L);
    delete_x(&L,1);
    printf("L after: ");
    PrintList(L);
    
    printf("M before: ");
    PrintList(M);
    delete_x(&M,3);
    printf("M after: ");
    PrintList(M);
    
    printf("N before: ");
    PrintList(N);
    delete_x(&N,7);
    printf("N after: ");
    PrintList(N);

    return 0;
}
bool InitList(sqlist *L)
{
    L->data = (int*)malloc(maxsize*sizeof(int));
    if(!L->data)
    {
        return false;
    }
    L->length=0;
    return true;
}

int Length(sqlist L)
{
    return (L.length);
}

int LocateElem(sqlist L,int e)
{
    for(int i=0;i<(L.length);i++)
    {
        if(L.data[i]==e)
        {
            return i;
        }
    }
    return -1; // -1 锟斤拷锟斤拷锟斤拷锟斤拷锟铰标范围锟斤拷
}

bool GetElem(sqlist L, int i,int *e)
{
    if(i>(L.length-1) || i<0)
    {
        return false;
    }
    *e = L.data[i-1];
    return true;
}

bool ListInsert(sqlist *L, int i, int e)
{
    if(i<=0 || i>(L->length+1))
    {
        return false;
    }
    for(int j=(L->length-1);j>=(i-1);j--)
    {
        L->data[j+1] = L->data[j];
    }
    L->data[i-1] = e;
    L->length++;
    return true;
}

bool ListDelete(sqlist *L, int i, int *e)
{
    if(i<=0 || i>(L->length))
    {
        return false;
    }
    *e = L->data[i-1];
    for(int j=i-1;j<(L->length-1);j++)
    {
        L->data[j]=L->data[j+1];
    }
    L->length--;
    return true;
}

void PrintList(sqlist L)
{
    if(L.length==0)
    {
        printf("NULL");
    }
    else
    {
         for(int i=0;i<(L.length);i++)
        {
            if(i!=(L.length-1))
            {
                printf("%d ", L.data[i]);
            }
            else
            {
                printf("%d\n", L.data[i]);
            }
        }
    }
}

bool Empty(sqlist L)
{
    if(L.length==0)
    {
        return true;
    }
    return false;
}

void DestroyList(sqlist *L)
{
    free(L->data);
    L->data = NULL;
    L->length=0;
}