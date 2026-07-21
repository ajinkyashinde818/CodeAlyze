#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;


int main(){
	/*input*/
//	long long n;
	int n ,r;
	cin >> n >> r;
//	int s[n];
//	for(int i = 0; i < n; i++){
//		cin >> s[i];
//	}

	/*calc*/
	int ans = 0;
	ans = 100*(10-n)+r;
//	for(int i = 0; i < n; i++){
//
//	}
	if(n >= 10)cout << r << endl;
	else{
		/*output*/
		cout<< ans <<endl;
	}
    return 0;
}
