#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string.h>
#include <set>
#include <algorithm>
using namespace std;
vector<int> a[1000];
int n;
void solve(){
    int p = -1;
    for (int i = 1 ; i * (i + 1) <= 2 * n ; ++i){
        if (i * (i + 1) == 2 * n){
            p = i;
            break;
        }
    }
    if (p == -1){
        puts("No");
        return;
    }
    for (int i = 0 ; i <= p ; ++i) a[i].clear();
    int q = 0;
    for (int i = 0 ; i < p ; ++i){
        for (int j = i + 1 ; j <= p ; ++j){
            ++q;
            a[i].push_back(q);
            a[j].push_back(q);
        }
    }
    puts("Yes");
    printf("%d\n" , p + 1);
    for (int i = 0 ; i <= p ; ++i){
        printf("%d" , (int)a[i].size());
        for (int j = 0 ; j < a[i].size(); ++j)
            printf(" %d" , a[i][j]);
        puts("");
    }
}
int main(){
    while(cin >> n) solve();
}
