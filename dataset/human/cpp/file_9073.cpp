#include <iostream>
#include <string>
using namespace std;
int main(void){
    int n,m;
    cin>>n>>m;
    string a[50],b[50],ans="No";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    for(int i=0;i<n-m+1;i++){
        for(int j=0;j<n-m+1;j++){
            bool f=true;
            for(int k=0;k<m;k++){
                if(a[k+i].substr(j,m)!=b[k]){
                    f=false;
                }
            }
            if(f){
                ans="Yes";
                i=50;
                j=50;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
