#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <list>
#include <queue>
using namespace std;

int inf = (1 << 30);
int mod = 1e9 + 7;
int64_t inf64 = (1LL << 60);

template <typename T>
T gcd(T a, T b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

template <typename T>
T lcm(T a, T b) {
    T g = gcd(a, b);
    return a / g * b;
}

bool check(vector<int> a, int index, int key){
    if(a[index] >= key) return true;
    else return false;
}

int lower_bound(vector<int> a, int key){
    int left = -1, right = a.size();
    while(right - left > 1){
        int mid = left + (left + right) / 2;
        if(check(a, mid, key)) right = mid;
        else left = mid;
    }
    return right;
}

int main(){

    int N, M;
    cin >> N >> M;
    vector<string> A(N), B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    string ans = "No";
    for(int i = 0; i <= N - M; i++){
        for(int j = 0; j <= N - M; j++){
            bool flag = true;
            for(int x = 0; x < M; x++){
                for(int y = 0; y < M; y++){
                    if(A[i + x][j + y] != B[x][y]) flag = false;
                }
            }
            if(flag) ans = "Yes";
        }
    }

    cout << ans << endl;

    return 0;
}
