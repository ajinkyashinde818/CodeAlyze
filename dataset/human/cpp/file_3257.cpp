#include <bits/stdc++.h>
 #include <string> 
 #include <math.h>
 #include <bitset>
 using namespace std;
 
 int main(){
    long long i;
    long long N;
    long long A[120000];
    long long min;
    long long ans = 0;
    long long cnt = 0;

    cin >> N;
    for (i=0; i<N; i++){
        cin >> A[i];
    }

    min = abs(A[0]);

    for (i=0; i<N; i++){
        ans = ans + abs(A[i]);
        if (A[i] < 0)
            cnt++;
        if (min > abs(A[i]))
            min = abs(A[i]); 
    }

    if (cnt%2 != 0)
        ans = ans - min*2;

    cout << ans << endl;
        
    return 0;
 }
