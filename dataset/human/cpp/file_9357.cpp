#include<iostream>
using namespace std;
int main()
{
    bool a[50][50], b[50][50], f = 1;
    char c;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> c;
            a[i][j] = (c == '.' ? 0 : 1);
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            cin >> c;
            b[i][j] = (c == '.' ? 0 : 1);
        }
    }
    for(int ki = 0; ki <= n - m; ki++){
        for(int kj = 0; kj <= n - m; kj++){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < m; j++){
                    if(a[ki + i][kj + j] != b[i][j]){
                        i = m;
                        j = m;
                        f = 0;
                        break;
                    }
                }
            }
            if(f == 1){
                cout << "Yes" << endl;
                return 0;
            }
            f = 1;
        }
        
    }
    cout << "No" << endl;
    return 0;
}
