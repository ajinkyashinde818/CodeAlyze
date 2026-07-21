#include<stdio.h>

int main(){
    int n,A[200000] = {0};
    int B[200000] = {0};

    scanf("%d",&n);

    for(int i = 1; i < n+1; i++){
        scanf("%d",&A[i]);
    }

    int ans = 0;
    int i = 1;
    B[i] = i;
    while (1)
    {
        i = A[i];
        if(B[i]){
            ans = -1;
            break;
        } 
        B[i] = 1;
        ans++;
        if(i == 2) break;
    }

    printf("%d\n",ans);
    

}
