#include <bits/stdc++.h>
using namespace std;

int p(int k){
	int ans = 1;
	for(int i = 0;i < k;i++)ans *= 10;
	return ans;
}

int main(){
	string str, x, y = "", z = "";
	int xn, yn = 0, zn = 0, f = 0;
	cin >> str;
	for(int i = 0;i < str.size();i++){
		if(str[i] == '.'){
			x = str.substr(0, i);
			xn = x.size();
		}
		if((i == str.size()-1 && !f) || (i+1 < str.size() && str[i+1] == '(')){
			y = str.substr(xn+1, i-xn);
			yn = y.size();
			f = 1;
		}
		if(str[i] == ')'){
			z = str.substr(xn+yn+2, i-xn-yn-2);
			zn = z.size();
		}
	}
	int a = p(zn+yn)-p(yn);
	int b = atoi(x.c_str())*p(yn+zn)+atoi(y.c_str())*p(zn)+atoi(z.c_str());
	b = b-b/p(zn);
	if(zn == 0){
		a = p(yn);
		b = atoi(x.c_str())*p(yn)+atoi(y.c_str());
	}
	int g = __gcd(a, b);
	a /= g;b /= g;
	printf("%d/%d\n", b, a);
	return 0;
}
