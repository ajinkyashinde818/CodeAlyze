#include<iostream>
using namespace std;


int main(){
	int n;
	cin >> n;
	int s[n];
	for(int i = 0;i < n;i++){
		cin >> s[i];
	}
	int count = 0;
	int mark_0 = 0;
	for(int i = 0;i < n;i++){
		if(s[i] == 0){
			mark_0 = 1;
			break;
		}else{
			if(s[i] < 0){
				count++;
			}
		}
	}
	for(int i = 0;i < n;i++){
		if(s[i] < 0){
			s[i] = -s[i];
		}
	}
	long long ans = 0;
	int t;
	for(int i = 0;i < n;i++){
		if(s[i] != 0){
			t = s[i];
			break;
		}
	}
	if(mark_0 != 0){
		for(int i = 0;i < n;i++){
			ans += s[i];
		}
	}else {
		for(int i = 0;i < n;i++){
			if(s[i] < t){
				t = s[i];
			}
			ans += s[i];
		}
		if(count % 2 != 0){
			ans = ans - 2*t;
		}
	}
	cout << ans;
	return 0;
}
