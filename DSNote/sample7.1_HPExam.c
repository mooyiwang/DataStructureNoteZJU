//哈利波特的考试
#include<stdlib.h>
#include<stdio.h> 
#define MaxVertexNum 100
#define INFINITY 65535
typedef int WeightType;
typedef int Vertex;

typedef struct GNode* PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;

typedef struct ENode* PtrToEdge;
struct ENode
{
    Vertex V1,V2;
    WeightType Weight;
};
typedef PtrToEdge Edge;

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


void InsertEdge( MGraph Graph, Edge E)
{
    Graph->G[(E->V1)-1][(E->V2)-1] = E->Weight;
    Graph->G[(E->V2)-1][(E->V1)-1] = E->Weight;//无向图插两遍// 
}

MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    int Nv;
    int i;


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
    return Graph;
}
 
void Floyd( MGraph Graph, WeightType D[][MaxVertexNum])
 {
     Vertex i,j,k;

     for(i=0; i<Graph->Nv; i++)
        for(j=0; j<Graph->Nv; j++){
            D[i][j] = Graph->G[i][j];
        }
        for(k=0; k<Graph->Nv; k++)
            for(i=0; i<Graph->Nv; i++)
                for(j=0; j<Graph->Nv; j++)
                    if( D[i][k] + D[k][j] < D[i][j]){
                        D[i][j] = D[i][k] + D[k][j];
                    }
 }




void FindAnimal( MGraph Graph)
{
    Vertex i,j,Animal;
    WeightType Max;
    WeightType D[MaxVertexNum][MaxVertexNum];
    WeightType MaxWeight[Graph->Nv], MinDist = INFINITY;
    Floyd( Graph, D );
    for(i=0; i<Graph->Nv; i++){
        Max = 0;
        for(j=0; j<Graph->Nv; j++)
            if( j != i && D[i][j] > Max ) Max = D[i][j];
        MaxWeight[i] = Max;
    }
    for(i=0; i<Graph->Nv; i++)
        if( MaxWeight[i] < MinDist ){
            MinDist= MaxWeight[i];
            Animal = i+1 ;
    }
    printf("%d %d\n", Animal, MinDist);
}



//另一种
WeightType FindMax( WeightType D[][MaxVertexNum], Vertex V, int VertexNum )
{
    Vertex j;
    WeightType Max=0;
    for(j=0; j<VertexNum; j++){
        if( j!= V && D[V][j] > Max)
            Max = D[V][j];
    }
    return Max;
}

void FindAnimal( MGraph Graph)
{
    Vertex i,Animal;
    WeightType MaxDist=0;
    WeightType D[MaxVertexNum][MaxVertexNum];
    WeightType MinDist = INFINITY;
    Floyd( Graph, D );
    for(i=0; i<Graph->Nv; i++){
        MaxDist = FindMax( D, i, Graph->Nv);
        if( MaxDist = INFINITY){
            printf("0\n");
            return;
        }
        if( MaxDist < MinDist){
            MinDist = MaxDist;
            Animal = i+1;
        }
    }
    printf("%d %d\n", Animal, MinDist);
}

int main()
{
    MGraph G = BuildGraph();
    FindAnimal(G);
    return 0;
}
