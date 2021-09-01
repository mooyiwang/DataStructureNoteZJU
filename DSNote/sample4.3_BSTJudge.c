#include<stdlib.h>
#include<stdio.h> 
//判断两个序列是否构成同样的的BST//
 //建树//
typedef struct TreeNode* Tree;
struct TreeNode
{
    int v;
    Tree Left,Right;
    int flag;
};
Tree MakeTree( int N );
Tree Insert(Tree T, int V);
int check(Tree T,int V);
int Judge(Tree T, int N);
void ResetT(Tree T);
void FreeTree(Tree T);
Tree NewNode(int V);


//程序框架//
    
    int main()
    {
        int N,L,i;
        Tree T;

        scanf(" %d",&N);
        while (N){
            scanf(" %d",&L);
            T = MakeTree(N);
            for(i=0;i<L;i++){
                if(Judge(T,N)) printf("Yes\n");
                else printf("NO\n");
                ResetT(T);
            }
            FreeTree(T);
            scanf(" %d",&N);
        }
        return 0;
    }


/*建立树*/
    Tree MakeTree( int N )
    {
        int i,V;
        Tree T;

        scanf("%d",&V);
        T = NewNode(V);
        for(i=1;i<N;i++){
            scanf("%d",&V);
            T = Insert(T,V);
        }
        return T; 
    }
    
    Tree NewNode(int V)
    {
        Tree T;
        T = (Tree)malloc(sizeof(struct TreeNode));
        T->v = V;
        T->Left = T->Right = NULL;
        T->flag = 0;
        return T;
    }

    Tree Insert(Tree T, int V)
    {
        if(!T)
            T = NewNode(V);
        else{
            if(V < T->v)
                T->Left = Insert(T->Left, V);
            else if(V > T->v)
                T->Right = Insert(T->Right, V);
        }
        return T;
    }

//还可以这样写//
/*
Tree MakeTree( int N )
    {
        int i,V;
        Tree T=NULL;

        for(i=0;i<N;i++){
            scanf(" %d",&V);
            T = Insert(T,V);
        }
        return T; 
    }

    Tree Insert(Tree T, int V)
    {
        if(!T){
            T = (Tree)malloc(sizeof(struct TreeNode));
            T->v = V;
            T->Left = T->Right = NULL;
            T->flag = 0;
            return T;
        }
        else{
            if(V < T->v)
                T->Left = Insert(T->Left, V);
            else if(V > T->v)
                T->Right = Insert(T->Right, V);
        }
        return T;
    }
    
*/
   //如何判别//
   int Judge(Tree T, int N)
   {
       int i, V, tag=0;
       if(!T) return 0;
       scanf(" %d",&V);
       if(V == T->v) tag =1;
       T->flag =1;
       for(i=1; i<N; i++){
           scanf(" %d",&V);
           if(tag && check(T,V)) tag=1;
           else tag=0;
       }
       return tag;
   }

   int check(Tree T,int V)
   {
       if(T->flag){
           if(V < T->v) return check(T->Left,V);
           else if(V > T->v) return check(T->Right, V);
           else return 0;
       }
       else{
           if(V == T->v){
               T->flag = 1;
               return 1; 
           }
           else return 0;
       }
   }

//附属的一些函数//
void ResetT(Tree T)
{
    if(T->Left) ResetT(T->Left);
    if(T->Right) ResetT(T->Right);
    T->flag = 0;
}

void FreeTree(Tree T)
{
    if(T->Left) FreeTree(T->Left);
    if(T->Right) FreeTree(T->Right);
    free(T);
}


