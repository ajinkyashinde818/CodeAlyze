#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    int a[20+5];
    int b[20+5];
    int c[20+5];
    int score=0;

    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    for(int i=1; i<=n; i++){
        scanf("%d", &b[i]);
    }
    for(int i=1; i<n; i++){
        scanf("%d", &c[i]);
    }

    for(int i=1; i<=n; i++){
        score+=b[a[i]];
        // printf("%d\n", score);
        if(a[i]-a[i-1]==1){
            score+=c[a[i-1]];
            // printf("%d %d\n", i, score);
        }
    }

    printf("%d\n", score);
    return 0;
}
