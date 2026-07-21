#include <bits/stdc++.h>
using namespace std;

bool simpleSolve(int64_t N, vector<int64_t> A, vector<int64_t> B) {
    do {
        bool ok = true;
        for (uint64_t i = 0; i < A.size(); i++) {
            if (A[i] == B[i]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            cout << "Yes" << endl;
            for (uint64_t i = 0; i < B.size(); i++) {
                cout << B[i] << " \n"[i == B.size() - 1];
            }
            return true;
        }
    } while (next_permutation(B.begin(), B.end()));

    cout << "No" << endl;
    return false;
}

bool solve(int64_t N, vector<int64_t> A, vector<int64_t> B) {
    multiset<int64_t> st_B;
    for (uint64_t i = 0; i < A.size(); i++) {
        st_B.insert(B[i]);
    }

    //各数字の許容位置を考える
    vector<int64_t> num_A(N, 0), num_B(N, 0);
    for (int64_t i = 0; i < N; i++) {
        num_A[A[i]]++;
        num_B[B[i]]++;
    }

    //やばい順に出す
    priority_queue<pair<int64_t, int64_t>> pq;
    for (int64_t i = 0; i < N; i++) {
        if (num_B[i] == 0) {
            continue;
        }
        pq.push(make_pair(num_A[i] + num_B[i], i));
    }

    vector<int64_t> sub(N, 0);

    vector<int64_t> C(N);
    for (int64_t i = 0; i < N; i++) {
        pair<int64_t, int64_t> top = pq.top();

        while (sub[top.second] > 0) {
            pq.pop();
            top.first -= sub[top.second];
            sub[top.second] = 0;
            pq.push(top);
            top = pq.top();
        }
        pq.pop();

        if (top.second == A[i]) {
            pair<int64_t, int64_t> second = pq.top();
            while (sub[second.second] > 0) {
                pq.pop();
                second.first -= sub[second.second];
                sub[second.second] = 0;
                pq.push(second);
                second = pq.top();
            }

            if (second.second == A[i]) {
                cout << "No" << endl;
                return false;
            }
            pq.pop();

            C[i] = second.second;

            //使ったので
            second.first--;

            //入れ直す
            if (--num_B[second.second] != 0) {
                pq.push(second);
            }

            pq.push(top);

        } else {
            //topをそのまま使う
            C[i] = top.second;

            //使ったので減らす
            top.first--;

            //入れ直す
            if (--num_B[top.second] != 0) {
                pq.push(top);
            }
        }

        sub[A[i]]++;
    }

    cout << "Yes" << endl;
    for (uint64_t i = 0; i < B.size(); i++) {
        cout << C[i] + 1 << " \n"[i == C.size() - 1];
    }
    return true;
}

int main() {
    int64_t N;
    cin >> N;
    vector<int64_t> A(N), B(N);
    for (int64_t& a : A) {
        cin >> a;
        a--;
    }
    for (int64_t& b : B) {
        cin >> b;
        b--;
    }

    solve(N, A, B);

    //    while (true) {
//
//        mt19937_64 engine(random_device{}());
//        int64_t N = 10;
//        vector<int64_t> A(N), B(N);
//        uniform_int_distribution<int64_t> dist(0, 5);
//        for (int64_t i = 0; i < N; i++) {
//            A[i] = dist(engine);
//            B[i] = dist(engine);
//        }
//        sort(A.begin(), A.end());
//        sort(B.begin(), B.end());
//
//        cout << "curr input" << endl;
//        for (int64_t i = 0; i < N; i++) {
//            cout << setw(2) << A[i] + 1 << " \n"[i == B.size() - 1];
//        }
//        for (int64_t i = 0; i < N; i++) {
//            cout << setw(2) << B[i] + 1 << " \n"[i == B.size() - 1];
//        }
//
//        cout << "curr input(0-indexed)" << endl;
//        for (int64_t i = 0; i < N; i++) {
//            cout << setw(2) << A[i] << " \n"[i == B.size() - 1];
//        }
//        for (int64_t i = 0; i < N; i++) {
//            cout << setw(2) << B[i] << " \n"[i == B.size() - 1];
//        }
//
//        bool result1 = simpleSolve(N, A, B);
//
//        bool result2 = solve(N, A, B);
//        if (result1 != result2) {
//            break;
//        }
//    }
}
