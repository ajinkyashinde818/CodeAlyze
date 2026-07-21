#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<string>
#include<math.h>
 
using namespace std;
 
int main(){
    bool ans=false;
    bool check=true;
    int n,m,k;
    string a[51],b[51];
    cin>>n>>m;
    k=n-m+1;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    for(int y=0;y<k;y++){
        for(int x=0;x<k;x++){
            check=true;
            for(int yy=0;yy<m;yy++){
                for(int xx=0;xx<m;xx++){
                    if(a[y+yy][x+xx]!=b[yy][xx])check=false;
                }
            }
            if(check)ans=true;
        }
    }
    if(ans)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
 
}
