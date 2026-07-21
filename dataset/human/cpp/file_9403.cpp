#include <iostream>
using namespace std;
const int MAX=50;
int main(){
    int n,m;
    cin>>n>>m;
    string a[MAX],b[MAX];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    bool flag;
    for(int i=0;i<n-m+1;i++){
        for(int j=0;j<n-m+1;j++){
            flag=true;
            for(int ii=0;ii<m;ii++){
                for(int jj=0;jj<m;jj++){
                    if(b[ii][jj]!=a[i+ii][j+jj]){
                        flag=false;
                    }
                }
            }
            if(flag){
                cout<<"Yes";
                return 0;
            }
        }
    }
    cout<<"No";
    return 0;
}
