#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int A[1010][1010];

int main() {
    int n;
    scanf("%d", &n);
    int t = 1;
    while(t <= n) n -= t++;
    t--;
    if(n) {
        puts("No");
        return 0;
    }
    puts("Yes");
    printf("%d\n", t + 1);
    int cnt = 0;
    for(int i = 1; i <= t + 1; i++)
        for(int j = i + 1; j <= t + 1; j++)
            A[i][j] = (A[j][i] = ++cnt);
    for(int i = 1; i <= t + 1; i++) {
        printf("%d ", t);
        for(int j = 1; j <= t + 1; j++)
            if(i != j) printf("%d ", A[i][j]);
        putchar('\n');
    }
}
