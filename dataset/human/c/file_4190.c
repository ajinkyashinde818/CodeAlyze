#include<stdio.h>

int max1(int a, int b) { return a > b ? a : b; }

int main(){
    int a,b,k,counter=0;
    int ans[1000]={0};
    scanf("%d %d %d",&a,&b,&k);
    for(int i=1;i<=max1(a,b);i++){
        if(a%i==0&&b%i==0){
            ans[counter++] = i;
        }
    }
    printf("%d\n",ans[counter-k]);
    return 0;
}
