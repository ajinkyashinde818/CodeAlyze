#include <bits/stdc++.h>
#include <boost/range/irange.hpp>
#include <boost/range/adaptors.hpp>

using namespace std;
using namespace boost::adaptors;
using uint = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

void walk(vector<ll> & distance, vector<ll> & values, vector<ll> & consumption, vector<ll> & nutrition, vector<ll> & gain_max_reminder, ll N){
    for (auto &&i: boost::irange(1LL, N+1)){
        consumption.at(i) = distance.at(i-1);
        nutrition.at(i) = nutrition.at(i-1) + values.at(i-1);
    }
    ll maximum = 0;
    for (auto &&i: boost::irange(1LL, N+1)){
        if (maximum < nutrition.at(i) - consumption.at(i)){
            maximum = nutrition.at(i) - consumption.at(i);
        }
        gain_max_reminder.at(i) = maximum;
    }
}



int main() {
    ll N, C;
    cin >> N >> C;
    vector<ll> xs_right(N, 0), vs_right(N, 0);
    for (auto &&i: boost::irange(0LL, N)){
        cin >> xs_right.at(i) >> vs_right.at(i);
    }
    vector<ll> xs_left(xs_right.begin(), xs_right.end());
    vector<ll> vs_left(vs_right.begin(), vs_right.end());
    reverse(xs_left.begin(), xs_left.end());
    reverse(vs_left.begin(), vs_left.end());
    for (auto &&i: boost::irange(0LL, N)){
        xs_left.at(i) = C - xs_left.at(i);
    }
    ll right_max, right_idx, left_max, left_idx;
    vector<ll> consumption_right(N+1, 0), consumption_left(N+1, 0), nutrition_right(N+1, 0), nutrition_left(N+1, 0), gain_max_reminder_left(N+1, 0), gain_max_reminder_right(N+1, 0);
    walk(xs_right, vs_right, consumption_right, nutrition_right, gain_max_reminder_right, N);
    walk(xs_left, vs_left, consumption_left, nutrition_left, gain_max_reminder_left, N);

    vector<ll> gain_right_left(N+1, 0), gain_left_right(N+1, 0);
    for (auto &&i: boost::irange(0LL, N + 1)){
        gain_right_left.at(i) = nutrition_right.at(i) - consumption_right.at(i) * 2 + gain_max_reminder_left.at(N - i);
    }
    for (auto &&i: boost::irange(0LL, N + 1)){
        gain_left_right.at(i) = nutrition_left.at(i) - consumption_left.at(i) * 2 + gain_max_reminder_right.at(N - i);
    }

    ll maximum = 0;
    for (auto &&i: boost::irange(0LL, N+1)){
        maximum = max(gain_right_left.at(i), max(gain_left_right.at(i), maximum));
    }
    cout << maximum;
    return 0;
}
