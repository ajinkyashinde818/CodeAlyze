#include<stdio.h>
int main(void){
    int A,B,c[100],K,i,cou,cou2,d[100],z=0;

    scanf("%d %d %d",&A,&B,&K);
    if(A>=B){
    for(i=0;i<A;i++){
        cou=0;
        if(A%(i+1)==0){
            if(B%(i+1)==0){
                cou++;
            }
        }
        if(cou==1){
            c[i]=i+1;
        }else{
            c[i]=0;
        }
    }for(i=0;i<A;i++){
    if(c[i]!=0){
        d[z]=c[i];
        z++;
    }
    }
    printf("%d",d[z-K]);

    }else{
        for(i=0;i<B;i++){
        cou=0;
        if(A%(i+1)==0){
            if(B%(i+1)==0){
                cou++;
            }
        }
        if(cou==1){
            c[i]=i+1;
        }else{
            c[i]=0;
        }
    }for(i=0;i<B;i++){
    if(c[i]!=0){
        d[z]=c[i];
        z++;
    }
    }
    printf("%d",d[z-K]);


    }
    return 0;
}
