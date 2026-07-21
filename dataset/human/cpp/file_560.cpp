#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{   
    ll R, G, B, N;
    cin >> R >> G >> B >> N;

    ll res=0;
    for(int i=0;i*R<=N;i++){
        for(int j=0;i*R+j*G<=N;j++){
            if( (N-R*i-G*j)%B ==0 ) res++;
        }
    }
    cout<<res<<endl;

    return 0;
}
