#include <stdio.h>

int main() {
    int A,B,K,I;
    int ans[100];
    int ansnum = 0;
    scanf("%d%d%d",&A,&B,&K);
    if (A<B) {
        I = A;
    }else if(A>B){
        I = B;
    }else if(A==B){
        I = A;
    }
    
    for (int r = 1; I>=r; r++) {
        if((A%r== 0) && (B%r== 0)){
            ans[ansnum] = r;
           ansnum++;
        }
    }
    
    printf("%d",ans[ansnum-K]);
    return 0;
}
