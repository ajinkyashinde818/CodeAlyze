#include <iostream>
#include <limits.h>
#include <queue>
#include <algorithm>
#include <map>
#include <cstring>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int,int> P;
typedef long long int ll;

int N,M;
char A[51][51],B[51][51];


int main(){

	ios_base::sync_with_stdio(false);
	cin>>N>>M;	

	for(int i=0;i<N;i++)
		cin>>A[i];
	for(int i=0;i<M;i++)
		cin>>B[i];

	bool match = false, exist=false;


	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i+M-1>=N || j+M-1>=N) continue;
			match = true;
			for(int di=0;di<M;di++){
				for(int dj=0;dj<M;dj++){
					if(A[i+di][j+dj]!=B[di][dj]) match = false;
				}
			}
			if(match) exist = true;
		}
	}
	if(exist) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;
}
