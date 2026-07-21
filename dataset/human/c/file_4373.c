#include <stdio.h>
int main(){
    int n, d1, d2, cnt=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d%d", &d1, &d2);
        if( d1==d2 ){ cnt++; }
        else        { cnt=0; }
        if( cnt==3 ){ printf("Yes\n"); return 0; } 
    }
    printf("No\n");
    return 0;
}
