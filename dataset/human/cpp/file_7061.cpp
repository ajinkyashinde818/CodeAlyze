#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 2e5 + 5, MOD = 1e9 + 7;

template <typename T>
inline void read(T& x, T f = 1, char ch = getchar()) {
    x = 0;
    while (!isdigit(ch)) f = (ch == '-') ? -1 : 1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
    x *= f;
}


int n;
array<int, MAXN> a, b, ans;

struct SegTree {
    SegTree* lson, *rson;
    int l, r;
    int max;
} *root, tree[MAXN << 1];

inline SegTree* newNode(SegTree*& root) {
    static int tot;
    return root = &tree[tot++];
}

inline void update(SegTree* root) {
    root->max = max(root->lson->max, root->rson->max);
}

inline void build(SegTree*& root, int l, int r) {
    newNode(root);
    root->l = l, root->r = r;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(root->lson, l, mid), build(root->rson, mid + 1, r);
}

inline void modify(SegTree* root, int val, int num) {
    if (root->l == val && root->r == val) {
        root->max += num;
        return;
    }
    int mid = (root->l + root->r) >> 1;
    if (val <= mid) modify(root->lson, val, num);
    else modify(root->rson, val, num);
    update(root);
}

int res = 0;
inline void query(SegTree* root, int l, int r) {
    if (l <= root->l && root->r <= r) {
        if (root->max == 0) return;
        if (root->l == root->r) {
            res = max(res, root->l);
            return;
        }
        if (root->lson->max > 0 && root->lson->max >= root->rson->max)
            query(root->lson, l, r);
        else query(root->rson, l, r);
        return;
    }
    int mid = (root->l + root->r) >> 1;
    if (l <= mid) query(root->lson, l, r);
    if (r > mid) query(root->rson, l, r);
}

inline int qpos(SegTree* root, int pos) {
    if (root->l == pos && root->r == pos) {
        return root->max;
    }
    int mid = (root->l + root->r) >> 1;
    if (pos <= mid) return qpos(root->lson, pos);
    else return qpos(root->rson, pos);
}

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(root, 1, n);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        modify(root, b[i], 1);
    }
    for (int i = n; i >= 1; i--) {
        res = 0;
        if (a[i] > 1)
            query(root, 1, a[i] - 1);
        if (a[i] < n && !res)
            query(root, a[i] + 1, n);
        if (!res) {
            cout << "No" << endl;
            return 0;
        }
        modify(root, res, -1);
        ans[i] = res;
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}
