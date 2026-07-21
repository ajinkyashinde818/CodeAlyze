/*
 * wafuIroha.cpp
 *
 *  Created on: 2020/02/23
 *      Author: black
 */
#include <iostream>
#include <string>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;

	string *a = new string[n];
	string *b = new string[m];

	for (int i = 0; i<n; ++i){
		cin >> a[i];
	}

	for (int i = 0; i<m; ++i){
		cin >> b[i];
	}

	int count = 0;

	for(int i = 0; i < n-m+1; ++i){
		count = 0;
		for (int j = 0; j < n; ++j){
			if (a[j].substr(i, m) == b[count]){
				count++;
				if (count == m){
					cout << "Yes" << endl;
					return 0;
				}
			}
			else{
				count = 0;
			}
		}

	}

	cout << "No" << endl;

	return 0;
}
