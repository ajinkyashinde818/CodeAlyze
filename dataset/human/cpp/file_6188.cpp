#include<bits/stdc++.h>
using namespace std;

long long N, C;
vector<pair<long long, long long> >xv;

long long goright[100005];
long long goleft[100005];
long long backright[100005];
long long backleft[100005];

int main(){
	cin >> N >> C;
	for(long long i = 0; i < N; i++){
		long long x, v;
		cin >> x >> v;
		xv.push_back(make_pair(x, v));
	}
	sort(xv.begin(), xv.end());

	long long curmaxi = 0;
	long long curbackmaxi = 0;
	long long curadd = 0;
	long long cursub = 0;
	for(long long i = 0; i < N; i++){
		curadd += xv[i].second;
		cursub = xv[i].first;
		curmaxi = max(curmaxi, curadd - cursub);
		curbackmaxi = max(curbackmaxi, curadd - 2*cursub);
		goright[i] = curmaxi;
		backright[i] = curbackmaxi;
	}

	curmaxi = 0;
	curbackmaxi = 0;
	curadd = 0;
	cursub = 0;
	for(long long i = N-1; i >=0 ; i--){
		curadd += xv[i].second;
		cursub = C - xv[i].first;
		curmaxi = max(curmaxi, curadd - cursub);
		curbackmaxi = max(curbackmaxi, curadd - 2*cursub);
		goleft[i] = curmaxi;
		backleft[i] = curbackmaxi;
	}


	//for(long long i = 0; i < N; i++){
	//	cout << "goright[" << i << "]=" << goright[i] << endl;
	//	cout << "backright[" << i << "]=" << backright[i] << endl;
	//}

	//for(long long i = 0; i < N; i++){
	//	cout << "goleft[" << i << "]=" << goleft[i] << endl;
	//	cout << "backleft[" << i << "]=" << backleft[i] << endl;
	//}


	long long ans = max(goright[N-1], goleft[0]);

	//go right and left
	for(long long i = 0; i < N-1; i++){
		ans = max(ans, goright[i] + backleft[i+1]);
	}

	//go left and right
	for(long long i = 1; i < N; i++){
		ans = max(ans, goleft[i] + backright[i-1]);
	}

	cout << ans << endl;
}
