#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

//int gcd(int a, int b) {
//    int v0 = a, v1 = b, v2 = a % b;
//    while (v2 != 0) {
//        v0 = v1;
//        v1 = v2;
//        v2 = v0 % v1;
//    };
//    return v1;
//}

int main() {
    int N;
    cin >> N;
    long A[N];
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    int nega=0;
    long sum=0;
    for (int i=0; i<N; i++) {
        if(A[i]<0){
            nega++;
            A[i]=(-1)*A[i];
        }
        sum+=A[i];
    }
    long min=A[0];
    for (int i=1; i<N; i++) {
        if (min>A[i]) {
            min=A[i];
        }
    }
    long ans=0;
    if (nega%2==0) {
        ans = sum;
    }
    else{
        ans=sum-(2*min);
    }
    cout << ans << endl;
}
