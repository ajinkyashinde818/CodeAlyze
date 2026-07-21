#include <stdio.h>
int main(void){
    int n;
    int d[200];
    int count=0,h=0,j=0;
    
    if(scanf("%d",&n)==1);
    
    for(int i=0;i<n;i++){
        if(scanf("%d %d",&d[i*2],&d[i*2+1])==2);
        if(d[i*2]==d[i*2+1]){
            count++;
            h=count;
            if(h==3){
                j=1;
            }
        }
        else{
            count=0;
        }
    }
    
    if(j)
        printf("Yes");
    else
        printf("No");
    
    return 0;
}
