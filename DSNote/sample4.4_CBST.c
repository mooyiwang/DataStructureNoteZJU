//完全二叉搜索树//
#include<stdlib.h>
#include<stdio.h> 
#include<math.h>

#define MaxSize 10
#define N 10

int A[MaxSize],T[MaxSize];

int compare(const void*a, const void*b)
{
    return *(int*)a - *(int*)b;
}


void Read()
{
    int i;
    for(i=0;i<N;i++)
    scanf(" %d",&(A[i]));
}

void Output()
{
    int i;
    for(i=0; i<N; i++)
    printf( "%d ",T[i]);
}

int GetLeftLength( int n )
{
    int L;
    int H,X;
    for(H=0; pow(2, H+1)-1 < n; H+=1);
    X = n - ( pow(2, H) - 1);
    if( X <= pow(2, H-1)) L=pow(2, H-1)-1+X;
    else L = pow(2, H)-1;
    return L;
}  

void CBSTsolve( int ALeft, int ARight, int TRoot )
{//一开始输入的是 CBSTsolve(0,N-1,0)
    int n,L;
    n = ARight - ALeft + 1;
    if(n==0) return;
    L = GetLeftLength(n);
    T[TRoot] = A[ALeft + L];
    CBSTsolve(ALeft, ALeft+L-1, 2*TRoot+1);
    CBSTsolve(ALeft+L+1, ARight, 2*TRoot+2);
}


int main()
{
    Read();
    qsort(A, N, sizeof(int), compare);
    CBSTsolve(0, N-1, 0);
    Output();
}