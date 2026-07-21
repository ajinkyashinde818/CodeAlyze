#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<string> hoge(n);
    vector<string> sample(m);
    
    for(int i=0;i<n;i++) cin>>hoge.at(i);
    for(int i=0;i<m;i++) cin>>sample.at(i);
    
    string ans="No";
    
    for(int i=0;i<n-m+1;i++){
        for(int j=0;j<n-m+1;j++){
            bool ok=true;
            for(int k=i;k<i+m;k++){
                for(int l=j;l<j+m;l++){
                    if(hoge.at(k).at(l)!=sample.at(k-i).at(l-j)){
                        ok=false;
                        break;
                    }
                    if(!ok) break;
                }
            }
            if(ok){
                ans="Yes";
                break;
            }
        }
        if(ans=="Yes") break;
    }
    
    cout<<ans<<endl;
    
    return 0;
}
