#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    string a[50], b[50];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    int d = n - m + 1;
    for(int i = 0; i < d; i++){
        for(int j = 0; j < d; j++){
            bool f = true;
            for(int k = 0; k < m; k++){
                for(int l = 0; l < m; l++){
                    if(b[k][l] != a[i + k][j + l]){
                        f = false;
                    }
                }
            }
            if(f){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
