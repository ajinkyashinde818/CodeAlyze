#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> a(n,vector<char>(n));
    vector<vector<char>> b(m,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a.at(i).at(j);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>b.at(i).at(j);
        }
    }
    int x=0;
    for(int k=0;k<=n-m;k++){
        for(int l=0;l<=n-m;l++){
            x=0;
            for(int i=0;i<m;i++){
               for(int j=0;j<m;j++){
                   if(a.at(i+k).at(j+l)==b.at(i).at(j)) x++;
                }
            }
            if(x==pow(m,2)) break;
        }
        if(x==pow(m,2)) break;
    }
    if(x==pow(m,2)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
