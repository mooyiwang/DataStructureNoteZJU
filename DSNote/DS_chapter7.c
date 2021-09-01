#include<stdio.h>
#include<stdlib.h>

//7.1最短路径问题//

// 无权图的单源最短路径//

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
//T=O(V + E)//
 void Unweighted( Vertex S ) 
 {
     Enqueue(S,Q);
     while( !IsEmpty(Q) ){
         V = Dequeue(Q);
         for( V的每个邻接点 W){
             if( dist[W]<0){
                 dist[W] = dist[V] + 1;
                 path[W] = V;
                 Enqueue(W,Q);
             }
         }
     }
 }

 //有权图单源最短路径//
 //Dijkstra// 
//不能解决有负边的问题//
 void Dijkstra( Vertex S)
 {
     while(1){
         V = 未收录点中dist最小者;
        if( 这样的V不存在，点已经全部收录) break;
         collected[V] = true;
         for( V的每个邻接点W )
            if( collected(W) == false )
                if( dist[V] + E<V,W> < dist[W]){
                    dist[W] = dist[V] + E<V,W>;
                    path[W] = V;
                }
     }
 }
 // 时间复杂度取决于如何寻找未收录中dist最小点//
 /*1.直接全部扫描 扫描过程 O(V)
       总的 T=O(V^2 + E )  稠密图
   2.dist 存在最小堆之中  找及更新堆的值O(log V) 
            T=O(V*logV + E*logV) = O(E*logV)   稀疏图 

//多源最短路的算法//
/*1.将单源最短路算法调用V次 稀疏图用更好
    稠密图 T=O( V^3 + E*V ) 就比较大
    稀疏图 T=O( V^2 * LogV)
  
  2.Floyd算法 稠密图用更好
     T=O(V^3)
     */
 
bool Floyd()
 {
     Vertex i,j,k;

     for(i=0; i<N; i++)
        for(j=0; j<N; j++){
            D[i][j] = G[i][j];
            path[i][j] = -1;
        }
        for(k=0; k<N; k++){
            for(i=0; i<N; i++){
                for(j=0; j<N; j++){
                    if( D[i][k] + D[k][j] < D[i][j]){
                        D[i][j] = D[i][k] + D[k][j];
                        if( i==j && D[i][j]<0)  return false;
                        path[i][j] = k; 
                    }
    return true;           
 }

    
  
