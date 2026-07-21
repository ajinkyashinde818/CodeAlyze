#include<iostream>
using namespace std;
typedef long long ll;
int main(){
	int n,i,count=0;
	ll sum=0,min=1000000000;
	cin >> n;
	for(i=0;i<n;i++){
		ll num;
		cin >> num;
		if(num<0)	count++;
		num = abs(num);
		sum += num;
		if(min>num)	min = num;
	}
	if(count%2==0)	cout << sum << endl;
	else				cout << sum - (2*min) << endl;
	return 0;
}
