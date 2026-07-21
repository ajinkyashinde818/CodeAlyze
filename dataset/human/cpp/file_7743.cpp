#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long int> CS(N+1, 0);
    for(int n=0; n<N; n++) {
        long long int a;
        cin >> a;
        CS[n+1] = a + CS[n];
    }
    
    long long int ans=1e9*3;
    for(int n=0; n<N-1; n++) {
        ans = min(ans, abs(CS[N]-2*CS[n+1]));
    }
    
    cout << ans << endl;


    return 0;
    
}
