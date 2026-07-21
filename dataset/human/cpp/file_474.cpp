#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int R,G,B,N,ret=0; cin>>R>>G>>B>>N;
	for (int r=0; r*R<=N; r++) {
		for (int g=0; r*R+g*G<=N; g++) {
			int left=N-r*R-g*G;
			if(left%B==0)
				ret++;
		}
	}
	cout<<ret<<"\n";
	return 0;
}
