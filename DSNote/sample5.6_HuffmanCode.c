//huffman一定得到最优编码，但最优编码不一定是由huffman方法得到//
 //具体实现//
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