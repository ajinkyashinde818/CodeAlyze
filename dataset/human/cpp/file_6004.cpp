#include <bits/stdc++.h>

using namespace std;

long long tokei[111111];
long long tokeiRev[111111];
long long han[111111];
long long hanRev[111111];

int main()
{
	long long n,c;cin >> n >> c;
	vector<pair<long long,long long>> susi;
	vector<pair<long long,long long>> reversed_susi;
	
	for(int i = 0;i < n;i++){
		long long x,v;
		cin >> x >> v;
		susi.push_back(make_pair(x,v));
		reversed_susi.push_back(make_pair(c-x,v));
	}
	
	sort(susi.begin(),susi.end());
	sort(reversed_susi.begin(),reversed_susi.end());
	
	//for(int i = 0;i < n;i++)cout << "(" << susi[i].first << ',' << susi[i].second << ")" << ' ';cout << endl;
	//for(int i = 0;i < n;i++)cout << "(" << reversed_susi[i].first << ',' << reversed_susi[i].second << ")" << ' ';cout << endl;
	
	long long sum = 0;
	long long hansum = 0;
	for(int i = 1;i <= n;i++){
		sum += susi[i-1].second;
		hansum += reversed_susi[i-1].second;
		tokei[i] = max(tokei[i-1],sum - susi[i-1].first);
		tokeiRev[i] = max(tokeiRev[i-1],sum - 2 * susi[i-1].first);
		han[i] = max(han[i-1],hansum - reversed_susi[i-1].first);
		hanRev[i] = max(hanRev[i-1],hansum - 2 * reversed_susi[i-1].first);
	}
	
	//for(int i = 0;i <= n;i++)cout << tokei[i] << ' ';cout << endl;
	//for(int i = 0;i <= n;i++)cout << tokeiRev[i] << ' ';cout << endl;
	//for(int i = 0;i <= n;i++)cout << han[i] << ' ';cout << endl;
	//for(int i = 0;i <= n;i++)cout << hanRev[i] << ' ';cout << endl;
	
	long long answer = 0;
	
	for(int i = 0;i <= n;i++){
		answer = max(answer,tokei[i] + hanRev[n-i]);
		answer = max(answer,tokeiRev[i] + han[n-i]);
	}
	
	cout << answer << endl;
		
	
	return 0;
}
