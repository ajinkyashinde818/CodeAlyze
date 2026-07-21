#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
const int MAX = 200000;
long long Value[MAX]{0};
long long a[MAX]{0};
int main()
{
    long long n{0};
    while(scanf("%lld", &n)!= EOF && n){
        memset(a,0,sizeof(a));
        long long x{0}, y{0};
        for (int i=0; i < n; i++){
            scanf("%lld", &a[i]);
            y+=a[i];
        }
        y-=a[0];
        x=a[0];
        Value[0] = abs(x-y);
        for (int k=1; k <n-1; k++){
            x+=a[k];
            y-=a[k];
            Value[k] =(long long) abs(x-y);
        }
        sort(Value,Value+n-1);
        printf("%lld\n",Value[0]>0? Value[0]:Value[0]*-1);
    }
    return 0;
}
