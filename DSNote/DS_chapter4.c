#include<stdlib.h>
#include<stdio.h> 
    
    typedef struct TreeNode* BinTree;
    struct TreeNode
    {
        ElementType Data;
        BinTree Left;
        BinTree Right;
    };
    typedef BinTree Position;
//4.1二叉搜素树//  

//查找//
Position Find1( ElementType X, BinTree BST)
{
    if(!BST) return NULL;
    if(X > BST->Data)
        return Find( X, BST->Right);
    else if(X < BST->Data)
        return Find( X, BST->Left);
    else 
        return BST;
}
  //尾递归都可以用循环来实现 查找效率与树的高度有关//
  Position Find2( ElementType X, BinTree  BST)
  {
      while (BST)
      {
          if(X > BST->Data) BST = BST->Right;
          else if(X < BST->Data) BST = BST->Left;
          else return BST;
      }
      return NULL;
  }

//找最大和最小值//
 //迭代//
 Position FindMin(BinTree BST)
 {
     while(BST->Left){
         BST = BST->Left;
     }
     return BST;
 }

  Position FindMax(BinTree BST)
 {
     while(BST->Right){
         BST = BST->Right;
     }
     return BST;
 }
 //递归//
 Position FindMin2(BinTree BST)
 {
     if(!BST) return NULL;
     else if(!BST->Left) return BST;
     else return FindMin2(BST->Left);
 }

 //BST插入//
 BinTree Insert(ElementType X, BinTree BST)
 {
     if(BST){
        if(X > BST->Data && BST->Right){
             return Insert( X, BST->Right);
        }
        else if(X > BST->Data && !BST->Right){
            BinTree BT;
            BT = (BinTree)malloc(sizeof(struct TreeNode));
            BT->Data = X;
            BT->Left = BT->Right = NULL;
            BST->Right = BT;
            return BST;
        }
        if(X < BST->Data && BST->Left){
            return Insert( X, BST->Left);
        }
        else if(X < BST->Data && !BST->Left){
            BinTree BT;
            BT = (BinTree)malloc(sizeof(struct TreeNode));
            BT->Data = X;
            BT->Left = BT->Right = NULL;
            BST->Left = BT;
            return BST;   
     }
     else{
            BinTree BT;
            BT = (BinTree)malloc(sizeof(struct TreeNode));
            BT->Data = X;
            BT->Left = BT->Right = NULL;
            return BT;
     }
     return BST;
 }

  //更好的//
BinTree Insert2(ElementType X, BinTree BST)
   {
       if(!BST){
            BST = (BinTree)malloc(sizeof(struct TreeNode));
            BST->Data = X;
            BST->Left = BST->Right = NULL;
            return BST;
       }
       else{
            if(X > BST->Data)
                BST->Right = Insert2(X, BST->Right);
            else if(X < BST->Data)
                BST->Left = Insert2(X, BST->Left);
       }
       return BST;  
   }

//删除//
BinTree Delete( ElementType X, BinTree BST)
{
    Position tmp;
    if(!BST) printf("not found the element you want!");
    else if( X < BST->Data)
        BST->Left = Delete( X, BST->Left) ;
    else if( X > BST->Data)
        BST->Right = Delete( X, BST->Right);
    else{
        if( BST->Left && BST->Right ){
            tmp = FindMin(BST->Right);
            BST->Data = tmp->Data;
            BST->Right = Delete(tmp->Data,BST->Right);
        }
        else{
            tmp = BST;
            if(!BST->Left){
                BST = BST->Right;
            }
            else if(!BST->Right){
                BST = BST->Left;
            }
            free(tmp);
            }
            return BST;
        }  
    }
}

//4.2平衡二叉树//
  //定义//
  //调整//

  