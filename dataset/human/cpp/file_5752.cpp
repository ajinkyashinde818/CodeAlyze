#include <bits/stdc++.h>

using namespace std;

int n,tree[100005][2], ptr = 1;
long long int height[100005], l, gr = 0;

void addStr(string &s){
    int t = 0;
    for(size_t i = 0; i < s.size(); i++){
        if(tree[t][s[i] - '0'] != -1){
            t = tree[t][s[i] - '0'];
        }else{
            tree[t][s[i] - '0'] = ptr;
            height[ptr] = height[t] - 1;
            t = ptr++;
        }
    }
}

long long int findMax2(long long int s){
    if(s == 0)return 0;
    long long int ans = 1;
    while(s%2 == 0){
        s /= 2;
        ans *= 2;
    }
    return ans;
}

void processTrie(){
    for(int i = 0; i < ptr; i++){
        if(tree[i][0] == -1){
            gr ^= findMax2(height[i] - 1);
        }
        if(tree[i][1] == -1){
            gr ^= findMax2(height[i] - 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>l;
    string s;
    memset(tree, -1, sizeof(tree));
    height[0] = l+1;
    for(int i = 0; i < n; i++){
        cin>>s;
        addStr(s);
    }
    processTrie();
    if(gr == 0){
        cout<<"Bob"<<endl;
    }else{
        cout<<"Alice"<<endl;
    }
}
