#include <stdio.h>
int min(int n,int m){
    if(n<m) return n;
    else return m;
}
int main(void){
    int a,b,k,i,cnt=0;
    scanf("%d%d%d",&a,&b,&k);
    int ans = min(a,b);
    for(i=min(a,b);i>0;i--){
        if(k==cnt) break;
        if(a%i==0 && b%i==0){
            cnt++;
            ans = i;
        }
    }
    printf("%d",ans);

}
