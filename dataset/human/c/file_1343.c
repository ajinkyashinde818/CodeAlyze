#include<stdio.h>

int main(void){
    int n,m;
    scanf("%d%d", &n,&m);

    int one_to[n-2];
    int to_n[n-2];
    for(int i=0; i<n-2; i++){
        one_to[i] = 0;
        to_n[i] = 0;
    }

    for(int i=0; i<m; i++){
        int a,b;
        scanf("%d%d", &a, &b);

        if(a==1 && b!=n){
            one_to[b-2] = 1;
        }
        else if(a!= 1 && b==n){
            to_n[a-2] = 1;
        }
    }

    int res = 0;
    for(int i=0; i<n-2; i++){
        if(one_to[i]==1 && to_n[i]==1){
            res = 1;
        }
    }

    if(res){
        printf("POSSIBLE\n");
    }else{
        printf("IMPOSSIBLE\n");
    }

    return 0;
}
