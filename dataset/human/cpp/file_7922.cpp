#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;

/*
 * 問題文
 *
 * すぬけくんとアライグマは N 枚のカードの山を作りました。
 * カードの山の上から i 番目のカードには整数 aiが書かれています。
 * N枚のカードを分け合うことにしました。 
 * すぬけくんがカードの山の上から何枚かのカードを取ったあと、アライグマは残ったカード全てを取ります。 
 * このとき、すぬけくんもアライグマも 1枚以上のカードを取る必要があります。
 * すぬけくんとアライグマが持っているカードに書かれた数の総和をそれぞれ x,yとして、|x - y| を最小化したいです。 
 * |x - y| としてありうる値の最小値を求めなさい。

 *  黒の面に0、白の面に1が書かれた N個のオセロの駒が、どの駒も黒の面が上を向くように一列に並べられています。
 *  その後、ある区間にある駒を全て裏返すという操作が Q 回だけ行なわれました。 
 *  具体的には i 回目の操作においては、左から li 番目の駒から ri番目の駒までの駒全てが裏返されました。
 *  最終的な盤面を求めてください。
 *
 */

long long N;
vector<long long> S;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N ;
	for(int i=0; i<N; i++){
		long long u;
		cin >> u;
		if(i == 0){
			S.push_back(u);
		}
		else{
			S.push_back(S[i - 1] + u); //累積和
		}
	}

	long long ans = (1LL<<61);
	for(int i=0; i<N - 1; i++){
		long long a = S[i];
		long long b = S[N - 1] - S[i];
		long long c = abs(a - b);
		if(ans > c){
			ans = c;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
