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
    printf("娌℃湁杩欎釜鍊糪n");
    return -1;
}
int GetElem(sqlist L, int i)
{
    if(i>(L.length-1) || i<0)
    {
        printf("鏌ユ壘澶辫触\n");
        return -1;
    }
    return L.data[i-1];
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
        printf("绌鸿〃\n");
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
void zhuyuansu(sqlist L,int *a)
{
    int count[L.length];
    memset(count,0,L.length*sizeof(int));

    for(int i=0;i<(L.length);i++)
    {
        count[L.data[i]]++;
    }
    L.data[L.length-1]=-1;
    count[L.data[L.length-1]]++;

    // for(int i=0;i<(L.length);i++)
    // {
    //    printf("%d ",count[i]);
    // }
    // printf("\n");

    int maxnum=count[0];
    for(int i=0;i<(L.length);i++)
    {
        if(count[i]>maxnum)
        {
            maxnum=count[i];
        }
    }
    *a = maxnum;
}
int main()
{
    sqlist L;
    sqlist M;
    sqlist N;
    InitList(&L);
    InitList(&M);
    InitList(&N);
    
    int temp1[] = {-1,0,9};
    memcpy(L.data,temp1,sizeof(int)*3);
    L.length=3;

    int temp2[]= {-25,-10,10,-11};
    memcpy(M.data,temp2,sizeof(int)*4);
    M.length=4;

    int temp3[] = {2,9,17,30,41};
    memcpy(N.data,temp3,sizeof(int)*5);
    N.length=5;

    // |L-M|+|L-N|+|M-N|的最小值的最高效算法
    // 使用三指针法，时间复杂度O(n1+n2+n3)
    
    int min_sum = 2147483647;  // 初始化为最大整数
    int i = 0, j = 0, k = 0;
    
    while(i < L.length && j < M.length && k < N.length)
    {
        int a = L.data[i];
        int b = M.data[j];
        int c = N.data[k];
        
        // 计算当前三个元素的绝对差值和
        int current_sum = abs(a - b) + abs(a - c) + abs(b - c);
        
        // 更新最小值
        if(current_sum < min_sum)
        {
            min_sum = current_sum;
        }
        
        // 移动指向最小元素的指针
        if(a <= b && a <= c)
        {
            i++;
        }
        else if(b <= a && b <= c)
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    
    printf("三个序列的最小绝对差值和为：%d\n", min_sum);
    
    PrintList(L);
    PrintList(M);
    PrintList(N);
    
    return 0;
}//找主元素，要求半数以上为这个数