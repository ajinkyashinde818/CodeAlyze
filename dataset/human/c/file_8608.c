#include"stdio.h"
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int f[n];
    for(int i=0;i<n;i++) f[i]=0;
    int cnt=1,k=a[0];
    f[0]=1;
    while(1){
        if(k==2)  break;
        k=a[k-1];
        f[k-1]++;
        if(f[k-1]==2){
            printf("-1\n");
            return 0;
        }
        cnt++;
    }
    printf("%d\n",cnt);
}
