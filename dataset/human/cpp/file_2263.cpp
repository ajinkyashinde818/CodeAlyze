#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
//for (int i = 0; i < N; i++){}
//for (int j = 0; j < M; j++){}
long long gcd(long long a, long long b) {
    if (b == 0){
      return a;
    }
    else return gcd(b, a % b);
}

int main() {
    long long N;
    cin >> N;

    long long A[N];

    for (long long i = 0; i < N; i++){
        cin >> A[i];
    }

    long long minusCnt = 0;
    for(long long i=0; i < N; i++){
        if(A[i]<0){
            minusCnt++;
        }
    }

    long long maxSums = 0;
    long long minNum = 10000000000;
    for(long long i=0; i < N; i++){
        maxSums += abs(A[i]);
        minNum = min(minNum, abs(A[i]));
    }
//    cout << maxSums << endl;
//    cout << minusCnt << endl;

    long long res = 0;
    if(minusCnt%2 == 0){
        res = maxSums;
    }else{
        res = maxSums - 2*minNum;
    }

    cout << res << endl;
}
