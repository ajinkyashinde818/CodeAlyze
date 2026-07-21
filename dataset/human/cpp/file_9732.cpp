#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

#include <sstream>
#include <istream>

using namespace std;

//typedef pair<int,int> P;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	char s[100001];
	cin >> s;

	int num[26];
	for(int i=0;i<26;i++) num[i] = 1;

	for(int i=0;i<n;i++){
		num[s[i]-'a']++;
	}

	long long ans = 1;
	for(int i=0;i<26;i++){
		ans *= num[i];
		ans %= 1000000007;
	}
	ans--;

	cout << ans << endl;

	return 0;
}
