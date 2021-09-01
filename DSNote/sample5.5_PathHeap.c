#include<stdio.h>
#include<stdlib.h>

#define MAXN 1001
#define MINH -10001



typedef struct HeapStruct* MinHeap;
struct HeapStruct
{
    int *Elements;
    int Size;
    int Capacity;
};

MinHeap Create();
void Insert( MinHeap H, int X);
void Path(MinHeap H);

int main()
{
    int N,M,X;
    int i;
    MinHeap H = Create();
    scanf(" %d %d\n",&N,&M);
    for(i=0; i<N; i++){
        scanf(" %d",&X);
        Insert( H, X);
    }
    for(i=0; i<M; i++){
        Path( H );
    }
    return 0 ;
}

MinHeap Create()
{
    MinHeap H = (MinHeap)malloc(sizeof(struct HeapStruct));
    H->Elements = malloc(MAXN*sizeof(int));
    H->Size = 0;
    H->Elements[0] = MINH;
    return H;
}

void Insert( MinHeap H, int X)
{
    int i;
    for( i= ++H->Size ; H->Elements[i/2] > X ; i/=2)
        H->Elements[i] = H->Elements[i/2];
    H->Elements[i] = X;
}

void Path(MinHeap H)
{
    int j;
    scanf(" %d",&j);
    for(; j>0 ; j/=2)
        printf("%d ",H->Elements[j]);
    printf("\n");
}

