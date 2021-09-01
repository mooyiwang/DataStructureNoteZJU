//有push和pop顺序，知pre和in的顺序，在由此推得post顺序
 //存在数组里的数据处理，声明全局变量，然后传入下标进行处理就行// 
void PostFromPreNIn( int PreL, int InL, int PostL, int n)
{
    if(!n) return;
    if( n == 1){
        post[PostL] = pre[PreL]; return;
    }
    root = pre[PreL];
    post[PostL+n-1] = root;
    for( i=0; i<n; i++)
        if(in[InL+i] == root) break;
    L = i; R = n-L-1;
    PostFromPreNIn( PreL+1, InL, PostL, L);
    PostFromPreNIn( PreL+L+1, InL+L+1, PostL+L, R);
}

void PostFromPreNIn( int PreL, int InL, int PostL, int n)
{
    root = pre[PreL];
    post[PostL+n-1] = root;
    for( i=0; i<n; i++)
        if(in[InL+i] == root) break;
    L = i; R = n-L-1;
    if(L) PostFromPreNIn( PreL+1, InL, PostL, L);
    else return;
    if(R) PostFromPreNIn( PreL+L+1, InL+L+1, PostL+L, R);
    else return;
}