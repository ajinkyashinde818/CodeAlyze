#include <stdio.h>
int main(void){
    // Your code here!
    int K,S;
    int x,y,z;
    int cnt = 0;
    int sum;
    
    scanf("%d%d",&K,&S);
    
    for(x = 0;x<=K;x++){
        sum = S - x;
        for(y=0;y<=K;y++){
            z = sum - y;
            if(z <= K && z >= 0){
                cnt++;
            }
        }
    }
    
    printf("%d\n",cnt);
}
