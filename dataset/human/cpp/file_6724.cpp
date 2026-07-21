#include<bits/stdc++.h>
using namespace std;

int gcd(int y, int x){
	if(y<x)swap(y,x);
	
	if(x==0)return y;
	
	return gcd(x, y%x);
}

int main(){
	string s;	cin>>s;
	string x="";
	string loop="";

	int pos=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='('){
			pos=i;
			break;
		}else{
			x.push_back(s[i]);
		}
	}

	if(pos){
		for(int i=pos+1; i+1<s.length(); i++){
			loop.push_back(s[i]);
		}
	}

	if(x[x.length()-1]=='.')x.pop_back();
	//cout<<x<<endl;

	// {{{ A/B (循環してない部分)を生成
	int A=0,B=1;
	int m=0;
	bool flag=false;
	for(int i=0;i<x.length();i++){
		if(x[i]=='.'){
			flag=true;
			continue;
		}
		A=A*10+(x[i]-'0');
		if(flag){
			m++;
			B*=10;
		}
	}
	//printf("%d / %d\n",A,B);
	// }}}

	int C=0, D=1;
	if(loop.length()){
		//cout<<loop<<endl;
		//cout<<loop.length()<<endl;
		C=stoi(loop);
		D=pow(10,loop.length())-1;
		D*=pow(10,m);
		//printf("%d / %d\n",C,D);
	}

	// {{{ A/B + C/D

		// -> E/F

		int E=A*D + C*B;
		int F=D*B;
		int tmp=gcd(E,F);
		//printf("ans: %d / %d\n",E,F);
		//printf("[%d:%d]=%d\n",E,F,tmp);
		E/=tmp;	F/=tmp;
	// }}}

	printf("%d/%d\n",E,F);
	return 0;
}
