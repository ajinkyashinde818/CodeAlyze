#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long> A(N);

    int minus_num = 0;
    long min_abs_value = 10000000009;
    for(int i = 0; i < N; i++){
	long v;
	cin >> v;
	A.at(i) = v;
	if(v < 0){
	    minus_num++;
	}
	min_abs_value = min(min_abs_value, abs(v));
    }

    long ans = 0;
    for(int i = 0; i < N; i++){
	ans += abs(A.at(i));
    }

    if(minus_num % 2 == 1){
	ans -= min_abs_value*2;
    }
    
    cout << ans << endl;
    
}
