#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool B[200001];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) B[i]=true;
    vector<int> E(m);
    for(int i=0;i<m;i++){
        cin>>E[i];
    }
    reverse(E.begin(),E.end());
    for(auto e:E){
        if(B[e]){
            cout<<e<<endl;
            B[e]=false;
        }
    }
    for(int i=1;i<=n;i++){
        if(B[i]){
            cout<<i<<endl;
        }
    }
    return 0;
}
