#include <stdio.h>

int main(void){

    int n=0,d=0,x=0;
    int i=0,j=0;
    int ans = 0;
    int s[150] = {0};
    scanf("%d",&n);
    scanf("%d %d",&d,&x);
    for(i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    for(i=0;i<n;i++){
        j=0;
        while(1){
            if(s[i]*j+1 > d){
                break;
            }
            if(s[i]*j+1 <= d){
                ans++;
            }
            j++; 
        }
    }
    printf("%d\n",ans+x);

    return 0;
}
