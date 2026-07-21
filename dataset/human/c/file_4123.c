#include <stdio.h>
int main(){
    int A, B, K;
    scanf("%d %d %d", &A, &B, &K);
    int i, tmp;
    if(A>B){
        tmp = A;
        A = B;
        B = tmp;
    }
    int n[A];
    for(i=0;i<A;i++){
        if((A%(i+1)==0)&&(B%(i+1)==0)){
            n[i] = 1;
        }
        else{
            n[i] = 0;
        }
    }
    int count=0, ans=1;
    for(i=0;i<A;i++){
        if(n[A-1-i] == 1){
            count += 1;
        }
        if(count == K){
            ans = A-i;
            break;
        }
    }
    printf("%d\n", ans);
}
