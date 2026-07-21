#include <iostream>
#include <vector>
using namespace std;
bool judge(vector<vector<char>> a,vector<vector<char>> b,int k,int t,int m){
    for(int i = 0;i<m;i++){
        for(int j = 0;j<m;j++){
            if(b[i][j]!=a[i+k][j+t]) return false;
        }
    }
    return true;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> a;
    vector<vector<char>> b;
    char t;
    for(int i = 0;i<n;i++){
        a.push_back({});
        b.push_back({});
    }
    //cout << "meu" << endl;
    for(int i = 0;i<n;i++) for(int j = 0;j<n;j++){
        cin >> t;
        a[i].push_back(t);     
    } 
    for(int i = 0;i<m;i++) for(int j = 0;j<m;j++){
        cin >> t;
        b[i].push_back(t);
    }
    //cout << "meu" << endl;
    bool fl = false;
    for(int i = 0;i<n-m+1;i++) for(int j = 0;j<n-m+1;j++) if(judge(a,b,i,j,m)) fl = true;
    if(fl) cout << "Yes" << endl;
    else cout << "No" << endl;
}
