#include<stdio.h>
#include<stdlib.h>

//version1.0//
//之前的//
void DFS( Vertex V)
  {
      visited[V] = true;
      for( V的每个邻接点W )
        if( !visited[W] )
            DFS(W);
  }
void ListComponents( Graph G)
 {
     for( each V in G){
         if(!visited[V]){
             DFS(V); /*BFS(V);*/
         }
     }
 }


//

 void Save007( Graph G)
 {
     for( each V in G){
         if( !visited[V] && FirstJump(V)){
             answer = DFS(V);
             if(answer == yes) break;
         }
     } 
     if(answer == yes) Output("Yes");
     else Output("No");
 }
 //新的//
 int FirstJump( Vertex V)
 {
     if(Distance <= Redius) return 1;
     else return 0;
 }

int DFS( Vertex V)
  {
      visited[V] = true;
      for( V的每个邻接点W ){
        if( Jump(W) && IsLand(W)) return yes;
        if( !visited[W] && Jump(W))
           answer =  DFS(W);
      }
      return answer;
  }
//or//
void DFS( Vertex V)
  {
      visited[V] = true;
      if(IsSafe(V)) answer = yes;
      else {
        for( V的每个邻接点W ){
            if( !visited[W] && Jump(W) ){
                answer = DFS(W);
                if(answer == yes) break;
            }
        }
      }
      return answer;
}