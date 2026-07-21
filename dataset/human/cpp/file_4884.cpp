/*alurquiza*/
//https://matcomgrader.com/problem/9623/dictionary-search/
//Segment Tree + binary search
#include <bits/stdc++.h>

using namespace::std;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// freopen("milkvisits.in","r",stdin);
	// freopen("milkvisits.out","w",stdout);

	int N,DR;
	cin >> N >> DR;

	cout << DR + (100) * (10 - min(N,10)) << '\n';


	return 0;
}

//g++ -std=c++11 -Wall DS.cpp -o main
