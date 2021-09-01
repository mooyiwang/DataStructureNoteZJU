 #include<stdio.h>
 #include<stdlib.h>

 struct a[]
 {
     int coef;
     int expon;
 };
 
//用链表存储多项式//
 typedef struct PolyNode *Polynomial;

struct PolyNode
{
    int coef;
    int expon;
    Polynomial Link;
}

//2.1.2-3顺序表的顺序存储实现//
   //数组实现//
     //定义//
typedef struct LNode *List;
struct LNode
{
    ElementType data[MAXSIZE];
    int Last; //最后一个数的下标//
};

struct LNode L;

List Ptrl;

L.data[1]
Ptrl->data[1]
Length = L.Last+1
     
     //建立一个空表//
     List MakeEmpty()
     {
         List Ptrl;
         Ptrl = (List)malloc(sizeof(struct LNode));
         Ptrl->Last = -1; //数组下标是从0开始，如果将Last赋值为0，则不是空表了//
         return Ptrl;
     }
     //查找 Tn=On//
     int Find(ElementType X,List Ptrl)
     {
         int i = 0;
         while(i<=Ptrl->Last && Ptrl->data[i] != X)
           i++;
         if(i>Ptrl->Last) return -1;
         else return i;
     }
     //插入（在第i（1开始）个位置插入一个数X） Tn=On//
     void Insert(ElementType X, int i, List Ptrl)
     {
         int j;
         if(Ptrl->Last == MAXSIZE-1)
         {
             printf("the list is full!!");
             return;
         }
         else if (i<1 || i> Ptrl->Last+2)
         {
             printf("invalid insert position!!");
             return;
         }
         for(j = Ptrl->Last; j>=i-1; j--)
         {
             Ptrl->data[j+1] = Ptrl->data[j];
         }
         Ptrl->data[i-1] = X;
         Ptrl->Last++;
         return;
     }
     //删除 Tn=On//
     void Delete(int i,List Ptrl)
     {
        int j;
        if (i<1 || i> Ptrl->Last+1)
        {
            printf("invalid delete position!!");
            return;
        }
        for(j=i; j<=Ptrl->Last; j++)
        {
            Ptrl->data[j-1] = Ptrl->data[j];
        }
        Ptrl->Last--;
        return;
     }
 // 2.1.4-5链表表示//
    //定义// 
    typedef struct LNode *List;
    struct LNode
    {
        ElementType data;
        List Next;
    };

    struct LNode L;
    List Ptrl;
    //求表长 Tn=On//
    int Length(List Ptrl)
    {
        List p = Ptrl;
        int j = 0;
        while(p)
        {
            p = p->Next;
            j++;
        }
        return j;
    }
    //查找 Tn=On//
      //按序号查找 Kth//
    List FindKth(List Ptrl, int K)
    {
        List p = Ptrl;
        int i = 1;
        while(p!=NULL && i<K )
        {
            p = p->Next;
            i++;
        }
        if( i==K ) return p; else return NULL; //也可以 return p;//
    }
    //按值查找//
    List Find(ElementType X, List Ptrl)
    {
        List p = Ptrl;
        while(p->data!=X && p!=NULL)
        {
            p = p->Next;
        }
        return p;
    }
    //插入 在第i-1个节点后插入 Tn=On ,Tavg=N/2 //
    List Insert(ElementType X, int i, List Ptrl)
    {
        List p,s;
        if (i == 1)
        {
            s = (List)malloc(sizeof(struct LNode));
            s->data = X;
            s->Next = Ptrl;
            return s;
        }
        p = FindKth(Ptrl, i-1);
        if(p == NULL)
        {
            printf("invalid insert position!");
            return NULL;
        }
        else
        {
            s = (List)malloc(sizeof(struct LNode));
            s->data = X;
            s->Next = p->Next;
            p->Next = s;
            return Ptrl;
        }
    }
    //删除 删去第i个位置节点 Tn=On Tavg=n/2 // 
    List Delete(int i, List Ptrl)
    {
        List p,s;
        if(i==1)
        {
            s = Ptrl;
            if(s!=NULL) Ptrl = Ptrl->Next;
            else return NULL;
            free(s);
            return Ptrl;
        }
        p = FindKth(Ptrl, i-1);
        if(p==NULL)
        {
            printf("第i-1个节点不存在");
            return NULL;
        }
        else if(p->Next==NULL)
        {
            printf("第i个节点不存在");
            return NULL;
        }
        else
        {
            s = p->Next;
            p->Next = s->Next;
            free(s);
            return Ptrl;
        }
    }
//2.1.6 广义表和多重链表//
 //广义表//
   //定义//
      typedef struct GNode* GList;
      struct GNode
      {
          int Tag;  //标志域 0表示单元素 1表示广义表//
          union 
          {
              ElementType Data;
              GList SubList;
          }URegion;
          GList Next;
      };
 // 多重链表 多个指针域 但双向；链表不属于//
   //十字链表存储矩阵//


//2.2 堆栈 On//
   //栈的顺序存储实现 数组//
   #define MaxSize 
   typedef struct SNode *Stack;
   struct SNode
   {
       ElementType Data[MaxSize];
       int Top;
   };

   Stack Create()
   {
       Stack S;
       S = (Stack)malloc(sizeof(struct SNode));
       S->Top = -1;
       return S;
   }
   //入栈//
   void Push(Stack PtrS, ElementType item)
   {
       if(PtrS->Top == MaxSize-1)
       {
           printf("the stack is full!");
           return;
       }
       else
       {
           PtrS->Data[PtrS->Top+1] = item;
           PtrS->Top++; // PtrS->Data[++(PtrS->Top)] = item;//
           return;
       }
   }
   //出栈//
   ElementType Pop(Stack PtrS)
   {
       if(PtrS->Top == -1){
           printf("the stack is empty!");
           return ERROR;
       }
       else{
           return PtrS->Data[(PtrS->Top)--]; //这里--的位置很重要//
       } 
   }
   //一个数组实现两个堆栈 最大化利用空间//
   #define MaxSize
   typedef struct DStack *DStackPoint
   struct DStack
   {
       ElementType Data[MaxSize];
       int Top1;
       int Top2;
   }S;
   S.Top1 = -1;
   S.Top2 = MaxSize;
     
      //入栈//
      void PushToDstack(DStackPoint PtrS, ElementType item, int Tag)
      {
          if(PtrS->Top2 - PtrS->Top1 ==1){
              printf("the DStack is full!");
              return;
          }
          if(Tag == 1)
              PtrS->Data[++(PtrS->Top1)] = item;
          else
              PtrS->Data[--(PtrS->Top2)] = item;
      }
      //出栈//
      ElementType PopFromDstack(DStackPoint PtrS, int Tag)
      {
          if(Tag = 1){
              if(PtrS->Top1 == -1){
                  printf("stack 1 is empty!");
                  return NULL;
              }
              else{
                  return PtrS->Data[(PtrS->Top1)--];
              }
          }
          else{
              if(PtrS->Top2 == MaxSize){
                  printf("stack 2 is empty!");
                  return NULL;
              }
              else{
                  return PtrS->Data[(PtrS->Top2)++];
              }
          }
      }
    //堆栈的链式存储实现 单向链表 Top在链表头部//
      //建立//
      typedef struct SNode *Stack;
      struct SNode{
          ElementType Data;
          Stack Next;
      };

      Stack CreateStack()
      {
          Stack S;
          S = (Stack)malloc(sizeof(struct SNode));
          S->Next = NULL;
          return S;
      }
      
      int IsEmpty(Stack S) //如果为空，则返回1//
      {
          return (S->Next == NULL);
      } 
      //入栈//
      void Push(ElementType item, Stack S)
      {
          Stack TmpCell;
          TmpCell = (Stack)malloc(sizeof(struct SNode));
          TmpCell->Data = item;
          TmpCell->Next = S->Next;
          S->Next = TmpCell;
      }
      //出栈 删除并且返回栈顶的元素//
      ElementType Pop(Stack S)
      {
          Stack FirstCell;
          ElementType FirstData;
          if(IsEmpty(S)){
              printf("the stack is empty!");
              return NULL;
          }
          else{
              FirstCell = S->Next;
              S->Next = FirstCell->Next;
              FirstData = FirstCell->Data;
              free(FirstCell);
              return FirstData;
          }
      }
//2.3 对列//
   // 数组来实现//
     //定义//
        #define MaxSize
        typedef struct QNode *Queue;
        struct QNode{
            ElementType Data[MaxSize];
            int rear;
            int front;
        };
     //入队列//
     void AddQ(Queue PtrQ, ElementType item)
     {
         if((PtrQ->rear+1)%MaxSize == PtrQ->front){
             printf("queue is full!");
             return;
         }
         PtrQ->rear = (PtrQ->rear+1)%MaxSize;
         PtrQ->Data[PtrQ->rear] = item;
     }
     //出队列//
     ElementType DeleteQ(Queue PtrQ)
     {
         if(PtrQ->rear == PtrQ->front){
             printf("the queue is empty!");
             return ERROR;
         }
         else{
             PtrQ->front = (PtrQ->front +1)%MaxSize;
             return PtrQ->Data[PtrQ->front];
         }    
     }
  //单向链表存储队列// 
  //定义 //
    struct Node{
        ElementType Data;
        struct Node* Next;
    };
    struct QNode{
        struct Node* front;
        struct Node* rear;
    };
    typedef struct QNode* Queue;
    Queue PtrQ;
    //入队列//
    void AddToQueue(Queue PtrQ, ElementType item)
    {
        struct Node* SQ;
        SQ = (struct Node*)malloc(sizeof( struct Node));
        SQ->Data = item;
        if(PtrQ->front == NULL){
            PtrQ->front = PtrQ->rear = SQ;
            SQ->Next =NULL;
            return;
        }
        else{
            PtrQ->rear = PtrQ->rear->Next  = SQ;
            SQ->Next = NULL;
            return; 
        }

    }
    
    //出队列//
    ElementType DeleteFromQueue(Queue PtrQ)
    {
        struct Node* FrontCell;
        ElementType FrontData;
        if(PtrQ->front == NULL){
            printf("the queue is empty!");
            return ERROR;
        }
        FrontCell = PtrQ->front;
        if(PtrQ->front == PtrQ->rear)
            PtrQ->front = PtrQ->rear = NULL;
        else PtrQ->front = FrontCell->Next;
        FrontData = FrontCell->Data;
        free(FrontCell);
        return FrontData;
    }  

//2.4多项式加法实现//
 typedef struct PolyNode *Polynomial;
struct PolyNode
{
    int coef;
    int expon;
    Polynomial Link;
};

Polynomial P1,P2;

void Attach(int c, int e, Polynomial* pRear)//1.申请位置2.填数3.加在表后面4.将rear向后移//
{
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coef = c;
    P->expon = e;
    P->Link = NULL;
    (*pRear)->Link = P;
    *pRear = P; //!!必须传rear的地址来改变rear的值，此函数无返回，若只传rear的值并不能真正修改rear//
}

int Compare(int a,int b)
{
    if(a > b) return 1;
    else if(a == b) return 0;
    else if(a < b) return -1;
}

Polynomial PolyAdd(Polynomial P1, Polynomial P2)
{
    Polynomial front, rear, tmp;
    int sum;
    rear = (Polynomial)malloc(sizeof(struct PolyNode));
    front = rear;
    if(P1 && P2){
        switch (Compare(P1->expon,P2->expon)) //这里的Compare和Attach 都是自己定义的//
        {
        case 1:
            Attach(P1->coef,P1->expon,&rear);
            P1 = P1->Link;
            break;
        case -1:
            Attach(P2->coef,P2->expon,&rear);
            P2 = P2->Link;
            break;
        case 0:
            sum = P1->coef + P2->coef;
            if(sum) Attach(sum, P1->expon, &rear);
            P1 = P1->Link;
            P2 = P2->Link;
            break;
        }
    }
    for(;P1;P1 = P1->Link) Attach(P1->coef,P1->expon,&rear);
    for(;P2;P2 = P2->Link) Attach(P2->coef,P2->expon,&rear);
    rear->Link =NULL;
    tmp = front;
    front =tmp->Link;
    free(tmp);
    return front; 
}

//2.5 多项式综合应用//
  //多项式的表示//
  typedef struct PolyNode* Polynomial;
  struct PolyNode
  {
      int coef;
      int expon;
      Polynomial Link;
  };


  
  
   //读入多项式//
    void Attach(int c, int e, Polynomial* pRear)//1.申请位置2.填数3.加在表后面4.将rear向后移//
    {
        Polynomial P;
        P = (Polynomial)malloc(sizeof(struct PolyNode));
        P->coef = c;
        P->expon = e;
        P->Link = NULL;
        (*pRear)->Link = P;
        *pRear = P; //!!必须传rear的地址来改变rear的值，此函数无返回，若只传rear的值并不能真正修改rear//
    }
    
int Compare(int a,int b)
{
    if(a > b) return 1;
    else if(a == b) return 0;
    else if(a < b) return -1;
}

    Polynomial ReadPoly()
    {
        Polynomial P,Rear,tmp;
        int c,e,N;

        scanf("%d",&N);
        P = (Polynomial)malloc(sizeof(struct PolyNode));
        P->Link = NULL;
        Rear = P;
        while (N--)
        {
            scanf("%d %d",&c,&e);
            Attach(c, e, &Rear);
        }
        tmp = P;
        P = tmp->Link;
        free(tmp);
        return P;
    }

    //多项式相加//
    Polynomial AddPoly(Polynomial P1, Polynomial P2)
    {
        int sum;
        Polynomial P,tmp,Rear;
        P = (Polynomial)malloc(sizeof(struct PolyNode));
        P->Link = NULL;
        Rear = P;
        if(P1 && P2){
            switch (Compare(P1->expon,P2->expon))
            {
            case 1:
                Attach(P1->coef,P1->expon,&Rear);
                P1 = P1->Link;
                break;
            case -1:
                Attach(P2->coef,P2->expon,&Rear);
                P2 = P2->Link;
                break;
            case 0:
                sum = P1->coef + P2->coef;
                if(sum) Attach(sum, P1->expon, &Rear);
                P1 = P1->Link;
                P2 = P2->Link;
                break;
            }
        }
        for(;P1;P1 = P1->Link) Attach(P1->coef,P1->expon,&Rear);
        for(;P2;P2 = P2->Link) Attach(P2->coef,P2->expon,&Rear);
        tmp = P;
        P = P->Link;
        free(tmp);
        return P;
    }

    //两个多项式相乘 2ways：1.乘变加 2.插入//
    //插入法//
    Polynomial Mult(Polynomial P1,Polynomial P2)
    {
        Polynomial t1,t2,P,Rear,tmp;
        int c,e;

        if(!P1 || !P2) return NULL;
        
        t1 = P1; t2 = P2;
        P = (Polynomial)malloc(sizeof(struct PolyNode));
        P->Link = NULL;
        Rear = P;
        while(t2){
            c = t1->coef * t2->coef;
            e = t1->expon + t2->expon;
            Attach(c, e, &Rear);
            t2 = t2->Link;
        }
        
        t1 = t1->Link;
        while(t1){
            t2 = P2;Rear = P;
            while(t2){
                c = t1->coef * t2->coef;
                e = t1->expon + t2->expon;
                while(Rear->Link && Rear->Link->expon > e) Rear = Rear->Link;
                
                if(Rear->Link == NULL){
                    Attach(c, e, &Rear);
                }
                else if(Rear->Link->expon == e){
                    if(Rear->Link->coef +c)
                        Rear->Link->coef += c;
                    else{
                        tmp = Rear->Link;
                        Rear->Link = tmp->Link;
                        free(tmp);
                    }
                }
                else if(Rear->Link->expon < e){
                    tmp = (Polynomial)malloc(sizeof(struct PolyNode));
                    tmp->coef = c;
                    tmp->expon = e;
                    tmp->Link = Rear->Link;
                    Rear->Link = tmp;
                    Rear = Rear->Link;
                }
                t2 = t2->Link;
            }
            t1 = t1->Link;
        }
        tmp = P;
        P = tmp->Link;
        free(tmp);
        return P;
    }
//多项式输出//
void PrintPoly(Polynomial P)
{
    int flag = 0; /*调整输出格式*/
    if(!P) {
        printf("0 0\n");
        return;
    }
    while(P){
        if(!flag) flag = 1;
        else  printf(" ");
        printf("%d %d",P->coef,P->expon);
        P = P->Link;
    }
    printf("\n");
    return;
}

int main()
{
    Polynomial P1,P2,P3,P4;
    P1 = ReadPoly();
    P2 = ReadPoly();
    P3 = Mult(P1, P2);
    PrintPoly( P3 );
    P4 = AddPoly(P1, P2);
    PrintPoly( P4 );
    return 0;
}