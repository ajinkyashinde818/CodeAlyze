#include <stdio.h>

int main(){
    int n, cnt, ans;
    int S[101], T[101];

    ans = 0;
    cnt = 0;

    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        scanf("%d %d",&S[i],&T[i]);
        if(S[i] == T[i]) cnt++;
        else cnt = 0;
        if(cnt > 2) ans++;
    }
    if(ans > 0) printf("Yes");
    else printf("No");
    return 0;
}
