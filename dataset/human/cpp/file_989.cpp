#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;

int main(){
    int R ,G ,B , n;
    long long ans = 0;
    scanf("%d%d%d%d",&R,&G,&B,&n);
    for(int i = 0; R * i  <= n; i++){
        for(int j = 0; R * i + j * G <= n; j++){
            if((n - (R * i + j * G) ) % B == 0) ans++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
