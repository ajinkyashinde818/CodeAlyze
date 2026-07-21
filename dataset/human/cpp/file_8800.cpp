#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for(int i = 0; i < n; ++i){
        cin >> a.at(i);
    }
    for(int i = 0; i < m; ++i){
        cin >> b.at(i);
    }

    for(int di = 0; di + m <= n; ++di){
        for(int dj = 0; dj + m <= n; ++dj){
            bool flag = true;
            for(int i = 0; i < m; ++i){
                if(b.at(i) != a.at(di + i).substr(dj, m)){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
