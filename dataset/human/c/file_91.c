#include <stdio.h>

int main(void){
    int r,g,b,n;
    int i,j,k;
    int sum=0;
    int count=0;

    scanf("%d",&r);
    scanf("%d",&g);
    scanf("%d",&b);
    scanf("%d",&n);
    
    for(i=0; i<=n; i++){
        if(r*i > n) break;
        for(j=0; j<=n; j++){
            //printf("%d %d, %d %d,, ",i,j,r,g);
            if(r*i + g*j > n) break;
            if((n - r*i - g*j) % b != 0) {
                continue;
            }else{
                count++;
                //printf("%d %d#\n",i,j);
            }
            
        }
    }
    printf("%d\n",count);
    return 0;
}
