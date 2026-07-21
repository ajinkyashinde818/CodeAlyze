#include<bits/stdc++.h>
using namespace std;
int m;
vector<vector<int> > res;
int main(){
	scanf("%d",&m);
	int A = 1, B = 2;
	while(A < m){
		A += B;
		B ++;
	}
	if(A == m){
		puts("Yes");
		res.resize(B);
		res[0].push_back(1);
		res[1].push_back(1);
		int c = 1;
		for(int i=2; i<B; i++){
			for(int j=0; j<i; j++){
				++c;
				res[j].push_back(c);
				res[i].push_back(c);
			}
		}
		printf("%d\n",B);
		for(int i=0; i<B; i++){
			printf("%d",res[i].size());
			for(auto x : res[i])
				printf(" %d",x);
			puts("");
		}
	}else
		puts("No");
	return 0;
}
