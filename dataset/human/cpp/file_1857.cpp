#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<bool> moved(n,false);
    vector<int> op(m);
    for (int i = 0; i < m; ++i) {
        cin>>op[m-1-i];
        --op[m-1-i];
    }
    vector<int> ans;
    for (int i = 0; i < m; ++i) {
        if(moved[op[i]])continue;
        moved[op[i]]=true;
        ans.push_back(op[i]);
    }
    for (int j = 0; j < n; ++j) {
        if(!moved[j])ans.push_back(j);
    }
    for (int i = 0; i < n; ++i) {
        cout<<ans[i]+1<<endl;
    }
    return 0;
}
