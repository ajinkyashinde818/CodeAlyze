#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define REP(i, n) for (ll i = 0; i < n; i++)
#define REP1(i, n) for (ll i = 1; i <= n; i++)
#define RREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define RREP1(i, n) for (ll i = n; i >= 1; i--)
#define FOR(i, a, b, c) for (ll i = a; i <= b; i += c)
#define RFOR(i, a, b, c) for (ll i = a; i >= b; i -= c)
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)
#define INF 1145141919
typedef long long ll;

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%d\n", MAX(a * b, c * d));
    return 0;
}
