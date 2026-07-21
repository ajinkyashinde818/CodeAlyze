#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int a[3];
int ans;

void cnt(int num, int left){
    if(num == 2){
        if(left%a[2]==0)ans++;
        return;
    }
    for(int i = 0; a[num]*i <= left; i++)cnt(num+1, left-a[num]*i);
}
int main(){
    int n;
    ans = 0;
    cin >> a[0] >> a[1] >> a[2] >> n;
    cnt(0, n);
    cout << ans << endl;
    return 0;
}
