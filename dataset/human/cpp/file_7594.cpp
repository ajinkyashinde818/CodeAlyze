#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int N; 
    cin >> N;
    vector<int> a(N);
    for(int i=0; i<N; i++) cin >> a[i];


    long sum = 0; long left = 0;
    long res = 99999999999999999L;
    long tmp;
    for(int i=0; i<N; i++) sum += a[i];
    for(int i=0; i<N-1; i++) {
        sum -= a[i];
        left += a[i];
        tmp = abs(left-sum);
        if(tmp < res) res = tmp;
    }

    cout << res << endl;
}
