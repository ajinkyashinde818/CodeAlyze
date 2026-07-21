#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
int main(){
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    int cnt = 0;
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= n;j++){
            if(i * r + j * g <= n && (n - i * r - j * g) % b == 0)cnt++;
        }
    }
    cout << cnt << endl;
}
