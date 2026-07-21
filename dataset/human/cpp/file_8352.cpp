#include <iostream>
using namespace std;

int main(void){
    int n, m;
    cin >> n >> m;
    
    char a[50][52], b[50][52];
    
    int i;
    for(i = 0; i < n; i++){
        cin >> a[i];
    }
    for(i = 0; i < m; i++){
        cin >> b[i];
    }
    
    bool flg;
    int j, k, l;
    for(i = 0; i < n - m + 1; i++){
        for(j = 0; j < n - m + 1; j++){
            flg = true;
            for(k = 0; k < m; k++){
                for(l = 0; l < m; l++){
                    if(a[i + k][j + l] != b[k][l]){
                        flg = false;
                        break;
                    }
                }
                if(flg == false){
                    break;
                }
            }
            if(flg == true){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    
    cout << "No" << endl;
    
    return 0;
}
