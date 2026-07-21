#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int a[100000];
int b[100000];
int c[200000];
int par[200000];

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    
    if (x == y) return;
    
    par[x] = y;
}

int main() {
    int n, suma = 0, sumb = 0, ans = 0, i;
    vector <int> v, w;
    map <int, int> mp;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
        v.push_back(a[i]);
        suma ^= a[i];
    }
    
    v.push_back(suma);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        
        w.push_back(b[i]);
        sumb ^= b[i];
    }
    
    w.push_back(sumb);
    
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    
    for (i = 0; i < v.size(); i++) {
        if (v[i] != w[i]) {
            puts("-1");
            
            return 0;
        }
    }
    
    for (i = 0; i < n; i++) {
        if (a[i] != b[i]) break;
    }
    
    if (i == n) {
        puts("0");
        
        return 0;
    }
    
    for (i = 0; i < n * 2; i++) par[i] = i;
    
    for (i = 0; i < n; i++) {
        int x, y;
        
        if (a[i] == b[i]) continue;
        
        if (mp.count(a[i])) {
            x = mp[a[i]];
        } else {
            x = mp.size();
            mp[a[i]] = x;
        }
        
        if (mp.count(b[i])) {
            y = mp[b[i]];
        } else {
            y = mp.size();
            mp[b[i]] = y;
        }
        
        unite(x, y);
    }
    
    for (i = 0; i < n * 2; i++) c[find(i)]++;
    
    for (i = 0; i < n; i++) {
        if (a[i] != b[i]) ans++;
    }
    
    for (i = 0; i < n * 2; i++) {
        if (c[i] > 1) ans++;
    }
    
    if (mp.count(suma) && c[find(mp[suma])] > 1) ans--;
    
    printf("%d\n", ans);
    
    return 0;
}
