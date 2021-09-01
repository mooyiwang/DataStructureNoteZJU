#include<stdio.h>
#include<stdlib.h>
#define Null -1
#define MAXSIZE 1e5
// 单链表 逆转链表 Reversing Linked List//
//伪代码实现//
struct Node
{
    int Data;
    int Next;
}L[MAXSIZE];

typedef int Ptr;

int main()
{
    Ptr Head;
    int N,K;
    scanf(" %d %d %d",&Head,&N,&K)
    Read(Head, N);
    Head = Reverse( Head, K);
    Print(Head);
    return 0;
}

void Read(Ptr Head, int N)
{
    int i;
    Ptr Position;
    for(i=1; i<=N; i++){
        scanf(" %d %d %d",&Position,&L[Position].Data,&L[Position].Next);
    }
    return;
}
Ptr Reverse(Ptr Head, int K)
{
    Ptr tmp;
    int i=1; 
    Ptr new = Head;
    Ptr old = L[new].Next;
    while(i < K){
        tmp = L[old].Next;
        L[old].Next = new;
        new = old;
        old = tmp;
        i++;
    }
    L[Head].Next = old;
    Head = new;
    return Head; 
}

void Print( 
    
)