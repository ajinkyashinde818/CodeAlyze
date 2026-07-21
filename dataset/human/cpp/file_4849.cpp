#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, r;
    cin >> n >> r;
    if(n >= 10){
        cout << r << endl;
    }else{
        cout << r + 100*(10 - n) << endl;
    }

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}
