#include<stdlib.h>
#include<stdio.h>
//树 层次关系//
  
//3.0 引子顺序表的静态查找//
    //顺序查找//
    typedef struct LNode* List;
    struct LNode
    {
        ElementType Element[MAXSIZE];
        int Length; 
    };
    List Tb1;

       //哨兵 On//
       int SequentialSearch(List Tb1, ElementType K)
       {
           Tb1->Element[0] = K;
           int i;
           for(i=Tb1->Length;Tb1->Element[i] != K; i--);
           return i;
       }
    //二分查找 Binary Search On=log N//
    int BinarySearch(List Tb1, ElementType K)
    {
        int left, right, mid, NotFound = -1;

        left = 1;
        right = Tb1->Length;
        while(left <= right){
            mid = (left + right)/2;
            if(K < Tb1->Element[mid]) right = mid-1;
            else if(K > Tb1->Element[mid]) left = mid+1;
            else return mid;
        }
        return NotFound;
    }

//3.1 树的表示//
//3.2 二叉树//
  //二叉树的存储结构//
    //顺序存储 数组 完全二叉树 非完全二叉树也可补全后存入数组，但会造成空间浪费//
    //链表//
    typedef struct TreeNode* BinTree;
    struct TreeNode
    {
        ElementType Data;
        BinTree Left;
        BinTree Right;
    };
    typedef BinTree Position;
     
//3.3历遍//
       //递归//
       //先序历遍//
       void PreOrderTraversial( BinTree BT )
       {
           if(BT){
               printf("%d",BT->Data);
               PreOrderTraversial(BT->Left);
               PreOrderTraversial(BT->Right);
           }
       }
       //中序//
       void InOrderTraversial( BinTree BT )
       {
           if(BT)
                InOrderTraversial(BT->Left);
                printf("%d",BT->Data);
                InOrderTraversial(BT->Right);
           }
       }
       //后续//
       void PostOrderTraversial( BinTree BT )
       {
           if(BT){
               PostOrderTraversial(BT->Left);
               PostOrderTraversial(BT->Right);
               printf("%d",BT->Data);
           }
       }
       //非递归遍历//
        //中序 堆栈//
        typedef struct TreeNode* BinTree;
        struct TreeNode
        {
            ElementType Data;
            BinTree Left;
            BinTree Right;
        };

        typedef struct SNode* Stack;
        struct SNode
        {
            BinTree T;
            Stack Next;
        };

        Stack CreateStack()
        {
            Stack S;
            S = (Stack)malloc(sizeof(struct SNode));
            S->Next = NULL;
            return S;
        }
        
        int IsEmpty(Stack S)
        {
            return( S->Next == NULL);
        }

        void Push(Stack S, BinTree BT)
        {
            Stack tmp;
            tmp = (Stack)malloc(sizeof(struct SNode));
            tmp->T = BT;
            tmp->Next = S->Next;
            S->Next = tmp;
            return;
        }

        BinTree Pop(Stack S)
        {
            Stack tmp;
            BinTree BTtmp;
            if(IsEmpty(S)) return NULL;
            else{
                tmp = S->Next;
                BTtmp = tmp->T;
                S->Next = tmp->Next;
                free(tmp);
                return BTtmp;
            }
        }

        //中序//
        void InOrderTraversialWithStack(BinTree BT)
        {
            BinTree T = BT;
            Stack S = CreateStack();
            while( T || !IsEmpty(S)){
                while(T){
                    Push(S, T);
                    T = T->Left;
                }
                if(!IsEmpty(S)){
                    T = Pop(S);
                    printf("%5d",T->Data);
                    T = T->Right;
                }
            }
        }
        //先序//
        void PreOrderTraversialWithStack(BinTree BT)
        {
            BinTree T = BT;
            Stack S = CreateStack();
            while (T || !IsEmpty(S))
            {
                while(T){
                    printf("%5d",T->Data);
                    Push(S,T);
                    T = T->Left;
                }
                if(!IsEmpty(S)){
                    T = Pop(S);
                    T = T->Right;
                }
            }
        }
        //后序//
        void PostOrderTraversialWithStack(BinTree BT)
        {
            BinTree 
             T = BT;
            Stack S = CreateStack();
            while (T || !IsEmpty(S))
            {    
                while (T)
                {
                    while(T){
                        Push(S, T);
                        T = T->Left;
                    }
                    if(!IsEmpty(S)){
                        T = Pop(S);
                        Push(S, T);
                        T = T->Right;
                    }
                }
                T = Pop(S);
                printf("%5d",T->Data);
                if(!IsEmpty(S)){
                    T = Pop(S);
                    Push(S, T);
                    T = T->Right;
                }

            }
        }
    //层序遍历 队列实现 //
    struct Node
    {
        BinTree Data;
        struct Node* Next;
    };
    struct QNode
    {
         struct Node* Front;
         struct Node* Rear;
    };
    typedef struct QNode* Queue;

    Queue CreateQueue()
    {
        Queue Q;
        Q = (Queue)malloc(sizeof(struct QNode));
        Q->Front = NULL;
        Q->Rear = NULL;
        return Q;
    }

    AddQ( Queue Q, BinTree BT)
    {
        struct Node* QN;
        QN = (struct Node*)malloc(sizeof(struct Node));
        QN->Data = BT;
        QN->Next = NULL;
        if(Q->Front == NULL){
            Q->Front = Q->Rear = QN;
            return;
        }
        else{
            Q->Rear->Next = QN;
            Q->Rear = QN;
            return;
        }
    }
    int IsEmptyQ(Queue Q)
    {
        return (Q->Front == NULL);
    }

    BinTree DeleteQ(Queue Q)
    {
        BinTree BT;
        struct Node* tmp;
        if(!IsEmptyQ(Q)) return ERROR;
        else{
            tmp = Q->Front;
            BT = tmp->Data;
            if(Q->Front == Q->Rear) Q->Front = Q->Rear = NULL;
            else Q->Front = tmp->Next;
            free(tmp);
            return BT;
        }
    }


    void LevelOrderTraversial(BinTree BT)
    {
        Queue Q;
        BinTree T;
        if(!BT) return;
        Q = CreateQueue();
        AddQ(Q, BT);
        while(!IsEmptyQ(Q)){
            T = DeleteQ(Q);
            printf("%d",T->Data);
            if( T->Left ) AddQ(Q,T->Left);
            if( T->Right) AddQ(Q,T->Right);
        }
    }

  //遍历应用实例 //
  //输出二叉树叶子节点//
    void PreOrderTraversial( BinTree BT )
        {
            if(BT){
                if(!BT->Left && !BT->Right) printf("%d",BT->Data);
                PreOrderTraversial(BT->Left);
                PreOrderTraversial(BT->Right);
            }
        }
  //求二叉树的高度//
  int PostOrderGetHeight( BinTree BT)
  {
      int HL, HR, HMAX;
      if(BT){
        HL = PostOrderGetHeight(BT->Left);
        HR = PostOrderGetHeight(BT->Right);
        HMAX = (HL > HR)? HL : HR;
        return (HMAX + 1);
      }
      else return 0;
  }
   //二元运算表达式树及其遍历//
   //由两种遍历序列确定二叉树//
      //已知先序和中序 确定二叉树//
//树的同构//
   //二叉树的表示 链表，数组（满二叉树），静态链表//
     //静态链表表示//
     #define MaxTree 10;
     #define ElementType char;
     #define Tree int;
     #define Null -1;
    
    struct TreeNode
     {
         ElementType Data;
         Tree Left;
         Tree Right;
     }T1[MaxTree], T2[MaxTree];

     int main()
     {
         Tree R1,R2;

         R1 = BuildTree(T1);
         R2 = BuildTree(T2);

         if(Isomorphic(R1,R2)) printf("yes\n")
         else printf("no\n");

         return 0;

     }

     Tree BuildTree(struct TreeNode T[])
     {
         int i,N,Root = Null;
         int check[MaxTree];
         char cl,cr;

         scanf("%d\n",&N);
         if(N){
             for(i=0; i<N; i++) check[i] = 0;
             for(i=0; i<N; i++){
                 scanf("%c %c %c",&T[i].Data,&cl,&cr);
                 if(cl != '-'){
                    T[i].Left = cl-'0';
                    check[T[i].Left] = 1;
                 }
                 else T[i].Left = Null;
                 if(cr != '-'){
                    T[i].Right = cr-'0';
                    check[T[i].Right] = 1;
                 }
                 else T[i].Right = Null;
            }
            for(i=0; i<N; i++){
                if(check[i] = 0) break;
            }
            Root = i ;
         }
         return Root;
     }

int Isomorphic(Tree R1,Tree R2)
{
    if( R1 == Null && R2 == Null) 
        return 1;
    if( (R1 != Null && R2 == Null) || (R1 == Null && R2 != Null)) 
        return 0;
    if( T1[R1].Data != T2[R2].Data) 
        return 0;
    if( T1[R1].Left == Null && T2[R2].Left == Null)
        return (Isomorphic(T1[R1].Right, T2[R2].Right));
    if((T1[R1].Left != Null && T2[R2].Left != Null)
        && (T1[T1[R1].Left].Data == T2[T2[R2].Left].Data))
        
        return ((Isomorphic(T1[R1].Left, T2[R2].Left)) 
        && (Isomorphic(T1[R1].Right, T2[R2].Right)) )
    if((T1[R1].Left != Null && T2[R2].Left != Null)
        && (T1[T1[R1].Left].Data != T2[T2[R2].Left].Data))
        
        return ((Isomorphic(T1[R1].Left, T2[R2].Right)) 
        && (Isomorphic(T1[R1].Right, T2[R2].Left)) )
}

