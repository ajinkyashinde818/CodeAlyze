#include <stdio.h>
int main(){
    int m,n,i,j,Ai,Aj,ok;
    char a[51][51],b[51][51];
    scanf("%d %d",&n,&m);
    for(i=0; i<n; i++){
        scanf("%s",&a[i]);
    }
    for(i=0; i<m; i++){
        scanf("%s",&b[i]);
    }
    for(int Ai=0; Ai<n-m+1; Ai++){
        for(Aj=0; Aj<n-m+1; Aj++){
            ok=1;
            for(i=0; i<m; i++){
                for(j=0; j<m; j++){
                    if(a[Ai+i][Aj+j]!=b[i][j]){
                        ok=0;
                    }
                }
            }
            if(ok==1){
                printf("Yes");
                return 0;
            }
        }
    }
    printf("No");
}
