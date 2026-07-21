#include <bits/stdc++.h>
using namespace std;

int cov(char c){
    if(c == 'a')return 0;
    else return (c - 'a');
}

unsigned long dfs(vector<int> vec, int i){
        if(i == vec.size()-1)return vec.at(i)+1;
        else{
            unsigned long ans = (dfs(vec, i+1) * (vec.at(i) + 1)) %  1000000007;
            return ans;
        }
}

int main() {
    int N;
    string S;
    cin >> N >> S;

    vector<int> m(30);
    for(int i = 0; i < N; i++)
    {
         m.at(cov(S.at(i))) += 1;
    }
    
    unsigned long ans = dfs(m, 0);

    cout << (ans -1) %  1000000007<< endl;
    
}
