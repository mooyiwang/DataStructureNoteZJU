#include<stdio.h>
#include<stdlib.h>
//6.1 图的定义//
//图的表示//
  //邻接矩阵//
  //邻接表//  
//6.2图的遍历//
  //DFS 深度优先搜索//

     //伪码描述// //类似于先序遍历//
  void DFS( Vertex V)
  {
      visited[V] = true;
      for( V的每个邻接点W )
        if( !visited[W] )
            DFS(W);
  }
  //BFS 广度优先搜索// // 层序遍历//
 void BFS(Vertex V)
 {
     visited[V] = true;
     Enqueue(V, Q);
     while(!IsEmpty(Q)){
         V = Dequeue(Q);
         for( V的每个邻接点W ){
             if(!visited[W]) {
                 visited[W] = true;
                 Enqueue(W, Q);
             }
         }
     }
 }
 //为何会有两种遍历方法//

 //存在图不连通的情况//
 void ListComponents( Graph G)
 {
     for( each V in G){
         if(!visited[V]){
             DFS(V); /*BFS(V);*/
         }
     }
 }

 
 
 //补充 图的具体C语言实现//
typedef struct GNode* PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data[MaxVertexNum];
};
typedef PtrToGNode MGraph;
typedef int Vertex;

//MGraph初始化//
MGraph CreateGraph( int VertexNum )
{
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    Vertex V,W;
    for(V=0; V<Graph->Nv; V++){
        for(W=0; W<Graph->Nv; W++){
            Graph->G[V][W] = INFINITY;
        }
    }

    return Graph;
}

//插入边//
typedef struct ENode* PtrToEdge;
struct ENode
{
    Vertex V1,V2;
    WeightType Weight;
};
typedef PtrToEdge Edge;

void InsertEdge( MGraph Graph, Edge E)
{
    Graph->G[E->V1][E->V2] = G->Weight;
    Graph->G[E->V2][E->V1] = G->Weight;//无向图插两遍// 
}

MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    int Nv;
    int i;
    Vertex V;

    scanf(" %d",&Nv);
    Graph = CreateGraph( Nv );
    scanf(" %d",&(Graph->Ne));
    if(Graph->Ne != 0){
        E = (Edge)malloc(sizeof(struct ENode));
        for(i=0; i<Graph->Ne; i++){
            scanf(" %d %d %d",&(E->V1),&(E->V2),&(E->Weight));
            InsertEdge( Graph, E);
        }
    }
    for(V=0; V<Graph->Nv; V++){
        scanf(" %d",&(Graph->Data[V]));
    }
    return Graph;
}

//更简单//

int G[MAXN][MAXN],Nv,Ne;//提前声明为全局变量//

void BuildGraphNew()
{
    int i,j,v1,v2,w;
    scanf(" %d",&Nv);
    for(i=0; i<Nv; i++){
        for(j=0; j<Nv; j++){
            G[i][j] = 0;
        }
    }
    scanf(" %d",&Ne);
    for(i=0; i<Ne; i++){
        scanf(" %d %d %d", &v1,&v2,&w);
        G[v1][v2] = w;
        G[v2][v1] = w;
    }
}

//邻接表表示//
typedef struct GNode *PtrToGNode;
struct GNode
{
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

typedef struct VNode
{
    PtrToAdjVNode FirstEdge;
    DataType Data;
}AdjList[MaxVertexNum];

struct AdjVNode
{
    Vertex AdjV;//邻接点下标 终点//
    WeightType Weight;
    PtrToAdjVNode NextAdjVNode;
};
typedef struct AdjVNode* PtrToAdjVNode;

LGraph CreateGraph( int VertexNum )
{
    LGraph Graph;
    Vertex V;

    Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    for(V=0; V<VertexNum; V++){
        Graph->G[V].FirstEdge = NULL;
    }
    return Graph;
}


typedef struct ENode* PtrToEdge;
struct ENode
{
    Vertex V1,V2;
    WeightType Weight;
};
typedef PtrToEdge Edge;

void InsertEdge( LGraph Graph, Edge E )
{
    PtrToAdjVNode NewNode /*LastNode*/;

    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;
    
    /*
    if( !Graph->G[E->V1].FirstEdge ) Graph->G[E->V1].FirstEdge= NewNode;
    else{ 
        
        for( LastNode = Graph->G[E->V1].FirstEdge ; !LastNode->NextAdjVNode ; LastNode = LastNode->NextAdjVNode );
        LastNode->NextAdjVNode = NewNode;
    }*///每次都插在第一个不是更简单吗？

    NewNode->NextAdjVNode = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;

    //无向图情况//

    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V1;
    NewNode->Weight = E->Weight;
    
    NewNode->NextAdjVNode = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph()
{
    LGraph Graph;
    Edge E;
    int Nv;
    int i;
    Vertex V;

    scanf(" %d",&Nv);
    Graph = CreateGraph( Nv );
    scanf(" %d",&(Graph->Ne));
    if(Graph->Ne != 0){
        E = (Edge)malloc(sizeof(struct ENode));
        for(i=0; i<Graph->Ne; i++){
            scanf(" %d %d %d",&(E->V1),&(E->V2),&(E->Weight));
            InsertEdge( Graph, E);
        }
    }
    for(V=0; V<Graph->Nv; V++){
        scanf(" %d",&(Graph->G[V].Data));
    }
    return Graph;
}

//更简单//
AdjList G;
int Nv,Ne;
PtrToAdjVNode NewNode;

void BuildGraph()
{
    int i;
    int v1,v2,w;
    scanf(" %d",&Nv);
    for(i=0; i<Nv; i++){
        G[i].FirstEdge =NULL;
    }
    scanf(" %d",&Ne);
    for(i=0; i<Ne; i++){
        scanf(" %d %d %d", &v1,&v2,&w);
        NewNode->Weight = w;
        NewNode->AdjV = v2;
        NewNode->NextAdjVNode = G[v1].FirstEdge;
        G[v1].FirstEdge = NewNode;
        
        NewNode->Weight = w;
        NewNode->AdjV = v1;
        NewNode->NextAdjVNode = G[v2].FirstEdge;
        G[v2].FirstEdge = NewNode;
    }
}