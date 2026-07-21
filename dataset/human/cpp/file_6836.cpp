#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, a[200000], b[200000], pos[200010], mx;
vector<int> arr;

int main() {
    arr.push_back(0);
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) scanf("%d", &a[i]);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &b[i]);
        if (arr.back() != b[i]) {
            arr.push_back(b[i]);
            pos[b[i]] = i;
        }
    }
    arr.push_back(200001);
    pos[200001] = n;
    for (int i = 0 ; i < n ; i++) {
        int tmp = *lower_bound(arr.begin(), arr.end(), a[i] + 1);
        int gap = pos[tmp] - i;
        if (mx < gap) mx = gap;
    }
    for (int i = 0, j = mx % n ; i < n ; i++, j = (j + 1) % n) {
        if (a[i] == b[j]) {
            printf("No");
            return 0;
        }
    }
    printf("Yes\n");
    for (int i = 0, j = mx % n ; i < n ; i++, j = (j + 1) % n) {
        printf("%d ", b[j]);
    }
}
