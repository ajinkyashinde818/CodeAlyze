#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 100005;

int n, l[N], r[N], cc;
char b[N];
ll d, a;

void f(int x, ll d){
    if(!!l[x] ^ !!r[x]) a ^= (d & -d);
    if(l[x]) f(l[x], d - 1);
    if(r[x]) f(r[x], d - 1);
}

int main(){
    scanf("%d%lld", &n, &d);
    for(; n--; ){
        scanf("%s", b);
        int c = 0;
        for(int i = 0; b[i]; i++){
            int &nx = (b[i] == '0') ? l[c] : r[c];
            if(!nx) nx = ++cc;
            c = nx;
        }
    }
    f(0, d);
    puts(a ? "Alice" : "Bob");
}
