#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Node {
    int depth;
    Node* child[2];
    Node() {
        child[0] = child[1] = nullptr;
    }
};

int main() {
    long long int N, L; scanf("%lld%lld", &N, &L);

    Node* root = new Node;
    root -> depth = 0;
    for(int i=0; i<N; i++) {
        string s; cin >> s;
        Node* cur = root;

        for(size_t k=0; k<s.length(); k++) {
            int c = s[k] - '0', d = cur -> depth;
            if(cur -> child[c] == nullptr) {
                cur -> child[c] = new Node;
                cur -> child[c] -> depth = d + 1;
            }
            cur = cur -> child[c];
        }
    }

    queue<Node*> que;
    que.push(root);
    long long int ans = 0;
    while(que.size()) {
        Node* cur = que.front(); que.pop();
        if((cur -> child[0] == nullptr) && (cur -> child[1] == nullptr)) continue;
        if((cur -> child[0] == nullptr) || (cur -> child[1] == nullptr)) {
            int d = cur -> depth;
            ans ^= (L - d) & (d - L);
        }

        for(int k=0; k<2; k++) {
            if(cur -> child[k] != nullptr) {
                que.push(cur -> child[k]);
            }
        }
    }
    printf("%s\n", ans ? "Alice" : "Bob");
    return 0;
}
