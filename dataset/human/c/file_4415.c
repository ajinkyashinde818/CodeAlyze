#include<stdio.h>

int main(){
        int n, i, j;
        scanf("%d", &n);
        int d[n][2];
        for(i=0; i<n; i++){
                for(j=0; j<2; j++){
                        scanf("%d", &d[i][j]);
                }
        }
        int count=0;
        for(i=1; i<n-1; i++){
                if((d[i-1][0]==d[i-1][1])&&(d[i][0]==d[i][1])&&(d[i+1][0]==d[i+1][1])){
                        printf("Yes");
                        return 0;
                }
        }
        printf("No");
        return 0;
}
