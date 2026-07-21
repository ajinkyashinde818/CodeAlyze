#include <bits/stdc++.h>

using namespace std;

char a[52][52];
char b[52][52];
bool check;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    check = false;
    for(int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }
    for(int i = 0; i < m; i++) {
        scanf("%s", b[i]);
    }
    for(int p = 0; p <= n - m; p++) {
        for(int q = 0; q <= n - m; q++) {
            check = true;
            for(int i = p; i < p + m; i++) {
                if(check == false) break;
                for(int j = q; j < q + m; j++) {
                    if(a[i][j] != b[i - p][j - q]) check = false;
                    if(check == false) break;
                    if(i == p + m - 1 && j == q + m - 1 && check == true) printf("Yes\n");
                }
            }
            if(check == true) break;
            else check = false;
        }
        if(check == true) break;
    }
    if(check == false) printf("No\n");
    return 0;
}
