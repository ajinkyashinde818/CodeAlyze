#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,m;
    cin >> n >> m;
    char a[256][256], b[256][256];
    
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> a[i][j];

    for(int i=0;i<m;i++) for(int j=0;j<m;j++) cin >> b[i][j];
    
    bool exist = false;
    
    for(int i2=0;i2<n;i2++){
        for(int j2=0;j2<n;j2++){
            if(i2+m-1>=n||j2+m-1>=n) continue;
            
            bool point = true;
            for(int i=0;i<m;i++){
                for(int j=0;j<m;j++){
                    if(a[i+i2][j+j2] != b[i][j]) point = false;
                }
            }
            if(point) exist = true;
        }
    }
    
    if(exist){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
}
