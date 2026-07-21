#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <bitset>
#include <set>
#include <cmath>
using namespace std;

int main(){
    long long N, L;
    cin >> N >> L;
    vector<string> s(N);
    for(int i=0; i<N; i++)
        cin >> s[i];

    vector<vector<int>> v;
    v.push_back({-1, -1});

    for(int i=0; i<N; i++){
        int pos = 0;
        for(int j=0; j<s[i].size(); j++){
            int x = s[i][j] - '0';
            if(v[pos][x] == -1){
                v[pos][x] = v.size();
                v.push_back({-1, -1});
            }
            pos = v[pos][x];
        }
    }

    queue<pair<int, int>> que;
    que.push(make_pair(0, 0));
    vector<int> dep;
    while(!que.empty()){
        int s, d;
        tie(s, d) = que.front();
        que.pop();
        int cnt = 0;
        for(int i=0; i<2; i++)
            if(v[s][i] != -1){
                que.push(make_pair(v[s][i], d+1));
                cnt++;
            }
        if(cnt == 1)
            dep.push_back(d);
    }

    long long ans = 0;
    for(auto x : dep){
        long long tmp = L - x;
        tmp = tmp&(-tmp);
        ans ^= tmp;
    }
    cout << (ans!=0 ? "Alice" : "Bob") << endl;
    return 0;
}
