#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <numeric>
using namespace std;

int main(){
    int N;
    cin >> N;
    long sum = 0;
    vector<long> A(N);
    for(int i = 0;i<N;i++){
        cin >> A[i];
        sum = sum + abs(A[i]);
    }

    long MIN = 10000000000;
    int count = 0;
    for(int i = 0;i<N;i++){
        MIN = min(MIN,abs(A[i]));
        if(A[i] < 0) {
            count = count + 1;
        }
    }

    if(count % 2 == 0){
        cout << sum << endl;
    }else{
        cout << sum - MIN * 2 << endl;
    }
}
