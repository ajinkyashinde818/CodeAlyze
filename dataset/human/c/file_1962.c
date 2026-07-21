#include <stdio.h>
int main(void){
    int n,res=0;
    scanf("%d",&n);
    int a[n+1],b[n+1],c[n];
    for(int i=1;i<n+1;i++)scanf("%d",&a[i]);
    for(int i=1;i<n+1;i++)scanf("%d",&b[i]);
    for(int i=1;i<n;i++)scanf("%d",&c[i]);
    for(int i=1;i<n+1;i++){
        res+=b[i];
    }
    for(int i=1;i<n;i++){
        if(a[i+1]==a[i]+1)res+=c[a[i]];
    }
    printf("%d\n",res);
    return 0;
}
