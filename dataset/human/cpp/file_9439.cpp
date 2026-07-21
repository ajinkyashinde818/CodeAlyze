#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,m;
    cin>>n>>m;
    vector<string> s,t;
    for(int i=0;i<n;i++){
    string ss;
    cin>>ss;
    s.push_back(ss);
    }
    for(int i=0;i<m;i++){
        string ss;
        cin>>ss;
        t.push_back(ss);
    }
    for(int i=0;i<n-m+1;i++){
        for(int j=0;j<n-m+1;j++){
            bool ok=true;
            for(int k=0;k<m;k++){
                for(int kk=0;kk<m;kk++){
                    if(s[i+k][j+kk]!=t[k][kk]){ok=false;break;}
                }
            }
            if(ok){cout<<"Yes"<<endl;return 0;}
        }
    }
    cout<<"No"<<endl;
}
