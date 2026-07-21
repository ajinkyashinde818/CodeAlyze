#include<stdio.h>
int main(void){
    int N, c = 0, ans = 0;
    scanf("%d", &N);
    int D[N][2];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 2; j++){
            scanf("%d", &D[i][j]);
        }
        if(D[i][0] == D[i][1]) c += 1;
        else c = 0;
        if (c == 3) ans += 1;
        
    }
    if(ans > 0) printf("Yes");
    else printf("No");
    
    return 0;
}
