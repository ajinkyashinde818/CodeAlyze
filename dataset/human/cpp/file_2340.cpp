#include <iostream>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
using namespace std;
using ll = long long;
using graph = std::vector<std::vector<long long>>;
int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll minC = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        if(A[i] < 0){
            minC++;
        }
        A[i] = abs(A[i]);
    }
    sort(A.begin(),A.end());
    ll sum = 0;
    for(int i = 0; i< N; i++){
        if(i == 0){
            if(minC % 2 == 1){
                sum -= A[i];
            }else{
                sum += A[i];
            }
        }else{
            sum += A[i];
        }
    }
    cout << sum << endl;
}
