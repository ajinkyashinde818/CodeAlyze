#include <iostream>
#include <string>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    char a[60][60],b[60][60];
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<m;++i){
        for(int j=0;j<m;++j){
            cin>>b[i][j];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            int cnt=0;
            for(int k=0;k<m;++k){
                for(int l=0;l<m;++l){
                    if(a[i+k][j+l]==b[k][l]){
                        ++cnt;
                    }
                }
            }
            if(cnt==m*m){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
}
