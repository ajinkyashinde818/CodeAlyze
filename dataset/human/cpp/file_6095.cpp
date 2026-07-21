#include"bits/stdc++.h"
using namespace std;

int main() {
    long long N, C;
    cin >> N >> C;

    vector<long long> x(N), v(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> v[i];
    }

    //解のパターンは3種類か
    long long ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
    {
        //1.左回りのみ
        long long curr_score = 0, curr_pos = 0;
        for (int i = 0; i < N; i++) {
            curr_score += v[i] - (x[i] - curr_pos);
            ans1 = max(ans1, curr_score);
            curr_pos = x[i];
        }
    }

    //2.右回りのみ
    {
        long long curr_score = 0, curr_pos = C;
        for (int i = N - 1; i >= 0; i--) {
            curr_score += v[i] - (curr_pos - x[i]);
            ans2 = max(ans2, curr_score);
            curr_pos = x[i];
        }
    }

    //3.左いってから右
    {
        vector<long long> left_scores(N, 0);
        long long curr_score = 0, curr_pos = 0;
        for (int i = 0; i < N; i++) {
            curr_score += v[i];
            left_scores[i] = curr_score;
        }

        //iまで行って戻ってくる
        for (int i = 0; i < N; i++) {
            left_scores[i] -= x[i] * 2;
        }
        curr_pos = C;
        curr_score = 0;
        vector<long long> right_scores(N, 0);
        //右回り
        for (int i = N - 1; i > 0; i--) {
            curr_score += v[i] - (curr_pos - x[i]);
            right_scores[i] = curr_score;
            curr_pos = x[i];
        }

        vector<long long> max_left_scores(N), max_right_scores(N);
        max_left_scores[0] = left_scores[0];
        for (int i = 1; i < N; i++) {
            max_left_scores[i] = max(max_left_scores[i - 1], left_scores[i]);
        }

        max_right_scores[N - 1] = right_scores[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            max_right_scores[i] = max(max_right_scores[i + 1], right_scores[i]);
        }

        for (int i = 0; i < N - 1; i++) {
            ans3 = max(ans3, max_left_scores[i] + max_right_scores[i + 1]);
        }
    }

    //4.右行ってから左
    {
        vector<long long> right_scores(N, 0);
        long long curr_score = 0, curr_pos = C;
        for (int i = N - 1; i > 0; i--) {
            curr_score += v[i];
            right_scores[i] = curr_score;
        }

        //iまで行って戻ってくる
        for (int i = N - 1; i > 0; i--) {
            right_scores[i] -= (C - x[i]) * 2;
        }
        curr_pos = 0;
        curr_score = 0;
        vector<long long> left_scores(N, 0);
        //左
        for (int i = 0; i < N; i++) {
            curr_score += v[i] - (x[i] - curr_pos);
            left_scores[i] = curr_score;
            curr_pos = x[i];
        }

        vector<long long> max_left_scores(N), max_right_scores(N);
        max_left_scores[0] = left_scores[0];
        for (int i = 1; i < N; i++) {
            max_left_scores[i] = max(max_left_scores[i - 1], left_scores[i]);
        }

        max_right_scores[N - 1] = right_scores[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            max_right_scores[i] = max(max_right_scores[i + 1], right_scores[i]);
        }

        for (int i = 0; i < N - 1; i++) {
            ans4 = max(ans4, max_left_scores[i] + max_right_scores[i + 1]);
        }
    }

    cout << max({ ans1, ans2, ans3, ans4 }) << endl;
}
