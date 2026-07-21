#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int m;
    scanf("%d", &m);

    for (int n = 1; n * (n - 1) <= 2 * m; n++)
        if (n * (n - 1) == 2 * m) {
            vector<vector<int>> v(n);
            for (int i = 0, k = 0; i < n; i++)
                for (int j = 0; j < i; j++, k++) {
                    v[i].push_back(k);
                    v[j].push_back(k);
                }

            puts("Yes");
            printf("%d\n", n);

            for (int i = 0; i < n; i++) {
                printf("%zd", v[i].size());
                for (int j : v[i])
                    printf(" %d", j + 1);
                putchar('\n');
            }

            return 0;
        }

    puts("No");
    return 0;
}
