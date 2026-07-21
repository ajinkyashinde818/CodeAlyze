#include<iostream>
#include<string.h>
#include<queue>
#include<map>
#include<vector>
#include <cstdlib>
#include<algorithm>
#include <cstdio>
#include <cctype>
using namespace std;
const long long INF=10000000000000LL;
typedef long long ll;
typedef pair<ll,ll> P;
ll N,M,K=1,C;
ll A,B,W;
ll T,a,b;
double v[55],D[55];
ll ans=0;
bool h,o;
//bool D[100005];
ll S[50][50]={};
char str1[55][55],str2[55][55];
map<string,int> m;

int main(){
	cin>>N>>M;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>str1[i][j];
		}
	}
	for(int i=0;i<M;++i){
		for(int j=0;j<M;++j){
			cin>>str2[i][j];
		}
	}
	o=0;
	for(int i=0;i<N-M+1;++i){
		for(int j=0;j<N-M+1;++j){
			h=0;
			for(int k=0;k<M;++k){
				for(int l=0;l<M;++l){
					if(str1[i+k][j+l]!=str2[k][l]){
						h=true;
						break;
					}
				}
			}
			if(!h){
				cout<<"Yes"<<endl;
				o=true;
				break;
			}
		}
		if(o)break;
	}
	if(!o)cout<<"No"<<endl;
	return 0;
}
