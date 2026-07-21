// D - Flipping Signs
#include <bits/stdc++.h>
using namespace std;

int main(){
	int N; cin>>N;

	long long sum = 0, minus_count = 0, mini = LLONG_MAX;

	while(N--){
		long long a; cin>>a;
		if(a<0){ a = -a; ++minus_count; }
		mini = min(mini, a);
		sum += a;
	}

	sum -= minus_count%2 * mini*2;
	cout<< sum <<endl;
}
