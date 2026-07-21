/*
TASK: ditch
LANG: C++11
 */
//#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 3, M = 2 * 3e4 + 3;

int arr[N];
long long mem[N][2];
int n;
long long solve(int i,int isPos){
    int s=isPos*2-1;
    if(i==n-1)return arr[i]*s;
    auto &ret=mem[i][isPos];
    if(ret!=0x3f3f3f3f3f3f3f3f)return ret;
    ret=arr[i]*s+solve(i+1,1);
    ret=max(ret,arr[i]*s*-1+solve(i+1,0));
    return ret;
}
int main() {
    //freopen("test.in", "r", stdin);

    while (cin >> n) {

        for (int i = 0; i < n; i++)cin >> arr[i];
        memset(mem,'?',sizeof mem);
        cout <<solve(0,1) << endl;
    }
    return 0;
}
