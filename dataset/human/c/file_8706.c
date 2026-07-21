#include <stdio.h>
int b[100001];
int main(void){
    long N,i,cnt=0;
    scanf("%ld",&N);
    int a[N];
    for(i=0;i<N;i++) scanf("%d",&a[i]);
    i=0;
    while(1){
        if(i==1){
            printf("%ld\n",cnt);
            return 0;
        }
        if(b[a[i]-1]==1){
            printf("-1");
            return 0;
        }
        else{
            b[a[i]-1]++;
            cnt++;
            i=a[i]-1;
        }
    }
}
