#include<stdio.h>
int main(){
    int a, b, k;
    scanf("%d%d%d",&a,&b,&k);
    int c[100];
    int index = 0;
    for(int i = 1; ; i++){
        if(a % i == 0 && b % i == 0){
            c[index] = i;
            index ++;
        }
        if(a < i || b < i){
            break;
        }
    }
    printf("%d\n",c[index - k]);
    return 0;
}
