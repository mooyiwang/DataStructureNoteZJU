//8.1最小生成树问题 Minimum Spanning Tree
//连通图 最少的边，且每条边都是最短路径
//贪心
//Prim算法

//回顾 Dijkstra算法
void Dijkstra( Vertex S )
{
    while(1){
        V = 未收录顶点中dist最小的；
        if(已经全部收录完了) break;
        collected[V] = true;
        for( V 的每个邻接点 W )
            if( collected[W] == false )
                if( dist[V] + E<V,W> < dist[W] ){
                    dist[W] = dist[V] + E<V,W>;
                    path[W] = V;
                }
    }
}

void Prim()
{
    MST = {s};
    while(1){
        V = 未收录顶点中dist最小的;
        if(这样的V不存在) break;
        dist[V] = 0;
        for( V 的每个邻接点 W )
            if( dist[W] != 0 )
                if( E<V, W> < dist[W] ){
                    dist[W] = E<V, W>;
                    parent[W] = V;
                }
    }
    if( MST中收入的顶点不到|V|个) Error("生成树不存在");
}
//T=O(V^2) 对稠密图是合算的


//Kruskal算法
void Kruskal( Graph G )
{
    MST = {};
    while( MST中收的边数不到|V|-1 条 && E 中还有边  ){
        从 E 中取一条权重最小的边 E(V, W) ; //最小堆存 logE
        将 E(V, W) 从 E 中删除;
        if(  E(V, W) 不在MST中构成回路 ) //并查集 
            将 E(V, W) 加入 MST;
        else 彻底无视E(V, W); 
    }
     if( MST中收的边数不到|V|-1 条) Error("生成树不存在");
}
//T = O(E * logE) 稀疏图

//6.3 拓扑排序
//AOV-Activity On Vertex

void TopSort()//有VOA图打印出序列
{
    for( cnt=0; cut<|V|; cnt++){
        V = 未输出的入度为0的顶点; //O(V)
        if(这样的V不存在){
            Error(" 图中有回路 ")
            break;
        }
        输出V，或者记录输出V的编号;
        for( V 的每个邻接点 W) 
            Indegree[W]--;//删除 E<V, W>;
    }
}
// T=O(V^2)

//更简单的算法，随时将入度变为0的点装入一个容器，到时直接从里面取就可以
void TopSort()
{
    for( 图中的每一个顶点V )
        if(Indegree[V] == 0)
            Enqueue( V, Q );
    while( !IsEmpty(Q) ){
        V = Dequeue(Q);
        输出V，或者记录输出V的编号;
        cnt++;
        for( V 的每个邻接点 W) 
            Indegree[W]--;//删除 E<V, W>;
            if(Indegree[W] == 0)
                Enqueue( W, Q );
    }
    if( cnt != |V|输出顶点的个数小于V)
         Error(" 图中有回路 ")
}
// T=O(V+E)

//AOE-Activity On Edge
void Period()
{   for( 图中的每一个顶点V )
        if(Indegree[V] == 0)
            Earliest[V] = 0;
            Enqueue( V, Q );
    while( !IsEmpty(Q) ){
        V = Dequeue(Q);
        for( V 的每个邻接点 W) 
            for( W的每个前序顶点U) Earliest[W] = max{ Earliest[U] + C<U, W>};
            Indegree[W]--;//删除 E<V, W>;
            if(Indegree[W] == 0)
                Enqueue( W, Q );
    }
}
