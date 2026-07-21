#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
   
    int n, m;
    cin>>n>>m;
    
    vector<string> a(n), b(m);
    
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    for(int i=0; i<m; i++){
        cin>>b[i];
    }
    
    bool bb=false;
    int idy=0;
    while(idy<=n-m){
        for(int i=0; i<n-m+1; i++){
            
            bb=true;
            for(int my=0; my<m; my++){
                for(int mx=0; mx<m; mx++){
                    if(b[my][mx]!=a[idy+my][i+mx]){
                        bb=false;
                    }
                }
            }
            
            if(bb){
                break;
            }
        }
        if(bb){
                break;
            }
        idy++;
    }
    
    if(bb){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    
}
