#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

#define ll long long
#define ld long double

struct Node {
    int num;
    long double dist;
    bool operator<(const Node &right) const {
        return dist >= right.dist;
    }
    Node(int n, long double d) {
        num = n;
        dist = d;
    }
};

long double d(int ax, int ay, int bx, int by) {
    return sqrt((long double)(ax - bx) * (long double)(ax - bx) +
                (long double)(ay - by) * (long double)(ay - by));
}

int main() {
    int Xs, Ys, Xt, Yt;
    cin >> Xs >> Ys >> Xt >> Yt;
    int N;
    cin >> N;
    vector<int> x(N + 2), y(N + 2), r(N + 2);
    for (int i = 0; i < N; i++) {
        cin >> x[i + 1] >> y[i + 1] >> r[i + 1];
    }
    x[0] = Xs;
    y[0] = Ys;
    r[0] = 0;
    x[N + 1] = Xt;
    y[N + 1] = Yt;
    r[N + 1] = 0;
    vector<bool> ch(N + 2);
    vector<long double> dist(N + 2);
    for (int i = 0; i < N + 2; i++) {
        ch[i] = false;
        dist[i] = 1e18;
    }
    dist[0] = 0;
    priority_queue<Node> pq;
    pq.push(Node(0, 0));
    while (pq.size() > 0) {
        Node n = pq.top();
        pq.pop();
        int this_num = n.num;
        long double this_dist = n.dist;
        if (ch[this_num])
            continue;

        ch[this_num] = true;

        for (int i = 0; i < N + 2; i++) {
            if (ch[i])
                continue;

            long double dd = d(x[this_num], y[this_num], x[i], y[i]);
            long double next_dist =
                this_dist +
                max((long double)0, dd - (long double)(r[this_num] + r[i]));

            if (dist[i] > next_dist) {
                dist[i] = next_dist;
                pq.push(Node(i, next_dist));
            }
        }
    }
    // for (long double longd : dist) {
    //    cout << longd << endl;
    //}
    cout << fixed << setprecision(10) << dist[N + 1] << endl;
    return 0;
}
