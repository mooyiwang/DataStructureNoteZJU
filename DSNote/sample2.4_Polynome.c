#include<stdlib.h>
#include<stdio.h>

//2.5 多项式综合应用//
  //多项式的表示//
  typedef struct PolyNode* Polynomial;
  struct PolyNode
  {
      int coef;
      int expon;
      Polynomial Link;
  };


  
  
   //读入多项式//
    void Attach(int c, int e, Polynomial* pRear)//1.申请位置2.填数3.加在表后面4.将rear向后移//
    {
        Polynomial P;
        P = (Polynomial)malloc(sizeof(struct PolyNode));
        P->coef = c;
        P->expon = e;
        P->Link = NULL;
        (*pRear)->Link = P;
        *pRear = P; //!!必须传rear的地址来改变rear的值，此函数无返回，若只传rear的值并不能真正修改rear//
    }
    
int Compare(int a,int b)
{
    if(a > b) return 1;
    else if(a == b) return 0;
    else if(a < b) return -1;
}

    Polynomial ReadPoly()
    {
        Polynomial P,Rear,tmp;
        int c,e,N;

        scanf("%d",&N);
        P = (Polynomial)malloc(sizeof(struct PolyNode));
        P->Link = NULL;
        Rear = P;
        while (N--)
        {
            scanf("%d %d",&c,&e);
            Attach(c, e, &Rear);
        }
        tmp = P;
        P = tmp->Link;
        free(tmp);
        return P;
    }

    //多项式相加//
    Polynomial AddPoly(Polynomial P1, Polynomial P2)
    {
        int sum;
        Polynomial P,tmp,Rear;
        P = (Polynomial)malloc(sizeof(struct PolyNode));
        P->Link = NULL;
        Rear = P;
        while(P1 && P2){
            switch (Compare(P1->expon,P2->expon))
            {
            case 1:
                Attach(P1->coef,P1->expon,&Rear);
                P1 = P1->Link;
                break;
            case -1:
                Attach(P2->coef,P2->expon,&Rear);
                P2 = P2->Link;
                break;
            case 0:
                sum = P1->coef + P2->coef;
                if(sum) Attach(sum, P1->expon, &Rear);
                P1 = P1->Link;
                P2 = P2->Link;
                break;
            }
        }
        for(;P1;P1 = P1->Link) Attach(P1->coef,P1->expon,&Rear);
        for(;P2;P2 = P2->Link) Attach(P2->coef,P2->expon,&Rear);
        tmp = P;
        P = P->Link;
        free(tmp);
        return P;
    }

    //两个多项式相乘 2ways：1.乘变加 2.插入//
    //插入法//
    Polynomial Mult(Polynomial P1,Polynomial P2)
    {
        Polynomial t1,t2,P,Rear,tmp;
        int c,e;

        if(!P1 || !P2) return NULL;
        
        t1 = P1; t2 = P2;
        P = (Polynomial)malloc(sizeof(struct PolyNode));
        P->Link = NULL;
        Rear = P;
        while(t2){
            c = t1->coef * t2->coef;
            e = t1->expon + t2->expon;
            Attach(c, e, &Rear);
            t2 = t2->Link;
        }
        
        t1 = t1->Link;
        while(t1){
            t2 = P2;Rear = P;
            while(t2){
                c = t1->coef * t2->coef;
                e = t1->expon + t2->expon;
                while(Rear->Link && Rear->Link->expon > e) Rear = Rear->Link;
                
                if(Rear->Link == NULL){
                    Attach(c, e, &Rear);
                }
                else if(Rear->Link->expon == e){
                    if(Rear->Link->coef +c)
                        Rear->Link->coef += c;
                    else{
                        tmp = Rear->Link;
                        Rear->Link = tmp->Link;
                        free(tmp);
                    }
                }
                else if(Rear->Link->expon < e){
                    tmp = (Polynomial)malloc(sizeof(struct PolyNode));
                    tmp->coef = c;
                    tmp->expon = e;
                    tmp->Link = Rear->Link;
                    Rear->Link = tmp;
                    Rear = Rear->Link;
                }
                t2 = t2->Link;
            }
            t1 = t1->Link;
        }
        tmp = P;
        P = tmp->Link;
        free(tmp);
        return P;
    }
//多项式输出//
void PrintPoly(Polynomial P)
{
    int flag = 0; /*调整输出格式*/
    if(!P) {
        printf("0 0\n");
        return;
    }
    while(P){
        if(!flag) flag = 1;
        else  printf(" ");
        printf("%d %d",P->coef,P->expon);
        P = P->Link;
    }
    printf("\n");
    return;
}

int main()
{
    Polynomial P1,P2,P3,P4;
    P1 = ReadPoly();
    P2 = ReadPoly();
    P3 = Mult(P1, P2);
    PrintPoly( P3 );
    P4 = AddPoly(P1, P2);
    PrintPoly( P4 );
    return 0;
}