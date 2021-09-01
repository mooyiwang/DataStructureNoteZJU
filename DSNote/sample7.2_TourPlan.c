//旅游规划问题

void Dijkstra( Vertex S )
{
    while(1){
        V = 未收录顶点中dist最小的;
        if(这样的V不存在) break;
        collected[V] = true;
        for( V 的每个邻接点 W )
            if(collected[W] == false)
                if( dist[V] + E<V, W> < dist[W] ){
                    dist[W] = dist[V] + E<V, W>;
                    path[W] = V;
                    cost[W] = cost[V] + C<V, W>;
                }
                else if(dist[V] + E<V, W> == dist[W] && 
                        cost[W] > cost[V] + C<V, W>){
                            cost[W] = cost[V] + C<V, W>; 
                            path[W] = V;   
                }                
        }
}

//推广
//求等长最短路径有多少条
count[s] = 1;
收入V后，使得V的邻接点W路变短了： count[W] = count[V];
收入V后，使得V的邻接点W路长度不变：count[W] += count[V]
//求边数最少的最短路，就是上面旅游规划中每条路的cost变为1
count[s] = 0；
收入V后，使得V的邻接点W路变短了： count[W] = count[V]+1
收入V后，使得V的邻接点W路长度不变：count[W] = count[V]+1