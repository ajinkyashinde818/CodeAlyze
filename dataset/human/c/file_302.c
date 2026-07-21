#include <stdio.h>

int main(void){
    int n;
    int a[100001];
    int i,flag;
    long long int tmp; 
    
    long long int memo1[100001] = {0};
    long long int memo2[100001] = {-2000000000};
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    
    for(i = 1; i <= n; i++){
        if(memo1[i-1] + a[i] > memo2[i-1] - a[i]){
            memo1[i] = memo1[i-1] + a[i];
        }else{
            memo1[i] = memo2[i-1] - a[i];
        }
        
        if(memo1[i-1] - a[i] > memo2[i-1] + a[i]){
            memo2[i] = memo1[i-1] - a[i];
        }else{
            memo2[i] = memo2[i-1] + a[i];
        }
    }
    
    printf("%lld\n", memo1[n]);
    
    return 0;
}
