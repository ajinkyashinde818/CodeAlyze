#include<bits/stdc++.h>
using namespace std;
int a,b,c,n;
int main() {
    scanf("%d%d%d%d",&a,&b,&c,&n);
    int ans=0;
    for(int i=0; a*i<=n; i++) {
        for(int j=0; a*i+b*j<=n; j++) {
            if((n-a*i-b*j)%c==0) {
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
