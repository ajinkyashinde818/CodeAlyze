#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<string> a(n,""), b(m,"");
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n - m + 1; i++){
        for(int j = 0; j < n - m + 1; j++){
            bool match = true;
            for(int ii = 0; ii < m; ii++){
                for(int jj = 0; jj < m; jj++){
                    if(a[i + ii][j + jj] != b[ii][jj]){
                        match = false;
                    }
                }
            }
            if (match){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
