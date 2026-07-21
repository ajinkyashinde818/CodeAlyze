#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<sstream>

using namespace std;
typedef long long ll;
typedef long double ld;
int n;
ll k;
string num;

void et(){
	int res1=0;
	ld res2=0.0,res3;
	int bit=0;
	int pp=1;
	bool f=false;
	ld k2=1;
	for(int i=0;i<8;i++){
		if(num[i]>='0' && num[i]<='9')bit=num[i]-'0';
		if(num[i]>='a' && num[i]<='f')bit=num[i]-'a'+10;
		for(int j=0;j<4;j++){
			if(i==0 && j==0){
				if((bit >> (3-j)) & 1)pp=-1;
				else pp=1;
			}else{
				if((bit >> (3-j)) & 1){
					if(i<=5 || (i==6 && j==0)){
						res1+=k*pp;
					}
					else{
						res2+=k2;
					}
				}
			}
			if(k>0)k/=2;
			if(i>=6)k2/=2;
		}
	}
	if(res1==0 && pp==-1)cout << "-";
	cout << res1 << ".";
	if(res2==0.0)cout << "0";
	else{
		bool f=false;
		while(1){
			res2*=10;
			int res22=(int)res2/1;
			if(res2==0.0)break;
			if(res22!=0)f=true;
			cout << res22;
			res2=(ld)res2-res22;
		}
	}
	cout << endl;
}

int main(void){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> num;
		k=1;
		for(int j=0;j<24;j++)k*=2;
		et();
	}
	return 0;
}
