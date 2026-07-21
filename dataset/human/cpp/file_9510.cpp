#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char> > a(n, vector<char>(n)), b(m, vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            cin >> b[i][j];
        }
    }
    bool ans = false;
    for(int k=0; k<=n-m; k++){
        for(int l=0; l<=n-m; l++){
            int same = true;
            for(int i=0; i<m; i++){
                for(int j=0; j<m; j++){
                    if(a[i+k][j+l] != b[i][j]){
                        same = false;
                        i = n;
                        break;
                    }
                }
            }
            if(same){
                ans = true;
                k = n;
                break;
            }
        }
    }
    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }   
    return 0;
}
