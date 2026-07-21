/*
 * FileName:     D
 * CreatedDate:  2020-05-31 22:04:17 +0900
 * LastModified: 2020-06-28 10:14:50 +0900
 */

#include <stdio.h>

int main(void){
    long long int n;scanf("%lld",&n);
    int ans=0;
    for(long long int i=2;i*i<=n;i++){
        if(n%i==0){
            int cnt = 0;
            while(n%i==0){
                n/=i;
                cnt++;
            }
            for(int j=1;j<=cnt;j++){
                cnt -= j;
                ans++;
            }
        }
    }
    if(n!=1)ans++;
    printf("%d\n",ans);
    return 0;
}
