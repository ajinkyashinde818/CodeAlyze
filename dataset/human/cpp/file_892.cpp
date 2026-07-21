#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <string>
#include <iostream>
#include <stack>
 
using namespace std;
 
int main(){
    int r, g, b, n;
    scanf("%d %d %d %d", &r, &g, &b, &n);

    int ans = 0;

    for(int i = 0; i <= n / r; ++i){
        for(int j = 0; j <= (n - r*i)/g; ++j){
            if((n - r*i - g*j) % b == 0){
                ans++;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
