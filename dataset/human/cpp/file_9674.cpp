#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<string> b(m);
    for(int i = 0; i < m; i++) cin >> b[i];

    string res = "Yes";
    for(int i = 0; i+m-1 < n; i++){
        for(int j = 0; j+m-1 < n; j++){
            res = "Yes";
            for(int k = 0; k < m; k++){
                for(int l = 0; l < m; l++){
                    if(b[k][l] != a[i+k][j+l]) res = "No";
                }
            }
            if(res == "Yes") break;
        }
        if(res == "Yes") break;
    }

    cout << res << endl;
    return 0;
}
