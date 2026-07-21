#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <unordered_map>
#include <cmath>
#include <cassert>
#include <cstring>
#include <queue>

class SolutionCrossing {
public:
//    found
//    1 2 3 4
//    1 5 6 7
//    2 5 8 9
//    3 6 8 10
//    4 7 9 10
//
//    int n;
//    std::vector<int> used, sets;
//
//    void rec(int size) {
//        bool found = true;
//        for (int i = 0; i < n; i++) {
//            if (used[i] != 2) {
//                found = false;
//            }
//        }
//        if (found) {
//            std::cerr << "found" << std::endl;
//            for (int mask : sets) {
//                for (int i = 0; i < n; i++) {
//                    if (((mask >> i) & 1)) {
//                        std::cerr << (i + 1) << " ";
//                    }
//                }
//                std::cerr << std::endl;
//            }
//            exit(0);
//        }
//
//        for (int mask = 1; mask < (1 << n); mask++) {
//            if (__builtin_popcount(mask) != size)
//                continue;
//            bool fail = false;
//            for (int i = 0; i < n; i++) {
//                if (((mask >> i) & 1) && used[i] >= 2) {
//                    fail = true;
//                }
//            }
//            for (int before : sets) {
//                if (__builtin_popcount(mask & before) != 1) {
//                    fail = true;
//                }
//            }
//            if (!fail) {
//                for (int i = 0; i < n; i++) {
//                    if (((mask >> i) & 1)) {
//                        ++used[i];
//                    }
//                }
//                sets.push_back(mask);
//                rec(size);
//                sets.pop_back();
//                for (int i = 0; i < n; i++) {
//                    if (((mask >> i) & 1)) {
//                        --used[i];
//                    }
//                }
//            }
//        }
//    }

    void solve(std::istream& in, std::ostream& out) {
//        in >> n;
//        used.assign(n, 0);
//        for (int size = 1; size < n; size++)
//            if ((2 * n) % size == 0)
//                rec(size);

        int n;
        in >> n;
        int x = -1, y = -1;
        for (int i = 1; i * i <= 2 * n; i++) {
            if (i * (i + 1) == (2 * n)) {
                x = i;
                y = i + 1;
                break;
            }
        }
        if (x == -1) {
            out << "No" << "\n";
            return;
        }
        std::vector<int> used(n);
        std::vector<std::vector<int>> sets;
        std::vector<int> set;
        std::queue<int> queue;
        for (int i = 0; i < n; i++) {
            queue.push(i);
        }
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < i; j++) {
                set.push_back(sets[j][i - 1]);
            }
            for (int j = 0; set.size() < x; ++j) {
                set.push_back(queue.front());
                queue.pop();
            }
            sets.push_back(set);
            set.clear();
        }
        for (auto s : sets)
            for (int i : s)
                ++used[i];



        for (int i : used)
            assert(i == 2);
        out << "Yes" << "\n";
        out << sets.size() << "\n";
        for (auto s : sets) {
            out << s.size() << ' ';
            for (int i : s) {
                out << (i + 1) << ' ';
            }
            out << "\n";
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    using Solution = SolutionCrossing;

    int tests = 1;
//    std::cin >> tests;
    for (int test = 0; test < tests; ++test) {
        Solution solution;
        solution.solve(std::cin, std::cout);
    }

    return 0;
}
