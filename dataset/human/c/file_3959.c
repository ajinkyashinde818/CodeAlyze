#include<stdio.h>
int main(){
    int a,b,k;
    scanf("%d %d %d",&a,&b,&k);
    int A[a];
    int n = -1;
    for(int i = 1; i <= a; i++){
        if(a % i == 0){
            n++;
            A[n] = i;
            
        }
    }
    int i = n;
    int count = 0;
    int num = 0;
    while(1){
        if(b % A[i] == 0){
            
            num = A[i];
            count++;
        }
        i--;
        if(count == k) break;
    }
    printf("%d",num);
    return 0;
}
