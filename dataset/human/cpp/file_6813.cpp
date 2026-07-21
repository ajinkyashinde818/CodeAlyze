#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>v, v2, vis(n, 0);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v2.push_back(x);
    }
    reverse(v2.begin(), v2.end());
    int j = 0;
    vector<int>cur;
    for(int i = 0; i < n; i++){
        while(j < n && v2[j] == v[i]){
            j++;
        }
        if(j < n){
            cur.push_back(v2[j]);
            vis[j] = 1;
            j++;
        }
    }
    for(int i = 0; i < n; i++){
        if(vis[i] == 0){
            cur.push_back(v2[i]);
        }
    }
    int y = 1;
    for(int i = 0; i < n; i++){
        if(v[i] == cur[i]){
            y = 0;
        }
    }
    if(y == 1){
        cout << "Yes\n";
        for(int i = 0; i < n; i++){
            cout << cur[i] << ' ';
        }
        return 0;
    }
    reverse(v2.begin(), v2.end());
    multiset<int>st;
    for(int i = 0; i < n; i++){
        st.insert(v2[i]);
    }
    int k = 1;
    vector<int>ans;
    for(int i = 0; i < n; i++){
        multiset<int>::iterator it = st.upper_bound(v[i]);
        if(it == st.end()){
            it = st.begin();
        }
        ans.push_back(*it);
        st.erase(it);
    }
    for(int i = 0; i < n; i++){
        if(ans[i] == v[i]){
            k = 0;
        }
    }
    if(k == 0){
        cout << "No";
    }
    else{
        cout << "Yes\n";
        for(int i = 0; i < n; i++){
            cout << ans[i] << ' ';
        }
    }
    return 0;
}
