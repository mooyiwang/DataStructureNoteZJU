#include<stdio.h>
#include<sthlib.h> 
#define MaxSize 10 
 //将计算机编号与0->N-1一一映射(编号即下标)，这样就可以只用一个数组来存//
typedef int ElementType;//映射为非负整数//
typedef int SetName;//集合的名字即集合的下标//
typedef ElementType SetType[MaxSize];



SetName Find( SetType S, ElementType X)
{
    for( ; S[X]>=0; X=S[X]);
    return X;
}
//路径压缩//
 //空间换时间//
SetName Find( SetType S, ElementType X)
{
    if(S[X]<=0) return X;
    else return S[X] = Find( S, S[X]);//尾递归可以改成循环，编译器可以自动改成循环//
} 
    //循环//
/*
    SetName Find( SetType S, ElementType X)
{
    if(S[X]<=0) return X;
    while(S[X] >0 )
        S[X] = Find( S, S[X]);
} 
*/


//!!以下为按秩归并 //
/*
void Union( SetType S, SetName Root1, SetName Root2 )
{//默认两个不同集合的根节点//
//比树高//
    if(S[Root1] > S[Root2]){
        S[Root1] = Root2;  
    }
    else{
        if(S[Root1] == S[Root2]) S[Root1]--;
        S[Root2] = Root1;
    }
}
*/
//也可以比节点数//

void Union( SetType S, SetName Root1, SetName Root2 )
{//默认两个不同集合的根节点//
//比节点数//
    if(S[Root1] > S[Root2]){
        S[Root2] += S[Root1];
        S[Root1] = Root2;    
    }
    else{
        S[Root1] += S[Root2];
        S[Root2] = Root1;
    }
}

int mian()
{
    SetType S;
    int n;
    char in;
    scanf(" %d",&n);
    Initialization( S, n );
    do{
        scanf(" %c",&in);
        switch (in)
        {
        case 'C':
            Check_connection(S);
            break;
        case 'I':
            Input_connection(S);
            break;
        case 'S':
            Check_network( S, n );
            break;
        }
    }while( in != 'S');
    return 0;
}

void Initialization(SetType S, int n)
{
    int i;
    for(i=0; i<n; i++)
        S[i] = -1;
}
void Check_connection(SetType S)
{
    ElementType m,n;
    SetName R1,R2;
    scanf(" %d %d ",&m,&n);
    R1 = Find(S, m-1);
    R2 = Find(S, n-1);
    if( R1 == R2 ) printf("yes\n");
    else printf("no\n");
    return;
}

void Input_connection( SetType S )
{
    ElementType m,n;
    SetName R1,R2;
    scanf(" %d %d\n ",&m,&n);
    R1 = Find(S, m-1);
    R2 = Find(S, n-1);
    if( R1 != R2 ){
        Union( S, R1, R2);
        return;
    }
}

void Check_network(SetType S, int n )
{
    int cnt = 0,i;
    for(i=0; i<n; i++){
        if( S[i] < 0 ) cnt++;
    }
    if(cnt == 1)
        printf("The network is connected. \n");
    else
        printf("There are %d components.\n",cnt);
    return;
}

