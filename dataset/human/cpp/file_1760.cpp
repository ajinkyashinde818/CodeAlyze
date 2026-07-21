#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>

using namespace std;

bool mycomp1(pair<int,int> a, pair<int,int>b){
	return a.second>b.second;	
}

bool mycomp2(pair<int,int> a, pair<int,int>b){
	return a.first<b.first;
}

map<int, int> update;
int main(){
	int n,m;
	scanf("%d %d", &n, &m);

	for(int i=0;i<m;i++){
		int r;
		scanf("%d", &r);
		update[r] = i;
	}

	vector<pair<int,int> > requests;
	for(map<int, int>::iterator it=update.begin(); it!=update.end(); it++){
		requests.push_back(pair<int,int>(it->first, it->second));
	}

	std::sort(requests.begin(), requests.end(), mycomp1);

	for(int i=0;i<requests.size();i++){
		printf("%d\n", requests[i].first);
	}


	std::sort(requests.begin(), requests.end(), mycomp2);
	int now = 1;

	for(int i=0;i<requests.size();i++){
		int exclude = requests[i].first;
		for(int j=now;j<exclude;j++){
			printf("%d\n", j);
		}
		now = exclude+1;
	}
	for(int j=now;j<=n;j++){
		printf("%d\n", j);
	}

}
