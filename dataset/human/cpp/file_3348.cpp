#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <string>
#include <numeric>


using namespace std;


void a(){

    int A,B,T; cin >> A >> B >> T;

    int c = T/A;

    cout << c*B;

}

void b(){

    int N; cin >> N;

    vector<int> V(N);
    vector<int> C(N);
    for(int i = 0; i < N; i++){
        cin >> V[i];
    }
    for(int i = 0; i < N; i++){
        cin >> C[i];
    }
    int profit = 0;
    for(int i = 0; i < N; i++){
        if (V[i] - C[i] > 0){
            profit += V[i] - C[i];
        }
    }

    cout << profit;

}

int gcd(int a, int b){

    if(a < b) gcd(b, a);
    unsigned r;
    while ((r=a%b)) {
        a = b;
        b = r;
    }
    return b;

}

void c(){
    int N; cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    // left[i] == gcd of A[0,i]
    vector<int> left(N,A[0]);
    for (int i = 1; i < N; i++ ){
        left[i] = gcd(left[i - 1], A[i]);
    }

    vector<int> right(N, A[N-1]);
    for (int i = N -2; 0 <= i; i-- ){
        right[i] = gcd(A[i], right[i + 1]);
    }

    int max_gcd = 1;
    for(int i = 1; i < N - 1; i++){
        max_gcd = max( gcd(left[i -1], right[i+1]), max_gcd);
    }

    max_gcd = max( right[1], max_gcd);// i = 0
    max_gcd = max( left[N-2], max_gcd); // i = N -1

    cout << max_gcd;

}

void d(){

    int N; cin >> N;
    vector<long long>A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    // dp[0][i] == answer of A[i,N-1], dp[1][i] == answer of -A[i]::A[i+1; N-1]
    vector<vector<long long>> dp(2, vector<long long>(N));
    dp[0][N-1] = A[N-1];
    dp[1][N-1] = -A[N-1];
    for(int i = N -2; 0 <=i; i--){
        dp[0][i] = max( A[i] + dp[0][i+1],
                       -A[i] + dp[1][i+1]);
        dp[1][i] = max( -A[i] + dp[0][i+1],
                         A[i] + dp[1][i+1]);
    }

    cout << dp[0][0];
}

int main(){

    d();
    return 0;
}
