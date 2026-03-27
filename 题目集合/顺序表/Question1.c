//将顺序表所有元素逆置，空间复杂度为O(1)
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
bool nizhi(sqlist *L)
{
    if(Empty(*L))
    {
        printf("sqlit is NULL\n");
        return false;
    }
    for(int i=0;i<(L->length/2);i++)
    {
        int temp = L->data[i];
        L->data[i] = L->data[L->length-1-i];
        L->data[L->length-1-i] = temp;
    }
    return true;
}
int main()
{
    sqlist L;
    sqlist M;
    sqlist N;
    // 例如 1 2 3 4 5 6在3和4之间为中点，循环一次对称的交换
    InitList(&L);
    InitList(&M);
    InitList(&N);

    //3中情况分别试一下。1.只有一个数 2.总数偶数 3.总数奇数
    // 测试情况1: 只有一个元素
    ListInsert(&L, 1, 1);

    // 测试情况2: 6个元素
    for(int i = 1;i <= 6;i++)
    {
        ListInsert(&M,i,i);    
    }
    // 测试情况3: 7个元素
    for(int i = 1;i <= 7;i++)
    {
        ListInsert(&N,i,i);    
    }
    
    printf("L before: ");
    PrintList(L);
    nizhi(&L);
    printf("L after: ");
    PrintList(L);
    
    printf("M before: ");
    PrintList(M);
    nizhi(&M);
    printf("M after: ");
    PrintList(M);
    
    printf("N before: ");
    PrintList(N);
    nizhi(&N);
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
    return -1; // -1 不在数组下标范围内
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