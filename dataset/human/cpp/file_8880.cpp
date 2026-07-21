#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, m;
int A[50][50];
int B[50][50];

int can(){
    bool b;
    for(int i = 0; i <= n - m; i++){
        for(int j = 0; j <= n-m; j++){
            b = true;
            for(int k = 0; k< m; k++){
                for(int l = 0; l<m ;l++) {
                     if(A[i + k][j + l] != B[k][l]) b = false;
                }    
            }
            if(b) return 1;
        }
    } 
    return 0;
}

int main()
{
    cin>>n>>m;
    for(int i = 0; i< n; i++){
        for(int j = 0; j<n ;j++) {
            char x;cin >> x;
            A[i][j] = (x=='#'?1:0);
            
        }
    }
    for(int i = 0; i< m; i++){
        for(int j = 0; j<m ;j++) {
            char x;cin >> x;
            B[i][j] = (x=='#'?1:0);
        }
    }
    cout << (can()? "Yes":"No") << endl;
    return 0;
}
