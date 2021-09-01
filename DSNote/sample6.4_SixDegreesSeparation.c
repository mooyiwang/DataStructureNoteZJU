

 void SDS()
 {
     for( each V in G){
         count = BFS(V);
         Output(count/N);
     }
 }
 
 int BFS(Vertex V)
 {
     visited[V] = true; 
     cnt = 1;
     level = 0; last = V;
     Enqueue(V, Q);
     while(!IsEmpty(Q)){
         V = Dequeue(Q);
         for( V的每个邻接点W ){
             if(!visited[W]) {
                 visited[W] = true;
                 Enqueue(W, Q);
                 cnt++;
                 tail = W;
             }
         }
        if (V == last){
            level++; last = tail;
        }
        if(level == 6) break;
     }
     return cnt;
 }
