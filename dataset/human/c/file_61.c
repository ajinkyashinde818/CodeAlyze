#include <stdio.h>

int main(void){
    int r,g,b,n,cnt=0;
    scanf("%d%d%d%d",&r,&g,&b,&n);
    int i=n/r+1,j=n/g+1;
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            if((n-r*i-g*j)==0||((n-r*i-g*j)>0&&(n-r*i-g*j)%b==0)){
                //printf("%d %d \n",i,j);
                cnt++;
            } 
        }
    }
    printf("%d\n",cnt);
    return 0;
}
