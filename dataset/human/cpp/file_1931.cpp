#include<bits/stdc++.h>
using namespace std;

int main(){
  unsigned int s;
  int q;
  cin >> q;
  for(int i = 0;i < q;++i){
    scanf("%x",&s);
    double temp = 0;
    double t = pow(0.5, 7);

    for(int i = 0;i < 31;++i){
      int b = s % 2;
      temp += (double)b * t;
      
      t *= 2;
      s /= 2;
    }

    if(s % 2){
      cout << "-";
    }

    int n = (int)temp;
    long long m = (long long)(n * pow(10.0 ,7.0));
    long long l = (long long)(temp * pow(10.0 ,7.0));
    if((double)n == temp){
      cout << n << ".0" << endl;
    }else{
      long long x = l - m;
      int tmp = x;
      string st = "";
      for(int j = 0;j < 7;j++){
	if(tmp == 0){
	  st += "0";
	}
	tmp /= 10;
      }
      while(x % 10 == 0){
	x /= 10;
      }
      cout << n << "." << st << x << endl;
    }

  }

  return 0;
}
