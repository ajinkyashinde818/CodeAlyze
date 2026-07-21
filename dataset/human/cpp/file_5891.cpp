#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

typedef long long ll;

int main() {
    ll n, c;
    std::cin >> n >> c;

    std::vector<ll> dist(n);
    std::vector<ll> revdist(n);
    std::vector<ll> nutr(n);

    ll allnutr = 0;

    for (int i = 0; i < n; ++i) {
        ll x, y;
        std::cin >> x >> y;
        dist[i] = x;
        revdist[i] = c - x;
        nutr[i] = y;
        allnutr += y;
    }

    ll maxall = allnutr - c + std::max(dist[0], c - dist[n - 1]);

    std::vector<ll> nutr_clockwise(n);
    std::vector<ll> nutr_cntrclockwise(n);
    ll wise_cnt = 0, cntrwise_cnt = 0;
    for (int i = 0; i < n; ++i) {
        wise_cnt += nutr[i];
        nutr_clockwise[i] = wise_cnt - dist[i];
        cntrwise_cnt += nutr[n - i - 1];
        nutr_cntrclockwise[n - i - 1] = cntrwise_cnt - (c - dist[n - i - 1]);
    }

    std::vector<ll> prefclockwise(n), prefcntrclockwise(n);
    ll totalclockwise = 0, totalcntrclockwise = 0;
    prefclockwise[0] = std::max(0LL, (nutr[0] - dist[0]));
    prefcntrclockwise[n - 1] = std::max(0LL, (nutr[n - 1] - (c - dist[n - 1])));
    for (int i = 1; i < n; ++i) {
        prefclockwise[i] = std::max(nutr_clockwise[i], prefclockwise[i - 1]);
        prefcntrclockwise[n - i - 1] =
            std::max(nutr_cntrclockwise[n - i - 1], prefcntrclockwise[n - i]);
    }

    long long max = maxall;
/*
    for (int i = 0; i < n; ++i) {
 //       std::cout << prefclockwise[i] << "\n";
   //     std::cout << prefcntrclockwise[i] << "\n";
     //   std::cout << prefclockwise[i] + prefcntrclockwise[i] << "\n";
        long long new_max = std::max(std::max(prefclockwise[i] + prefcntrclockwise[i] - dist[i],
                                        prefcntrclockwise[i] + prefclockwise[i] - nutr[i] - (c - dist[i])),
                                    std::max(prefclockwise[i],
                                    prefcntrclockwise[i]));
        max = std::max(max, new_max);
    }
  */
    for (int i = 0; i < n - 1; ++i) {
        long long new_max = std::max(prefclockwise[i], prefclockwise[i] - dist[i] + prefcntrclockwise[i + 1]);
        max = std::max(max, new_max);
    }
    max = std::max(max, prefclockwise[n - 1]);
    max = std::max(max, prefcntrclockwise[0]);
    for (int i = 1; i < n; ++i) {
        long long new_max = std::max(prefcntrclockwise[i],
                                        prefcntrclockwise[i] - (c - dist[i]) + prefclockwise[i - 1]);
        max = std::max(max, new_max);
    }

    std::cout << max;
}
