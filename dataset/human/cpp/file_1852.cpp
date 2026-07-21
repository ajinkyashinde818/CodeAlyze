#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;


int main(){

	int N,M,tmp;
	scanf("%d %d",&N,&M);

	int* table = new int[N+M+100];
	int* locationTable = new int[N+1];

	for(int i = N-1; i >= 0; i--){
		table[i] = N-i;
		locationTable[table[i]] = i;
	}

	int index = N;

	for(int i = 0; i < M; i++){
		scanf("%d",&tmp);
		table[locationTable[tmp]] = -1;
		locationTable[tmp] = index;
		table[index++] = tmp;
	}

	for(int i = index-1; i >= 0; i--){
		if(table[i] != -1)printf("%d\n",table[i]);
	}

	return 0;
}
