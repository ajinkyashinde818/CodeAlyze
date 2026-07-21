#include<bits/stdc++.h>
using namespace std;
inline int_fast64_t read(){int_fast64_t x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
inline string read_s(){string s="";char c=getchar();while(c<'!'||c>'~'){c=getchar();}while(c>='!'&&c<='~'){s+=c;c=getchar();}return s;}
void Main(){
    int N = read(), mina, negac = 0;
    int_fast64_t ans = 0;
    vector<int> A(N);
    for (int i = 0; i<N; i++) A[i] = read();
    mina = abs(A[0]);
    for (int i = 0; i<N; i++) {
        mina = min(mina, abs(A[i]));
        ans += abs(A[i]);
        if (A[i] < 0) negac++;
    }
    if (negac%2 != 0) ans -= 2*mina;
    printf("%lld\n", ans);
}
int main(){cin.tie(nullptr);ios::sync_with_stdio(false);Main();return 0;}
