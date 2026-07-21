#include<stdio.h>
int main(){
    int i;
    int x;
    int a[10000];
    int cnt=0;
    for(i=0;i<10000;i++){
        scanf("%d",&a[i]);
        if(a[i]==0)break;
        cnt++;
    }
    for(i=0;i<cnt;i++){
        printf("Case %d: %d\n",i+1,a[i]);
    }
    return 0;
}
