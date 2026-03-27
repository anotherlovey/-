//

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
// º¯ÊýÔ­ÐÍÉùÃ÷
bool Empty(sqlist L);
bool nizhi(sqlist *L);
bool InitList(sqlist *L);
bool ListInsert(sqlist *L, int i, int e);
bool ListDelete(sqlist *L, int i, int *e);
int Length(sqlist L);
int LocateElem(sqlist L, int e);
bool GetElem(sqlist L, int i, int *e);
void PrintList(sqlist L);
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
    return -1; // -1 ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Â±ê·¶Î§ï¿½ï¿½
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

int main()
{
    sqlist L;
    sqlist M;
    sqlist N;
    InitList(&L);
    InitList(&M);
    InitList(&N);
    
    // start 


    return 0;
}
