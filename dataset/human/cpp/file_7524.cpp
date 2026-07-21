#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int dif=LLONG_MAX,sum=0,sum_arai=0;
	int N;
	cin >> N;
	int a[N];
	for(int i=0;i<N;i++){
		cin >> a[i];
		sum_arai+=a[i];
	}
	sum+=a[0],sum_arai-=a[0];
	if(abs(sum-sum_arai)<dif){
		dif=abs(sum-sum_arai);
	}
	for(int i=1;i<N-1;i++){
		sum+=a[i];
		sum_arai-=a[i];
		if(abs(sum-sum_arai)<dif){
			dif=abs(sum-sum_arai);
		}
	}
	cout << dif << endl;
	return 0;
}
