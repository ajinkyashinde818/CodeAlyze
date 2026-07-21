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

static LL P = 1000000007LL;


int A[52][52] = {0};
int B[52][52] = {0};

int N, M;

int ismatch(int u, int v){
	int ret = 1;
	if(u+M-1 >= N || v+M-1 >= N){
		return 0;
	}
	for(int i=0; i<M; i++){
		for(int j=0; j<M; j++){
			if(A[u+i][v+j] != B[i][j]){
				ret = 0;
				break;
			}
		}
		if(ret == 0){
			break;
		}
	}
	return ret;
}

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for(int i=0; i<N; i++){
		string a; cin >> a;
		for(int j=0; j<a.size(); j++){
			if(a[j] == '#'){
				A[i][j] = 0;
			}
			else{
				A[i][j] = 1;
			}
		}
	}
	for(int i=0; i<M; i++){
		string b; cin >> b;
		for(int j=0; j<b.size(); j++){
			if(b[j] == '#'){
				B[i][j] = 0;
			}
			else{
				B[i][j] = 1;
			}
		}
	}

	int ans = 0;
	for(int u=0; u<N; u++){
		for(int v=0; v<N; v++){
			ans = ismatch(u, v);
			if(ans == 1){
				break;
			}
		}
		if(ans == 1){
			break;
		}
	}

	if(ans == 1){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}
