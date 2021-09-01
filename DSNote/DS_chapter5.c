#include<stdio.h>
#include<stdlib.h>
//5.1 堆 Heap//
//优先队列 priority queue//
   //有很多存储的方式 数组 链表 有序数组 有序链表//
 //完全二叉树 数组 存储//
   //1.根是子树的max/min 2.完全二叉树//
 //建立//
typedef struct HeapStruct* MaxHeap;
struct HeapStruct
{
    ElementType *Elements;
    int Size;
    int Capacity;
};

MaxHeap Create( int MaxSize)
{
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
    H->Elements = malloc((MaxSize+1)*sizeof(ElementType)); //多一个位子来定义哨兵并且是从下标1开始存数据//
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Elements[0] = MaxData;//哨兵//

    return H;
}



//插入 OlogN//

void Insert( MaxHeap H, ElementType item)
{
    int i;
    if(IsFull(H)){
        printf("the maxheap is full!");
        return;
    }
    i = ++H->Size;
    for( ; H->Elements[i/2] < item; i/=2){
        H->Elements[i] = H->Elements[i/2];
    }
    H->Elements[i] = item;
}
//删除//
ElementType DeleteMax(MaxHeap H)
{
    int Parent, Child;
    ElementType MaxItem, tmp;

    if(!H->Size){
        printf("the heap is empty")；
        return;
    }

    MaxItem = H->Elements[1];
    tmp = H->Elements[H->Size--];

    for( Parent=1; Parent*2 <=H->Size ; Parent=Child){
        Child = Parent*2;
        if((Child!=H->Size) && (H->Elements[Child] < H->Elements[Child+1]))
            Child++;
        if(tmp >= H->Elements[Child]) break;
        else 
            H->Elements[Parent] = H->Elements[Child];
    }
    H->Elements[Parent] = tmp;
    return MaxItem;
}
//5.1.4最大堆的建立 O n//
//建立 调整//

//5.2哈夫曼树与哈夫曼编码 Huffman Tree//
//huffmantree 用链表来存，与堆用数组（完全二叉树）来存不一样//
typedef struct HeapStruct* MinHeap;
struct HeapStruct
{
    HuffmanTree Elements[];//HuffmanTree(ElementType) *Elements//
    int Size;
    int Capacity;
};

typedef struct TreeNode* HuffmanTree;
struct TreeNode{
    int Weight;
    HuffmanTree Left,Right;
};

HuffmanTree Huffman( MinHeap H )
{
    /*假设H->Size个权值的已经存到H->Elements[]->Weight里,H->Elements[]是一个结构体数组*/
    int i;
    HuffmanTree T;
    BuildMinHeap(H); //将H->Elements[]按权值调整为最小堆//

    for( i=1; i< H->Size; i++){
        T = malloc(sizeof(struct TreeNode));

        T->Left = DeleteMin(H);
        T->Right  = DeleteMin(H);
        T->Weight = T->Left->Weight + T->Right->Weight;

        InsertMin(H, T)；
    }
    T = DeleteMin(H);
    return T;
}

//huffman编码//

//5.3集合//
//表示//

//结构数组 静态链表 存储//
typedef struct{
    ElementType Data;
    int Parent;
}SetType;

SetType S[];

//查找//
/*
int Find( SetType S[], ElementType X)
{//返回值为所在集合头下标//
    int i;
    for(i=0;i<MaxSize;i++){
        if(X == S[i].Data ){
            while(S[i].Parent != -1){
                i = S[i].Parent;
            }
            return i;
        }
    }
    return -1;
}
*/
//或者//
int Find( SetType S[], ElementType X)
{
    int i;
    for( i=0; i<MaxSize && S[i].Data !=X; i++);
    if (i>=MaxSize) return -1;
    for(; (S[i].Parent >=0 ; i = S[i].Parent);
    return i;
}
//合并操作//
void Union( SetType S[], ElementType X1, ElementType X2)
{
    int Root1,Root2;
    Root1 = Find(S, X1);
    Root2 = Find(S, X2);

    if(Root1 != Root2) {//绝对值小的挂在大的上面//
        if(S[Root1].Parent < S[Root2].Parent){
            S[Root1].Parent += S[Root2].Parent;
            S[Root2].Parent = Root1;
        }
        else{
            S[Root2].Parent += S[Root1].Parent;
            S[Root1].Parent = Root2;
        }
}  