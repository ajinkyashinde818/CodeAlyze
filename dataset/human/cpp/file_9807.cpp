#include<iostream>
#include<algorithm>
#include<map>
using lint=int64_t;
using namespace std;
const lint mod=1e9+7;
int main()
{
	int N;
	string s;
	map<char,lint> m;

	cin >> N >> s;
	for(int i=0;i<s.size();i++)
	{
		m[s[i]]++;
	}

	lint ans=1;
	for(auto&& i:m)
	{
		ans*=(i.second+1);
		ans%=mod;
	}

	ans--;
	cout << ans << endl;
	return 0;
}
