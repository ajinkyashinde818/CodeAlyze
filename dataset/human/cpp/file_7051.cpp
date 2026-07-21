#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) cin >> b[n + 1 - i];
    //reverse(b + 1, b + n + 1);
    int ok = 0;
    for(int i = 1; i <= n; i ++){
        if(a[i] != b[i]) continue;
        int f = 0;
        for(int j = 1; j <= n; j ++){
            if(a[i] != b[j] && a[j] != b[i]){
                f = 1;
                swap(b[i], b[j]);
                break;
            }
        }
        if(!f){
            ok=1;
            break;
        }
    }
    if(ok==1){
        cout << "No" << endl;
    }else{
		cout << "Yes" << endl;
		for(int i = 1; i <= n; i ++){
			if(i != 1)cout << " ";
			cout << b[i];
		}
    	cout << endl;
	}
    return 0;
}
