#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
int N; 
cin >> N;
long long int A[314159], B[314159];  
for(int i = 0; i < N; i++){
cin >> A[i]; 
B[i+1] = B[i] + A[i]; 
}
long long int ans = abs(B[N] - 2 * B[1]); 
for(int i = 1; i < N; i++){
long long int K = abs(B[N] - 2 * B[i]);  
ans = min(ans, K); 
}
cout << ans << endl; 
}
