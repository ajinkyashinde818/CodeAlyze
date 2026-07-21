#include<stdio.h>
int main(){
    int n;
    int k;
    scanf("%d %d", &n, &k);
    int h[n];
    int count = 0;
    for(int i = 0;i < n;i++){
        scanf("%d",&h[i]);
    }
    for(int i = 0;i<n;i++){
        if(h[i] >= k){
            count++;
        } 
    }
    printf("%d",count);
    return 0;
}
