#include<stdio.h>

int main(void){
    int A,B,K,Ans;
    int Xa[100],Xab[100];
    int x;
    int i=0,j=0,k=0;
    scanf("%d%d%d",&A,&B,&K);
    for(x=1;x<=100;x++){
        if(A%x==0){Xa[i]=x;
            i++;
        }}
        
        for(j=0;j<=i-1;j++){
            if(B%Xa[j]==0){
                Xab[k]=Xa[j];
                k++;
            }
        }
            Ans=Xab[k-K];
            printf("%d\n",Ans);
        
        return 0;
}
