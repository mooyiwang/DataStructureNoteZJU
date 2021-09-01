#include<stdio.h>
#include<stdlib.h>
//9.1简单排序

void X_Sort( ElementType A[], int N )
//由小到大
//冒泡排序
 void Bubble_Sort(ElementType A[], int N)
 {
    int i,P;
    int flag;
    for(P=N-1; P>=0; P--){
        flag = 0;
        for(i=0; i<P; i++){
            if(num[i]>num[i+1]){
                Swap(A[i],A[i+1]); //优点：每次只相邻交换,对单向链表友好
                flag = 1;
            }
        }
        if( flag == 0 ) break;
    }
 }

//最好情况 T=O(N)
//最坏 T=O(N^2)

//插入排序
void Insertion_Sort( ElementType A[], int N)
{
    int P,i;
    for( P=1; P<N; P++){
        Tmp = A[P];
        for(i=P; i>0 &&  A[i-1] > Tmp; i--)
            A[i] = A[i-1];
        A[i] = Tmp
    }
}
//最好情况 T=O(N) 最坏 T=O(N^2)

//7.2 希尔排序 shell sort

//原始希尔排序
void Shell_Sort(ElementType A[], int N)
{
    int D,P,i;
    for(D= N/2; D>0; D/=2 ){
        for( P=D; P<N; P++){
            Tmp = A[P];
            for(i=P; i>=D &&  A[i-D] > Tmp  ; i-=D)
                A[i] = A[i-D];
            A[i] = Tmp
        }
    }
}
//最坏情况T=Θ(N^2)
//Hibbard, Sedgewick增量序列

//7.3堆排序
//选择排序 由小到大
void Selection_Sort(ElementType A[], int N )
{
    for( i=0; i<N-1; i++){
        MinPosition = ScanForMin( A, i, N-1);//关键
        Swap( A[i], A[MinPosition] )
    }
}
// 如果ScanForMin()直接扫描的话，总的T=O(N^2)

//堆排序 算法1
void Heap_Sort(ElementType A[], int N )
{
    BuildHeap(A);//先将A调整为最小堆,O(N)
    for( i=0; i<N; i++){
        TmpA[i] = DeleteMin(A); //logN
    }
    for( i=0; i<N; i++){
        A[i] = TmpA[i];
    }
}
// T=O(N*logN) 缺点：还需要一个额外的TmpA,可利用内存减半了

//堆排序 算法2
void Heap_Sort(ElementType A[], int N )
{
    for( i=N/2; i>=0; i--)
        PercDown( A, i, N ); //先将A调整为最大堆,O(N)
    for( i=N-1; i>0 ; i--){
        swap( &(A[0]), &(A[i]));
        PercDown( A, 0, i );
    }
}
// T稍小于O(N*logN)
//算法2的另一种表示
void Heap_Sort(ElementType A[], int N )
{
    BuildMaxHeap(A, 0, N-1);//先将A调整为最大堆,O(N)
    for( i=N-1; i>0 ; i--){
        A[i] =  DeleteMin(A);
        BuildMaxHeap(A, 0, i-1);
    }
}

//7.4归并排序
//将两组排好序的数组合并的算法
 void Merge( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd )
 {//假设两组在一个数组A中连续存放、
    LeftEnd = R-1;
    Tmp = L;
    NumElements = RightEnd - L + 1；
    while ( L<=LeftEnd && R<=RightEnd){
        if( A[L] <= A[R] ) TmpA[Tmp++] = A[L++];
        else TmpA[Tmp++] = A[R++];
    }
    for( ; L<=LeftEnd; L++) TmpA[Tmp++] = A[L];
    for( ; R<=RightEnd; R++) TmpA[Tmp++] = A[R];
    for(i = 0; i<NumElements; i++,RightEnd--)
        A[RightEnd] = TmpA[RightEnd];
 }
  //T=O(N)

 //递归算法，反复调用，最后将他们Merge
void MSort( ElementType A[], ElementType TmpA[], int L, int RightEnd )
{
    int Center;
    if( L < RightEnd ){
        Center = (L+RightEnd)/2;
        MSort(A, TmpA, L, Center);
        MSort(A, TmpA, Center+1, RightEnd);
        Merge(A, TmpA, L, Center+1, RightEnd);
    }
}
//T=O(N*logN)

//统一函数的接口
void Merge_Sort( ElementType A[], int N ){
    ElementType *TmpA;
    TmpA = malloc(N*sizeof( ElementType));
    if( TmpA != NULL){
        MSort(A, TmpA, 0, N-1);
        free(TmpA);
    }
    else Error("空间不足")
}

//非递归算法
void Merge_pass(ElementType A[], ElementType TmpA[], int N, int length)
{
    for(i=0; i<=N-2*length; i+= 2*length)
        Merge1(A, TmpA, i, i+length, i+2*length-1); //做完后元素存在TmpA，没有再导回A
    if(i+length<N) 
        Merge1(A, TmpA, i, i+length, N-1); 
    else
        for( j=i; j<N; j++) TmpA[j]=A[j];
}
 void Merge1( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd )
 {//假设两组在一个数组A中连续存放、
    LeftEnd = R-1;
    Tmp = L;
    NumElements = RightEnd - L + 1；
    while ( L<=LeftEnd && R<=RightEnd){
        if( A[L] <= A[R] ) TmpA[Tmp++] = A[L++];
        else TmpA[Tmp++] = A[R++];
    }
    for( ; L<=LeftEnd; L++) TmpA[Tmp++] = A[L];
    for( ; R<=RightEnd; R++) TmpA[Tmp++] = A[R];
 }
void Merge_Sort( ElementType A[], int N )
{
    ElementType *TmpA;
    TmpA = malloc(N*sizeof( ElementType));
    int length = 1;
    if( TmpA != NULL){
          while( length<N ){
              Merge_pass(A, TmpA, N, length);
              length *= 2;
              Merge_pass(TmpA, A, N, length);
              length *= 2;
          }
        free(TmpA);
    }
    else Error("空间不足")
//T=O(N*logN)最好最坏都是N*logN，缺点在于可用内存减半


//7.5快速排序

void QuickSort( ElementType A[], int N )
{
    if(N<2) return;
    pivot = 从A[]中选一个主元；
    将S = { A[] \ pivot} 分成两个独立子集：
    A1 = { a∈S | a ≤ pivot }， 
    A2 = { a∈S | a ≥ pivot };
    A[] = QuickSort( A1, N1 )∪ {pivot} ∪ QuickSort(A2,N2);
}
//时间复杂度与1.如何选主元 2.如何分子集有关
//最好情况T=O(N*logN) 最坏N^2

//选主元
//选头中尾三个数的中位数
ElementType Median3( ElementType A[], int Left, int Right )
{
    int Center = (Left + Right) /2;
    if(A[Left] > A[Center]) Swap( &A[Left], &A[Center]);
    if(A[Left] > A[Right]) Swap( &A[Left], &A[Right]);
    if(A[Center] > A[Right]) Swap( &A[Center], &A[Right]);

    Swap( &A[Center], &A[Right-1]);
    //将pivot藏到右边，并且分子集时只用考虑 left+1到right-2 区间的数了
    return A[Right-1];
}

//子集划分+递归实现

void QuickSort( ElementType A[], int Left, int Right)
{
    if(Right-Left >= Cutoff){
        Pivot = Median3( A, Left, Right);
        i = Left; j = Right -1;
        for(;;){
            while( A[++i] < Pivot ){}
            while( A[--j] > Pivot ){}
            if( i< j) Swap(&A[i], &A[j]);
            else break;       
        }
        Swap( &A[i], &A[Right-1]);
        QuickSort(A, Left, i-1);
        QuickSort(A, i+1, Right);
    }
    else Insertion_Sort( A+Left, Right-Left+1 );   
}

//或者
    i = Left+1; j = Right -2;
    for(;;){
        for(; A[i] < Pivot; i++);
        for(; A[j]) > Pivot; j--);

    }
//最后统一接口
void Quick_Sort( ElementType A[], int N )
{
    QuickSort(A, 0, N-1);
}

//7.6 表排序
//只移动指针，利用之前的排序来完成指针表的排序
//以插入排序为例  //最好情况 T=O(N) 最坏 T=O(N^2)
void Table_Sort( PointerType T[], int N)
{
    int P,i;
    for( P=1; P<N; P++){
        Tmp = T[P]->Key;
        TmpPtr = T[P];
        for(i=P; i>0 &&  T[i-1]->Key > Tmp; i--)
            T[i] = T[i-1];
        T[i] = TmpPtr;
    }
}

//如果最后要求物理排序，则一个一个环内处理
//物理排序时间复杂度 最坏 T=O(mN),m是每个元素复制所需时间


//7.7 基数排序
//7.7.1 桶排序 待排序的数量N很多，但是这些数的大小范围有限M
void Bucket_Sort( ElementType A[], int N )
{
    count[]初始化；
    while ( 读入A中的一个数A[i]) 
    将其插入count[A[i]]链表；
    for( i=0; i<M; i++){
        if(count[i]不为空) 输出整个count[i]链表;
    }
 }
//T=O(M+N)  N>>M 合算,此时就是线性时间复杂度

//7.7.2 基数排序 M>>N

//T=O(P(N+B)) P=logB(M)
// LSD MSD

//多关键字排序
//MSD LSD



//7.8 排序算法的比较