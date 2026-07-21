#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

struct Node {
    shared_ptr<Node> left, right;
    ll height, child_num;
    Node() : left(nullptr), right(nullptr), height(0), child_num(0) {}
};

int main() {
    ll N, L;
    cin >> N >> L;

    shared_ptr<Node> root = make_shared<Node>();

    for (ll i = 0; i < N; i++) {
        string s;
        cin >> s;
        shared_ptr<Node> curr = root;

        for (char c : s) {
            if (c == '0') {
                if (curr->left == nullptr) {
                    //作る
                    curr->left = make_shared<Node>();
                    curr->left->height = curr->height + 1;
                    curr->child_num++;
                }
                curr = curr->left;
            } else {
                if (curr->right == nullptr) {
                    //作る
                    curr->right = make_shared<Node>();
                    curr->right->height = curr->height + 1;
                    curr->child_num++;
                }
                curr = curr->right;
            }
        }
    }

    vector<ll> levels;

    stack<shared_ptr<Node>> st;
    st.push(root);

    while (!st.empty()) {
        auto t = st.top();
        st.pop();

        if (t->child_num == 1) {
            levels.push_back(L - t->height);
        }

        if (t->left != nullptr) {
            st.push(t->left);
        }

        if (t->right != nullptr) {
            st.push(t->right);
        }
    }

    ll grundy = 0;
    for (ll level : levels) {
        ll g = 1;
        while (level % g == 0) {
            g *= 2;
        }
        g /= 2;

        grundy ^= g;
    }

    cout << (grundy != 0 ? "Alice" : "Bob") << endl;
}
