#include<stdio.h>

int main(){
    int k,s,i,j,z,count=0;

    scanf("%d %d",&k,&s);

    for(i=0;i<=k;i++){
        for(j=0;j<=k;j++){
            z = s - i - j; 
                if(z>=0 && z<=k){
                    count++;
            }
        }
    }
    printf("%d",count);
    return 0;
}
