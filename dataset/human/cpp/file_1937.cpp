#include <iostream>
#include <string>
using namespace std;

string to_bit(string s){
	string ret = "";
	for(int i = 0;i < 8;i++){
		int t;
		if(s[i] <= '9' && s[i] >= '0') t = s[i] - '0';
		else t = s[i] - 'a' + 10;
		for(int j = 0;j < 4;j++){
			if(t >> (3 - j) & 1) ret += to_string(1);
			else ret += to_string(0);
		}
	}
	return ret;
}

int main(){
	int q;
	cin >> q;
	for(int i = 0;i < q;i++){
		long double ans = 0.0;
		string s;
		cin >> s;
		s = to_bit(s);
		if(s[0] == '1') cout << "-";
		for(int j = 1;j < 25;j++){
			ans *= 2.0;
			if(s[j] == '1') ans += 1.0;
		}
		long double add = 0.5;
		for(int j = 25;j < 32;j++){
			if(s[j] == '1') ans += add;
			add /= 2.0;
		}
		cout << (int)ans << ".";
		do{
			ans -= (int)ans;
			ans *= 10.0;
			cout << (int)ans;
		}while((ans - (int)ans) > 1e-9);
		cout << endl;
	}
	return 0;
}
