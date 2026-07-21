#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

const int MAX = 100000;
const int INF = 1 << 30;

int main(){
    int N;
    int A[MAX];
    int cnt = 0;
    int m = INF;
    long long sum = 0;

    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> A[i];
        if(A[i] < 0)cnt++;
        m = min(m,abs(A[i]));
        sum += abs(A[i]);
    }

    if(cnt % 2)cout << sum - m * 2 << endl;
    else cout << sum << endl;

    return 0;
}
