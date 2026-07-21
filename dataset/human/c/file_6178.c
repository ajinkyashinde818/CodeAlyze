#include<stdio.h>
#define N 1e10
int main(){
    int n, x=N, y, Ans=-N, i;
    scanf("%d", &n);
    scanf("%d",&y);

    for(i=1; i<n; i++){
        if(x > y) x = y;
        scanf("%d",&y);
        if(Ans < (y - x)) Ans = (y - x);
    }
    printf("%d\n",Ans);
    
    return 0;
}
