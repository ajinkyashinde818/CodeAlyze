#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    vector<string> a(n);
    vector<string> b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i+m-1>=n||j+m-1>=n) continue;
            bool c=true;
            for(int k=0;k<m;k++){
                for(int l=0;l<m;l++){
                    if(a[i+k][j+l]!=b[k][l]) c=false;
                }
            }
            if(c){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
}
