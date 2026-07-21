#include<iostream>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<math.h>
#include"boost/algorithm/string.hpp"
#include<array>

using namespace std;



int main(){
	/*Q3*/
	//std::array<string, 1000> str;


	/*Q2*/
	int r, g, b;//ハコの中の個数
	int n;
	int ret = 0;
	cin >> r >> g >> b >> n;
	int i_st = n / r, j_st = n / g, k_st = n / b;
	int i, j, k;
	int x, y, z;

	for (i = i_st; -1 < i; --i){
		x = r * i;
		for (j = j_st; -1 < j; --j){
			y = g * j;
		
			if (
				((n-x-y) > -1)
				&& ((n-x-y) % b == 0)
				){
				++ret;
			}
		}
	}

	cout << ret << endl;

	return 0;


	/*Q1*/
	/*
	int a, b;
	cin >> a >> b;

	cout << (int)(a - b + 1) << endl;
	
	return 0;
	*/
}
