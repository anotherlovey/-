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
bool nizhi(sqlist *L)
{
    if(Empty(*L))
    {
        printf("sqlit is NULL\n");
        return false;
    }
    int i = ((L->length)/2);
    int j = ((L->length)/2);
    while(i > 0 && j<(L->length))

}
int main()
{
    sqlist L;
    sqlist M;
    sqlist N;
    // 例如 1 2 3 4 5 6在3和4之间为中点，循环一次对称的交换
    bool InitList(sqlist *L);
    bool InitList(sqlist *M);
    bool InitList(sqlist *N);

    //3中情况分别试一下。1.只有一个数 2.总数偶数 3.总数奇数
    int i = 1;
    bool ListInsert(sqlist *L,int i,int e);
    for(int i = 1;i <= 5;i++)
    {
        int e = i;
        bool ListInsert(sqlist *L,int i,int e);
    }
    for(int i = 1;i <= 6;i++)
    {
        int e = i;
        bool ListInsert(sqlist *N,int i,int e);
    }
    

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