#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<string.h>
#include<queue>
#include<math.h>
#include<set>
#include<unordered_set>
#include<limits.h>
using namespace std;

typedef unsigned long long ll;







int main(){
    int n,m;
    vector<string>v1,v2;
    cin>>n>>m;
    v1.resize(n);
    string st;
    for(int i=0;i<n;i++){
        cin>>st;
        v1[i]=st;
    }
    
    for(int i=0;i<m;i++){
        cin>>st;
        v2.push_back(st);
    }
    for(int i=0;i+m<=n;i++){
        for(int j=0;j+m<=n;j++){
            bool ok=true;
            for(int k=0;k<m;k++){
                for(int l=0;l<m;l++){
                    if(v1[i+k][j+l]!=v2[k][l]){
                        ok=false;
                        break;
                    }
                }
            }
            if(ok){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}
