#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <tuple>
#include <string.h>
#include <math.h>
#include <random>
#include <functional>
#include <assert.h>
#include <math.h>
#include <sstream>
#include <iterator>

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int main()
{
    i64 n, c;
    scanf("%lld %lld", &n, &c);

    vector<i64> dist(n);
    vector<i64> value(n);

    for (int i = 0; i < n; i++)
        scanf("%lld %lld", &dist[i], &value[i]);

    vector<i64> clock(n), counter(n);
    clock[0] = value[0];
    counter[n - 1] = value[n - 1];

    for (int i = 1; i < n; i++)
        clock[i] = value[i] + clock[i - 1];

    for (int i = n - 2; i >= 0; i--)
        counter[i] = counter[i + 1] + value[i];

    //앞뒤로 시작점에서의 거리만큼 빼준다

    for (int i = 0; i < n; i++)
        clock[i] -= dist[i];

    for (int i = 0; i < n; i++)
        counter[i] -= c - dist[i];

    //각각의 방향에서 특정지점까지 갔을 때 최대치 구하기
    for (int i = 1; i < n; i++)
        clock[i] = max(clock[i - 1], clock[i]);

    for (int i = n - 2; i >= 0; i--)
        counter[i] = max(counter[i + 1], counter[i]);

    i64 ans = max({ 0ll, clock[n - 1], counter[0] });

    //각 방향에서 중간 꺾는 거 계산

    for (int i = 0; i < n - 1; i++)
        ans = max(ans, clock[i] - dist[i] + counter[i + 1]);

    for (int i = 1; i < n; i++)
        ans = max(ans, counter[i] + clock[i - 1] - (c - dist[i]));


    printf("%lld", ans);

    return 0;
}
