#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    string ans="No";
    cin >> n>>m;
    bool a[n+1][n+1],b[m+1][m+1];
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        // cerr << str<< endl;
        for(int j =0;j<n;j++){
            if(str[j]=='#'){
                a[i][j] = true;
            }
            else{
                a[i][j] = false;
            }
        }
    }
    for(int i=0;i<m;i++){
        string str;
        cin >> str;
        for(int j =0;j<m;j++){
            if(str[j]=='#'){
                b[i][j] = true;
            }
            else{
                b[i][j] = false;
            }
        }
    }
    bool flag = true;
    bool finish = false;
    //i,jは左上の座標
    for(int i =0;i<n-m+1;i++){
        for(int j =0;j<n-m+1;j++){
            flag = true;
            for(int k=0;k<m;k++){
                for(int l =0;l<m;l++){
                    if(a[i+k][j+l]!=b[k][l]){
                        flag = false;
                        break;
                    }
                    if(k == m-1 && l== m-1){
                        finish = true;
                        ans = "Yes";
                    }
                }
                if(!flag){
                    break;
                }
                if(finish){
                    break;
                }
            }
            if(finish){
                break;
            }
        }
        if(finish){
            break;
        }
    }
    cout << ans<<endl;
}
