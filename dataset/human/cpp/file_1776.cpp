#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> used(n,0);
    vector<int> e(m);
    for(int i=0;i<m;i++){
        cin>>e[i];
    }
    for(int i=m-1;i>=0;i--){
        if(!used[e[i]-1]){
            cout<<e[i]<<endl;;
            used[e[i]-1]=true;
        }
    }
    for(int i=0;i<n;i++){
        if(!used[i]){
            cout<<i+1<<endl;
        }
    }
    return 0;
}
