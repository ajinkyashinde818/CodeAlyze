#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
typedef long long int ll;

using namespace std;

ll calc(ll x,ll y){
	if(y == 0){
		return x;
	}else{
		return calc(y,x%y);
	}
}

int main(){

	char buf[10];
	ll base = 0,cicle_left = 0,cicle = 0,base_len = 0,cicle_left_len = 0,cicle_len = 0;
	ll ans_left,ans_right,common;
	bool FLG = false;
	int index;

	scanf("%s",buf);

	for(index = 0; buf[index] != '.';index++){
		base = 10*base + buf[index] - '0';
		base_len++;
	}

	index++;

	for(;buf[index] != '\0' && buf[index] != '(';index++){
		cicle_left = 10*cicle_left + buf[index] - '0';
		cicle_left_len++;
	}

	if(buf[index] == '('){
		FLG = true;
		index++;
		for(;buf[index] != ')';index++){
			cicle = 10*cicle + buf[index] - '0';
			cicle_len++;
		}
	}

	if(FLG){
		ans_left = base*pow(10,cicle_left_len+cicle_len)
				+cicle_left*pow(10,cicle_len)+cicle;

		ans_left -= base*pow(10,cicle_left_len)+cicle_left;

		ans_right = pow(10,cicle_left_len+cicle_len) - pow(10,cicle_left_len);

		if(ans_left > ans_right){
			common = calc(ans_left,ans_right);
		}else{
			common = calc(ans_right,ans_left);
		}

		printf("%lld/%lld\n",ans_left/common,ans_right/common);

	}else{
		ans_left = base*pow(10,cicle_left_len)+cicle_left;
		ans_right = pow(10,cicle_left_len);
		if(ans_left > ans_right){
			common = calc(ans_left,ans_right);
		}else{
			common = calc(ans_right,ans_left);
		}
		printf("%lld/%lld\n",ans_left/common,ans_right/common);
	}

	return 0;
}
