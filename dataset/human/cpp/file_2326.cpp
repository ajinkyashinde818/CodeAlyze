#include <bits/stdc++.h>

using namespace std;

const int MAXN=1e5+4;

int main()
{
    long long int n, a[MAXN], neg=0, suma=0, mini=MAXN*MAXN, f=0;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        if(a[i] == 0) f = 1;
        if(a[i] < 0ll){
            neg++;
            a[i] = -a[i];
        }
        suma+=a[i];
        mini = min(mini, a[i]);
    }
    if(f || neg%2 == 0) cout << suma;
    else cout << suma-2*mini;
    return 0;
}
