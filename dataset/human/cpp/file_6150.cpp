#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
typedef long long LL;
using Graph = vector<vector<int>>;

static long long INF = (1LL<<62);

LL N, C;
vector<pair<LL, LL>> XV;
map<LL, LL> M;
vector<LL> X, V;

LL P[100004] = {0};
LL Q[100004] = {0};
LL R[100004] = {0};
LL S[100004] = {0};

LL XP[100004] = {0};
LL XQ[100004] = {0};
LL XR[100004] = {0};
LL XS[100004] = {0};


int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> C;
	V.push_back(0);
	X.push_back(0);
	for(int i=0; i<N; i++){
		long long x, v;
		cin >> x >> v;
		X.push_back(x);
		V.push_back(v);
		XV.push_back(make_pair(x, v));
		M[x] = v;
	}
	X.push_back(C);

	LL eg = 0, w = 0;
	LL ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
	for(int i=1; i<=N; i++){
		eg += (V[i] - (X[i] - X[i-1]));
		w = eg - X[i];
		P[i] = eg;
		Q[i] = w;
		if(ans1 < eg){
			ans1 = eg;
		}
	}
	P[N+1] = P[N] - (C - X[N]);
	Q[N+1] = P[N+1] - C;

	eg = 0, w = 0;
	for(int i=N; i>=1; i--){
		eg += (V[i] - (X[i+1] - X[i]));
		w = eg - (C - X[i]);
		R[i] = eg;
		S[i] = w;
		if(ans2 < eg){
			ans2 = eg;
		}
	}
	R[N+1] = 0;
	S[N+1] = 0;

	for(int i=1; i<=N; i++){
		if(i == 1){
			XP[i] = P[i];
			XQ[i] = Q[i];
		}
		else{
			if(P[i] > XP[i-1]){
				XP[i] = P[i];
			}
			else{
				XP[i] = XP[i-1];
			}
			if(Q[i] > XQ[i-1]){
				XQ[i] = Q[i];
			}
			else{
				XQ[i] = XQ[i-1];
			}
		}
	}
	for(int i=N; i>=1; i--){
		if(i == N){
			XR[i] = R[i];
			XS[i] = S[i];
		}
		else{
			if(R[i] > XR[i+1]){
				XR[i] = R[i];
			}
			else{
				XR[i] = XR[i+1];
			}
			if(S[i] > XS[i+1]){
				XS[i] = S[i];
			}
			else{
				XS[i] = XS[i+1];
			}
		}
	}

	eg = 0;
	for(int i=1; i<=N; i++){
		eg = XQ[i] + XR[i+1];
		if(ans3 < eg){
			ans3 = eg;
		}
	}

	eg = 0;
	for(int i=1; i<=N; i++){
		eg = XS[i+1] + XP[i];
		if(ans4 < eg){
			ans4 = eg;
		}
	}
	LL ans = max(max(max(ans1, ans2), ans3), ans4);
	printf("%lld\n", ans);
	return 0;
}
