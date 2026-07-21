#include <cstdio>
#include <vector>

using namespace std;

vector <int> v[1000];

int main() {
    int n, c = 1, i, j, k;
    
    scanf("%d", &n);
    
    if (n == 1) {
        puts("Yes");
        puts("2");
        puts("1 1");
        puts("1 1");
    } else {
        for (i = 1; i * (i - 1) <= n * 2; i++) {
            if (i * (i - 1) == n * 2) {
                puts("Yes");
                printf("%d\n", i);
                
                for (j = 0; j < i; j++) {
                    for (k = j + 1; k < i; k++) {
                        v[j].push_back(c);
                        v[k].push_back(c);
                        c++;
                    }
                }
                
                for (j = 0; j < i; j++) {
                    printf("%d", v[j].size());
                    for (k = 0; k < v[j].size(); k++) printf(" %d", v[j][k]);
                    puts("");
                }
                
                return 0;
            }
        }
        
        puts("No");
    }
    
    return 0;
}
