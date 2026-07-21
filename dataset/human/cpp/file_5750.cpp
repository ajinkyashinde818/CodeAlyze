#include <cstdio>
static_assert(sizeof(long) >= 8, "long too short");
using namespace std;
struct Node {
    Node *ch[2];
    Node() = default;
};
void insert(Node *n, char *s) {
  	while (*s) {
      	auto &ch = n->ch[*s++ - '0'];
        if (!ch)
            ch = new Node();
      	n = ch;
    }
}
long solve(Node *n, long m) {
    return n ? solve(n->ch[0], m - 1) ^ solve(n->ch[1], m - 1) : m & -m;
}
char s[100001];
int main() {
    int n;
    long m;
    scanf("%d %ld", &n, &m);
    Node *root = new Node();
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        insert(root, s);
    }
    puts(solve(root, m + 1) ? "Alice" : "Bob");
}
