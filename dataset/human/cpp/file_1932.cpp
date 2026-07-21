#include<iostream>
#include<algorithm>
#include<iomanip>

std::string to2(char c16){
	if(c16 == '0')return "0000";
	if(c16 == '1')return "0001";
	if(c16 == '2')return "0010";
	if(c16 == '3')return "0011";
	if(c16 == '4')return "0100";
	if(c16 == '5')return "0101";
	if(c16 == '6')return "0110";
	if(c16 == '7')return "0111";
	if(c16 == '8')return "1000";
	if(c16 == '9')return "1001";
	if(c16 == 'a')return "1010";
	if(c16 == 'b')return "1011";
	if(c16 == 'c')return "1100";
	if(c16 == 'd')return "1101";
	if(c16 == 'e')return "1110";
	if(c16 == 'f')return "1111";
}

int main(){
	int n;
	std::cin >> n;
	for(;n--;){
		std::string s16, s2 = "";
		std::cin >> s16;
		for(int i=0;i<s16.size();i++){
			s2 += to2(s16[i]);
		}
		std::reverse(s2.begin(), s2.end());
		long double res = 0, _d = 1;
		for(int i=7;i<=30;i++){
			res += (s2[i] - '0') * _d;
			_d *= 2.0;
		}
		_d = 0.5;
		int st = 1;
		for(int i=6;i>=0;i--){
			if(s2[i] == '1'){
				res += _d;
				st = 7-i;
			}
			_d /= 2.0;
		}
		res *= (s2[31]-'0'==1)?(-1):1;
		std::cout.setf(std::ios_base::fixed,std::ios_base::floatfield);
		std::cout << std::setprecision(st) << res << std::endl;
	}
}
