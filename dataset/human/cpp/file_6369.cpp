#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const unsigned long long MOD = 1e9+7;

int main()
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	vector<int> v(2*n);

	if(str[0] == 'B')
		v[0] = 0;
	else
		v[0] = 1;

	for(int i=1;i<2*n;i++){
		if(str[i] != str[i-1]){
			v[i] = v[i-1];
		}else{
			v[i] = 1 - v[i-1];
		}
	}

	unsigned long long ans = 1;
	unsigned long long cnt_0 = 0;
	for(int i=0;i<2*n;i++){
		if(v[i] == 0){
			cnt_0++;
		}else{
			ans = ans*cnt_0 % MOD;
			cnt_0--;
		}
	}

	for(unsigned long long i=1;i<=n;i++){
		ans = (ans * i) % MOD;
	}

	if(cnt_0 != 0)
		cout << 0 << endl;
	else
		cout << ans << endl;
}
