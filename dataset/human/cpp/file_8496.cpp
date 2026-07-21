#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main(void){
    int n, m;
    cin >> n >> m;
    
    vector<string> a(n);
    vector<string> b(m);
    
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    
    for (int i = 0; i <= n-m; i++){
        for (int j = 0; j <= n-m; j++){
            
            bool temp_check = true;
            
            for (int k = 0; k <= m-1; k++){
                for (int l = 0; l <= m-1; l++){
                    if (a[i+k][j+l] != b[k][l]){
                        temp_check = false;
                    }
                }
            }
            
            if (temp_check == true){
                 cout << "Yes" << endl;
                 return 0;
            } 
            else continue;
            
        }
    }
    cout << "No" << endl;
}
