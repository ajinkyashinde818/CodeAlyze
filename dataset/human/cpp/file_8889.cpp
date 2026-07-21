#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n , m , same;
    char a[50][50] , b[50][50];
    bool f = false;
    
    cin >> n >> m;
    for(int i=0 ;i<n ;i++ ){
        cin >> a[i];
    }
    for(int i=0 ;i<m ;i++ ){
        cin >> b[i];
    }
    
    for(int i=0 ;i<n-m+1 ;i++ ){
        for(int j=0 ;j<n-m+1 ;j++ ){
            same = 0;
            for(int k=i ;k<i+m ;k++ ){
                for(int l=j ;l<j+m ;l++ ){
                    if(a[k][l] == b[k-i][l-j]){
                        same++;
                    }
                }
            }
            if(same == m*m){
                f = true;
            }
        }
    }
    
    if(f){
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    
    return(0);
}
