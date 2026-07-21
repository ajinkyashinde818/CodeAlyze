#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int main(){
	int N;
	scanf("%d",&N);
	
	for(int k = 1 ; ; k ++){
		if(k*(k-1) > N*2){
			puts("No");
			return 0;
		}
		if(k*(k-1) < N*2)continue;
		puts("Yes");
		printf("%d\n",k);
		vector<int> vec[1000];
		int cnt = 1;
		for(int i = 1 ; i <= k ; i ++){
			for(int j = i+1 ; j <= k ; j ++){
				vec[i].push_back(cnt);
				vec[j].push_back(cnt);
				cnt ++;
			}
		}
		for(int i = 1 ; i <= k ; i ++){
			printf("%d",k-1);
			for(int j = 0 ; j < k-1 ; j ++){
				printf(" %d",vec[i][j]);
			}
			puts("");
		}
		return 0;
	}
}
