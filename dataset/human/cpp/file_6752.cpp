#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;
typedef pair<P, int> PP;

int a[200005], b[200005];
vector<int> c[200005], d[200005];
PP p[200005];
int ans[200005];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
        c[a[i]].push_back(i);
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        b[i]--;
        d[b[i]].push_back(i);
    }
    for(int i = 0; i < n; i++){
        if((int)c[i].size() + (int)d[i].size() > n){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    for(int i = 0; i < n; i++){
        p[i] = PP(P((int)c[i].size(), (int)d[i].size()), i);
    }
    sort(p, p + n, greater<PP>());
    queue<P> que;
    int j = 0;
    int i;
    for(i = 0; i < n; i++){
        if(i == j){
            que.push(P(p[j].first.first, p[j].second));
            j++;
        }
        int u = p[i].second;
        while(d[u].size() && j < n){
            int v = p[j].second;
            while(c[v].size() == 0 && j < n){
                j++;
                v = p[j].second;
            }
            if(j == n) break;
            ans[c[v].back()] = d[u].back();
            d[u].pop_back();
            p[i].first.second--;
            c[v].pop_back();
            p[j].first.first--;
        }
        if(j == n) break;
    }
    for(; i < n; i++){
        if(que.empty()) break;
        int u = p[i].second;
        P q = que.front();
        que.pop();
        int v = q.second;
        while((int)d[u].size() >= q.first){
            for(int t = 0; t < q.first; t++){
                ans[c[v].back()] = d[u].back();
                d[u].pop_back();
                c[v].pop_back();
            }
            if(que.empty()) break;
            q = que.front();
            que.pop();
            v = q.second;
        }
        while(d[u].size()){
            ans[c[v].back()] = d[u].back();
            d[u].pop_back();
            c[v].pop_back();
        }
        que.push(P((int)c[v].size(), v));
    }
    for(int i = 0; i < n; i++) cout << b[ans[i]] + 1 << " ";
    cout << endl;
}
