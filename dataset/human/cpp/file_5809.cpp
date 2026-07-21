#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

typedef long long li;

template<class ValueType, ValueType offset, size_t AlphabetSize>
struct Trie {
    typedef Trie<ValueType, offset, AlphabetSize> Node;
    vector<Node*> children;
    bool have;

    Trie(): children(AlphabetSize, nullptr), have(false) {}
    ~Trie() {
        for (auto &&child : children) {
            if (child != nullptr) {
                delete child;
            }
        }
    }

    void insert_internal(const vector<ValueType>& seq, int index) {
        if (index == seq.size()) {
            have = true;
        } else {
            Node*& next = children[seq[index] - offset];
            if (next == nullptr) {
                next = new Trie();
            }
            next->insert_internal(seq, index + 1);
        }
    }

    void insert(const vector<ValueType>& seq) {
        insert_internal(seq, 0);
    }

    void insert(const string& s) {
        insert(vector<char>(s.begin(), s.end()));
    }

    bool contains_internal(const vector<ValueType>& seq, int index) {
        if (have) {
            return true;
        }
        for (int i = 0; i < AlphabetSize; ++i) {
            if (children[i] != nullptr && children[i]->contains_internal(seq, index + 1)) {
                return true;
            }
        }
        return false;
    }

    bool contains(const vector<ValueType>& seq) {
        return contains_internal(seq, 0);
    }
};

typedef Trie<char, '0', 2> BinaryTrie;

li traverse(BinaryTrie* node, li depth) {
    if (node == nullptr) {
        return 0;
    }
    int null_count = 0;
    for (auto &&child : node->children) {
        null_count += child == nullptr;
    }
    li nim = 0;
    if (null_count == 1) {
        nim ^= depth & -depth;
    }
    for (auto &&child : node->children) {
        nim ^= traverse(child, depth - 1);
    }
    return nim;
}

int main() {
    li n, l;
    cin >> n >> l;

    BinaryTrie* root = new BinaryTrie();
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        root->insert(s);
    }

    li nim = traverse(root, l);
    cout << (nim ? "Alice" : "Bob") << endl;
    return 0;
}
