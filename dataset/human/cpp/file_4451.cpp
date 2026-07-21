#include <stdio.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <iomanip>
#include <unordered_map>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

class Union_Find {
    public:
    std::vector<int> par;
    Union_Find() {}
    Union_Find(int n){
        par.resize(n, 0);
        for(int i = 0; i < n; i++){
            par[i] = i;
        }
    }

    void simplify(int x) {
        std::vector<int> path;
        while (par[x] != x) {
            path.push_back(x);
            x = par[x];
        }
        for (int p : path) {
            par[p] = x;
        }
    }
    
    int find(int x){
        simplify(x);
        return par[x];
    }
    
    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if (x != y) {
            par[y] = x;
            // 改造する時は「根になっているノードの親を変更する」という原則が守られていることに注意。
        }
    }
};

const int MAX_N = 100050;
int N;
int a[MAX_N], b[MAX_N];

std::unordered_map<int, std::vector<int>> mp_a, mp_b;
Union_Find uf = Union_Find(MAX_N);

int main(int argc, char **argv) {
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        std::cin >> a[i];
    }

    for (int i = 1; i <= N; i++) {
        std::cin >> b[i];
    }

    for (int i = 1; i <= N; i++) {
        a[0] = a[0] ^ a[i];
        mp_a[a[i]].push_back(i);
        mp_b[b[i]].push_back(i);
    }

    mp_a[a[0]].push_back(0);

    for (int i = 1; i <= N; i++) {
        if (mp_a[b[i]].size() < mp_b[b[i]].size()) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }

    int dif_num = 0;
    for (int i = 1; i <= N; i++) {
        if (a[i] != b[i]) {
            dif_num++;
        }
    }

    if (dif_num == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        if (a[i] != b[i]) {
            for (int j : mp_b[a[i]]) {
                if (a[j] != b[j]) {
                    uf.unite(i, j);
                    if (mp_a[a[i]][0] != i) {
                        break;
                    }
                }
            }
        }
    }

    int con_num = 0;
    for (int i = 1; i <= N; i++) {
        if (a[i] != b[i] && uf.find(i) == i) {
            con_num++;
        }
    }

    int ret = dif_num + con_num;

    for (int i = 1; i <= N; i++) {
        if (a[i] != b[i] && b[i] == a[0]) {
            ret--;
            break;
        }
    }

    //if (mp_a[a[0]].size() == mp_b[a[0]].size()) {
    //    ret--;
    //}

    std::cout << ret << std::endl;
    
    return 0;
}
