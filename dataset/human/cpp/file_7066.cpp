#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5+10;
int a[N], b[N], tb[N];
vector<int> dat[2][N];
int cnt[N];
int ans[N];

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a+i);
        dat[0][a[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", b+i);
        dat[1][b[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        int m = dat[0][i].size()+dat[1][i].size();
        if (m > n) {
            printf("No\n");
            return ;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) {
            cnt[a[i]]++;
        }
    }
    int ma = 0, sum = 0;
    int index = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > ma) {
            ma = cnt[i];
            index = i;
        }
        sum += cnt[i];
    }
    int left = max(0, 2*ma - sum);
    ma -= left;
    //cout << left << ' ' << index << ' ' << ma << endl;
    vector<int> vec1, vec2;
    for (int i = 1; i <= n && vec1.size() < left; i++) {
        if (a[i] == b[i] && a[i] == index) {
            vec1.push_back(i);
        }
    }
    for (int i = 1; i <= n && vec2.size() < left; i++) {
        if (a[i] != index && b[i] != index && a[i] != b[i]) {
            vec2.push_back(i);
        }
    }
    assert(vec1.size() == left);
    assert(vec2.size() == left);
    for (int i = 0; i < left; i++) {
        swap(b[vec1[i]], b[vec2[i]]);
    }
    // for (int i = 1; i <= n; i++) printf("%d%c", b[i], (i<n)?' ':'\n');

    vector<int> vec3;
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) {
            vec3.push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) tb[i] = b[i];
    for (int i = 0; i < vec3.size(); i++) {
        b[vec3[i]] = tb[vec3[(i+ma)%vec3.size()]];
    }

    printf("Yes\n");
    for (int i = 1; i <= n; i++) printf("%d%c", b[i], (i<n)?' ':'\n');

}

int main(){
    solve();
    return 0;
}
