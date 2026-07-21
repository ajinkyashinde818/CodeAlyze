#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int R, G, B, n; cin >> R >> G >> B >> n;int cnt = 0;
    for(int i = 0; i <= 3500; i++) {
        for(int j = 0; j <= 3500; j++) {
            if(n - (i * R + j * G) < 0 || (n - (i * R + j * G)) % B)continue;
            cnt++;
        }
    
    }
    cout << cnt << endl;
}
