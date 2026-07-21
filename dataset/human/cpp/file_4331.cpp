#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100100], brr[100100];
multiset<int> s;
vector<int> comp, lis[100100];
bool visit[100100];

void dfs(int here) {
    int i;
    visit[here] = true;
    for (i=0;i<lis[here].size();i++) {
        int there = lis[here][i];
        if (visit[there]) continue;
        dfs(there);
    }
}

int main() {
    int i;
    scanf("%d",&n);

    for (i=0;i<n;i++) scanf("%d",&arr[i]);
    for (i=0;i<n;i++) scanf("%d",&brr[i]);
    for (i=0;i<n;i++) arr[n]^=arr[i];
    for (i=0;i<n;i++) brr[n]^=brr[i];
    n++;
    for (i=0;i<n;i++) s.insert(arr[i]);
    for (i=0;i<n;i++) {
        if (s.find(brr[i])==s.end()) {
            printf("-1\n");
            return 0;
        }
        s.erase(s.find(brr[i]));
    }
    for (i=0;i<n;i++) {
        if (arr[i]!=brr[i]) break;
    }
    if (i==n) {
        printf("0\n");
        return 0;
    }
    for (i=0;i<n;i++) {
        if (arr[i]!=brr[i]||i==n-1) {
            comp.push_back(arr[i]);
        }
    }
    sort(comp.begin(),comp.end());
    comp.erase(unique(comp.begin(),comp.end()),comp.end());
    int acnt = 0;
    for (i=0;i<n;i++) {
        if (arr[i]==brr[i]&&i!=n-1) continue;
        acnt++;
        arr[i] = lower_bound(comp.begin(),comp.end(),arr[i])-comp.begin();
        brr[i] = lower_bound(comp.begin(),comp.end(),brr[i])-comp.begin();
    }
    for (i=0;i<n;i++) {
        if (arr[i]==brr[i]&&i!=n-1) continue;
        lis[brr[i]].push_back(arr[i]);
    }
    acnt-=2;
    for (i=0;i<comp.size();i++) {
        if (!visit[i]) {
            dfs(i);
            acnt++;
        }
    }
    printf("%d\n",acnt);

    return 0;
}
