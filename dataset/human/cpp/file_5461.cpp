#include<iostream>
#include<stdio.h>
#include<cmath>
#include<string>
#include<string.h>
using namespace std;

int main(){
	int n, r;
	cin >> n >> r;
	if (n >= 10){
		cout << r << endl;
		return 0;
	}
	else{
		cout << r + (100 * (10 - n)) << endl;
	}
	return 0;
}
