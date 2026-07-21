#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	if (n == 1){
		printf("%d\n", m);
		return 0;
	}
	if (n == 2){
		printf("%d %d\n", m, m);
		return 0;
	}
	
	vector<int> res;
	
	if (n & 1){
		for (int i = 0; i < n / 2; i++){
			res.push_back(0);
		}
		for (int i = 0; i < n - (n / 2); i++){
			res.push_back(m);
		}
	}
	else {
		for (int i = 0; i < n / 2 - 1; i++){
			res.push_back(0);
		}
		for (int i = 0; i < n / 2 + 1; i++){
			res.push_back(m);
		}
	}
	
	for (int i = 0; i < n; i++){
		if (i) printf(" ");
		printf("%d", res[i]);
	}
	puts("");
}
