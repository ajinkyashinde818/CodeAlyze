#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main(){
	string data[7]={
		/*小数7桁*/
		"0078125",
		"0156250",
		"0312500",
		"0625000",
		"1250000",
		"2500000",
		"5000000",
	};
	int bit[16][4]={
		{0,0,0,0},
		{0,0,0,1},
		{0,0,1,0},
		{0,0,1,1},
		{0,1,0,0},
		{0,1,0,1},
		{0,1,1,0},
		{0,1,1,1},
		{1,0,0,0},
		{1,0,0,1},
		{1,0,1,0},
		{1,0,1,1},
		{1,1,0,0},
		{1,1,0,1},
		{1,1,1,0},
		{1,1,1,1}};
	long long n;
	int Q;
	string in;
	int s[8];
	int s2[32];
	int carry;
	int nn;
	string a,b;
	bool f;

	cin>>Q;
	for(int i=0;i<Q;i++){
		cin>>in;
		for(int j=0;j<in.size();j++){
			if(in[j]>='0'&&in[j]<='9') s[j]=in[j]-'0';
			else  s[j]=in[j]-'a'+10;
		}
		for(int j=0;j<8;j++){
			for(int k=0;k<4;k++){
				s2[k+j*4]=bit[s[j]][k];
			}
		}
		n=0;
		for(int j=1;j<=24;j++){
			if(s2[j]==1) n+=pow(2,24-j);
		}
		a="";
		carry=0;
		for(int j=6;j>=0;j--){
			nn=carry;
			for(int k=25;k<32;k++){
				if(s2[k]==1) nn+=data[31-k][j]-'0';
			}
			carry=nn/10;
			b=(nn%10+'0');
			a=b+a;
		}
		if(s2[0]==1) cout<<"-";
		cout<<n;

		cout<<".";

		f=false;
		for(int j=0;j<7;j++){
			if(a[j]!='0') f=true;
		}
		if(f){
			b="";
			f=false;
			for(int j=6;j>=0;j--){
				if(a[j]!='0'||f){
					b=a[j]+b;
					f=true;
				}
			}
			cout<<b;
		}
		else cout<<"0";

		cout<<endl;
	}
	
}
