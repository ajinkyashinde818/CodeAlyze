#include<stdio.h>
int main(){
    int n,d,x,a[100],ans=0;
    scanf("%d%d%d",&n,&d,&x);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j+=a[i]){
            ans++;
        }
    }
    printf("%d\n",ans+=x);
    return 0;
}
