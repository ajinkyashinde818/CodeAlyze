#include<stdio.h>
int main(void){
    int num;
    int limit;
    int height[100001];
    int ans=0;

    scanf("%d %d\n",&num,&limit);

    for(int i=0;i<num;i++){
        scanf("%d",&height[i]);
    }

    for(int j=0;j<num;j++){
        if(height[j]>=limit)ans++;
    }
    printf("%d",ans);

    return 0;    
}
