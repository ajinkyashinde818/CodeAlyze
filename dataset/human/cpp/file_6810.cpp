/**
 *   @FileName	f.cpp
 *   @Author	kanpurin
 *   @Created	2020.09.13 22:14:43
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

int main() {
    int n;cin >> n;
    vector<int> a(n),b(n);
    vector<pair<int,int>> cnt_a(n),cnt_b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt_a[a[i]-1].first++;
        cnt_a[a[i]-1].second = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        cnt_b[b[i]-1].first++;
        cnt_b[b[i]-1].second = i;
    }
    int max_idx = -1;
    int max_cnt = -1;
    for (int i = 0; i < n; i++) {
        if (!(cnt_a[i].first > 0 && cnt_b[i].first > 0)) continue;
        if (max_cnt < cnt_b[i].first) {
            max_cnt = cnt_b[i].first;
            max_idx = i;
        }
        if (cnt_a[i].first + cnt_b[i].first > n) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    
    
    
    
    
    
    
    vector<int> end_a(n,-1);
    int t = 0;
    for (int i = 0; i < n; i++) {
        while (t < n && a[t] == i + 1) t++;
        if (t > 0 && a[t-1] == i+1) end_a[i] = t;
    }
    vector<int> start_b(n,-1);
    t = 0;
    for (int i = 0; i < n; i++) {
        while (t < n && b[t] < i + 1) t++;
        if (t < n && b[t] == i+1) start_b[i] = t;
    }
    int zurasi = 0;
    for (int i = 0; i < n; i++) {
        if (end_a[i] == -1 || start_b[i] == -1) continue;
        zurasi = max(zurasi,max(end_a[i] - start_b[i],0));
    }
    for (int i = 0; i < n; i++) {
        cout << b[(i-zurasi+n)%n] << " ";
    }
    
    
    
    cout << endl;
    return 0;
}
