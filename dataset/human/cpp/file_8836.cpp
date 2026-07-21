#include <iostream>
#include <string>
using namespace std;

bool checkSame(string* a, string* b, int i, int j, int m){
    for(int k = 0; k<m; k++){
        auto sa = a[i+k];
        sa = sa.substr(j, m);
        if(sa != b[k]) return false;
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    string a[n], b[m];
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    for(int i = 0; i<m; i++){
        cin >> b[i];
    }
    for(int i = 0; i<=n-m; i++){
        for(int j = 0; j<=n-m; j++){
            if(checkSame(a, b, i, j, m)){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
