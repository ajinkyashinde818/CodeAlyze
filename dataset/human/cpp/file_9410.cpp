#include <iostream>
using namespace std;

int main(void){
    int n,m;
    cin>>n>>m;
    string a[n],b[m];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    
    for(int j=0;j+m-1<n;j++){
        for(int i=0;i+m-1<n;i++){
            for(int k=0;k<m;k++){
                if(a[i+k].substr(j,m)!=b[k]) break;
                if(k==m-1){
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"No"<<endl;
}
