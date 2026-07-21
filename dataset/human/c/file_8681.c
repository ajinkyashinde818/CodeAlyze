#include <stdio.h>
#define N 100000
int main(void){
    int n;
    int i=0,cnt=0;
    int a[N];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    i=0;
    while(a[i]!=2){
        if(cnt==n)break;
        i=a[i]-1;
        cnt++;
    }
        if(a[i]==2)printf("%d\n",cnt+1);
    else printf("-1\n");
    return 0;
}
