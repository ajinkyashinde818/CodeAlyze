#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)==2){
        int M=m*m,N=n*n;
        char a[n+3][n+3],b[m+3][m+3],A[M+3],B[N+3];
        int i,j,k,l;
        getchar();

        for(i=0,k=0;i<n;i++){
            for(j=0;j<n;j++)
                scanf("%c",&a[i][j]);
            getchar();
        }

        for(i=0,k=0;i<m;i++){
            for(j=0;j<m;j++)
                scanf("%c",&b[i][j]);
            getchar();
        }

        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i+m-1>=n || j+m-1>=n) continue;
                if(a[i][j]==b[0][0]){
                    for(k=0;k<m;k++){
                        for(l=0;l<m;l++){
                            if(a[i+k][j+l]!=b[k][l])
                                break;
                        }
                        if(l!=m) break;
                    }
                }
                if(k==m)
                    break;
            }
            if(k==m)
                break;
        }

        if(k!=m) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
