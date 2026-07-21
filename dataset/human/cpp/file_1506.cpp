#include <cstring>
#include <map>
#include <unordered_map>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> pii;

int gi() {
    int a;
    scanf("%d", &a);
    return a;
}

ll gli() {
    ll a;
#ifndef ONLINE_JUDGE
    scanf("%lld", &a);
#else
    scanf("%I64d", &a);
#endif
    return a;
}

vector<int> res[450];

int main() {
    int n = gi();

    int k = 1;
    for (; k < 450; k++)
        if (k*(k-1)/2 == n)
            break;

    if (k == 450) {
        printf("No\n");
        return 0;
    }

    int c = 0;
    for (int i = 0; i < k; i++)
        for (int j = i+1; j < k; j++) {
            c++;
            res[i].push_back(c);
            res[j].push_back(c);
        }

    printf("Yes\n%d", k);
    for (int i = 0; i < k; i++) {
        printf("\n%d", k-1);
        for (int j = 0; j < k-1; j++)
            printf(" %d", res[i][j]);
    }
    printf("\n");

    return 0;
}
