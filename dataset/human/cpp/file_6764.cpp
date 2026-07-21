#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <functional>
#include <queue>
#include <unordered_set>
#include <climits>
#include <set>
#include <list>
#include <cmath>
#include <map>
#include <random>
#include <time.h>

using namespace std;
typedef long long ll;

int main()
{
	int N;
	int A[200200];
	int B[200200];
	int ACount[200200];
	int BCount[200200];
	for(int i = 0; i < 200200; i++){
		ACount[i] = 0;
		BCount[i] = 0;
	}
	clock_t start = clock();
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i];
		ACount[A[i]]++;
	}
	for(int i = 0; i < N; i++){
		cin >> B[i];
		BCount[B[i]]++;
	}
	int over = 0;
	for(int i = 1; i <= N; i++){
		if(ACount[i] > 0 && BCount[i] > 0){
			over = max(over, ACount[i] + BCount[i]);
		}
	}
	if(over > N){
		cout << "No" << endl;
		return 0;
	}else{
		cout << "Yes" << endl;
	}
	reverse(B, B+N);
	int counter = 0;
	std::random_device rnd;
	while(static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1000.0 < 1920){
		for(int i = 0; i < N; i++){
			if(A[i] == B[i]){
				int next = rnd() % N;
				int temp = B[next];
				B[next] = B[i];
				B[i] = temp;
				if(A[next] == B[next]){
					int nextnext = rand() % N;
					int temp2 = B[nextnext];
					B[nextnext] = B[next];
					B[next] = temp2;
				}
			}
		}
	}
	
	for(int i = 0; i < N; i++){
		cout << B[i] << " ";
	}
	cout << endl;
	
	return 0;
}
