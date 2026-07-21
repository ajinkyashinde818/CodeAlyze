// Template Matching
#include <iostream>
using namespace std;

int n,m;
char a[50][50],b[50][50];

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++) cin>>a[i][j];
    for(int i=0;i<m;i++)for(int j=0;j<m;j++) cin>>b[i][j];
    for(int x=0;x<=n-m;x++){
        for(int y=0;y<=n-m;y++){
            bool ok=true;
            for(int i=0;i<m;i++){
                for(int j=0;j<m;j++){
                    if(a[x+i][y+j]!=b[i][j]){
                        ok=false;
                        i=m;
                        break;
                    }
                }
            }
            if(ok){
                cout<<"Yes\n";
                return 0;
            }
        }
    }
    cout<<"No\n";
    return 0;
}
