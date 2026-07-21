#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n; cin >> n >> m;
    vector<string> a(n), b(m);
    for (int i=0; i<n; i++){
        cin >> a.at(i);
    }
    for (int i=0; i<m; i++){
        cin >> b.at(i);
    }
    for (int i=0; i<n-m+1; i++){//1行ずつiで回す
        for (int j=0; j<n-m+1; j++){//1文字ずつjで回す
            if (a.at(i).at(j)==b.at(0).at(0)){//画像Bの左上の画素に一致する画素が見つかったら
                bool judge=true;
                for (int k=0; k<m; k++){//そこからm行のstringを比較
                    if (a.at(i+k).substr(j, m)!=b.at(k)){
                        judge=false;
                        break;
                    }
                }
                if (judge){
                        cout << "Yes" << endl;
                        return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
