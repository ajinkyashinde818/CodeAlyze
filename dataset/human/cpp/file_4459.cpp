#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 1e5 +6;

int a[MAX_N];
int b[MAX_N];

vector<int> edg[MAX_N];
bool visit[MAX_N];

void dfs(int id) {
    visit[id]=1;
    for (int i:edg[id]) {
        if (!visit[i]) dfs(i);
    }
}

int main (){
    int n;
    scanf("%d",&n);
    vector<int> v;
    int kirino=0;
    multiset<int> st;
    for (int i=1;n>=i;i++) {
        scanf("%d",&a[i]);
        v.push_back(a[i]);
        kirino ^= a[i];
        st.insert(a[i]);
    }
    int cnt=0;
    bool meruru = 0;
    for (int i=1;n>=i;i++) {
        scanf("%d",&b[i]);
        v.push_back(b[i]);
        if (st.find(b[i]) != st.end()) {
            cnt++;
            st.erase(st.find(b[i]));
            if (b[i] == kirino) {
                meruru = 1;
            }
        }
        else {
            if (b[i] != kirino) {
                cnt = -2*n;
            }
            else {
                meruru = 1;
            }
        }
    }
    if (cnt <= n-2) {
        puts("-1");
        return 0;
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end()) - v.begin());
    int dif=0;
    for (int i=1;n>=i;i++) {
        a[i] = lower_bound(v.begin(),v.end(),a[i]) - v.begin()+1;
        b[i] = lower_bound(v.begin(),v.end(),b[i]) - v.begin()+1;
        if (a[i] != b[i]) {
            edg[a[i] ].push_back(b[i]);
            edg[b[i] ].push_back(a[i]);
            dif++;
        }
    }
    int cc=0;
    for (int i=1;v.size()>=i;i++) {
        if (edg[i].size() != 0 && !visit[i]) {
            dfs(i);
            cc++;
        }
    }
    if (cc==0) meruru=0;
    printf("%d\n",dif+cc-meruru);
}
