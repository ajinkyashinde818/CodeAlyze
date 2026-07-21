#include <stdio.h>
int main()
{   int n,a[100001];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }int cnt=0,i=0;
    while (cnt<=n){
        if(a[i]==2){
            printf("%d",cnt+1);
            return 0;
        }
        else i=a[i]-1;
        cnt++;
    }
    printf("-1");
    return 0;
}
