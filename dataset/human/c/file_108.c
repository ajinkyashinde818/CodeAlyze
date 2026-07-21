#include <stdio.h>
int min(int,int);

int main(){
    int r,g;
    int R,G,B,N;
    int count=0;
    scanf("%d",&R);
    scanf("%d",&G);
    scanf("%d",&B);
    scanf("%d",&N);

    for(r=0;r*R<=N;r++){
        for(g=0;g*G<=N-r*R;g++){
            if((N-r*R-g*G)%B==0){
                count++;
            }
        }
    }
    printf("%d",count);
    return 0;
}

int min(int a,int b){
    int m;
    if(a>b){
        m=b;
    }else{
        m=a;
    }
    return b;
}
