#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <stack>
#include <limits>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <memory>
//#include <tuple>

using namespace std;

//constexpr long long mod = static_cast<long long>(1e9 + 7);

struct Node {
    std::array<std::unique_ptr<Node>, 2> children;
};

void insert(Node& root, const std::string& str, int depth = 0) {
    if(str.size() <= depth) return;
    int i = str[depth] - '0';
    if(!root.children[i]) root.children[i] = std::make_unique<Node>();
    insert(*root.children[i], str, depth + 1);
}

long long grundy(unsigned long long i) {
    unsigned long long pow = 1;
    unsigned long long ans = 1;
    while(pow <= i) {
        if(i % pow == 0) ans = pow;
        pow *= 2;
    }
    return ans;
}

long long solve(const Node& root, long long L, long long depth = 0) {
    long long ans = 0;
    if(root.children[0]) {
        if(!root.children[1]) ans ^= grundy(L - depth - 1);
        else ans ^= solve(*root.children[1], L, depth + 1);
        ans ^= solve(*root.children[0], L, depth + 1);
    } else {
        if(root.children[1]) {
            ans ^= grundy(L - depth - 1);
            ans ^= solve(*root.children[1], L, depth + 1);
        }
    }
    return ans;
}

int main() {
    int N;
    long long L;
    std::cin >> N >> L;
    auto root = std::make_unique<Node>();
    while(N--) {
        std::string str;
        std::cin >> str;
        insert(*root, str);
    }

    auto ans = solve(*root, L + 1);

    std::cout << (ans != 0 ? "Alice" : "Bob") << std::endl;

    return 0;
}
