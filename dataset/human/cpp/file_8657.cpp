#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <functional>
#include <utility>
#include <queue>
#include <vector>
using namespace std;
typedef long long int ll;
const int MOD = 1000000007;

bool hantei(int n, int m, string* a, string* b){
    bool ret = false;
    bool tmp;
    // cout << n << m << endl;
    //始点のループ
    for(int i=0; i <= n - m; i++){
        for(int j=0; j <= n - m; j++){
            //比較のループ
            tmp = true;
            for(int k = 0 ; k < m; k++){
                for(int l = 0; l < m; l++){
                    // cout << a[i+k][j+l] << b[k][l] << endl;
                    if(a[i+k][j+l] != b[k][l]){
                        tmp = false;
                    }
                }
            }
        if(tmp) ret = true;
        }
    }   
    return ret;
}


int main(){
    int n, m;
    bool ans;
    cin >> n >> m;
    string a[n], b[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i < m; i++){
        cin >> b[i];
    }
    ans = hantei(n, m, a, b);
    if(ans){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}
