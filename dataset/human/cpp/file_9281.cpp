#include <iostream>
using namespace std;

char a[51][51];
char b[51][51];

int main(void){
    
    int n,m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            cin >> b[i][j];
        }
    }
    
    for(int i = 0; i < n-m+1; i++){
        for(int j = 0; j < n-m+1; j++){
            bool f = true;
            for(int k = 0; k < m; k++){
                for(int l = 0; l < m; l++){
                    if(a[i+k][j+l] != b[k][l]) f = false;
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
