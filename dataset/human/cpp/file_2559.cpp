//g++ -std=c++14 test.cpp -o test.out
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
using namespace std;

#define LL long long int

int N;
LL A[100000];

LL ans = 0;

void solve(){
	//負の数が偶数個なら数列を全部正の数にできるのでその和が答え
	//奇数個なら絶対値最小の項にマイナスを押しつければOK
	int negative = 0;//負の数が何個あるかを記録
	for(int i=0;i<N;i++){
		if(A[i]<0) negative++;
	}
	//負の数が偶数個なら数列を全部正の数にできるのでその和が答え
	if(negative%2==0){
		for(int i=0;i<N;i++) ans += abs(A[i]);
		return;
	}
	//奇数個なら絶対値最小の項にマイナスを押しつければOK
	int absmin_index = 0;
	for(int i=0;i<N;i++){
		if(abs(A[i])<abs(A[absmin_index])) absmin_index = i;
		if(A[i]==0) break;
	}
	for(int i=0;i<N;i++){
		if(i==absmin_index) ans -= abs(A[i]);
		else ans += abs(A[i]);
	}
}
 
int main(){
	cin >> N;
	for(int i=0;i<N;i++) cin >> A[i];
 
	solve();

	cout << ans << endl;
	return 0;
}
