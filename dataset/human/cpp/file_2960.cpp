#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, i, c = 0, z = 0;
    cin >> n;
    long long t = 0, a, mini = 9999999999;
    for(i=0; i<n; i++){
        cin >> a;
        if(a == 0){
            z++;
        }
        if(a < 0){
            a *= -1;
            c++;
        }
        mini = min(a, mini);
        t += a;
    }
    if(c%2 == 1 && z == 0){
        t += -2*mini;
    }
    cout << t;
    return 0;
}
