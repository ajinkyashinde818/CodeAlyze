#include <stdio.h>

int main(){
    int K,S;
    scanf("%d %d",&K,&S);
    int i,j,k;
    int count=0;
    for( i=0;i<=K;i++){
        for(j=0;j<=i;j++){
            for(k=0;k<=j;k++){
                if (i+j+k==S){
                    if((j==k)&&(i==j)){
                        count++;
                    }else if((j!=k)&&(i!=j)){
                        count+=6;
                    }else{
                        count+=3;
                    }
                }
            }
        }
    }
    printf("%d",count);
    return 0;
}
