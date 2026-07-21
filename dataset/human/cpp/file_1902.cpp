#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<cstdio>
#include<sstream>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double EPS=1e-8;
const int inf=1e9;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
int main(){
	int n;
	cin>>n;
	while(n--){
		string s="";
		rep(i,8){
			string q="";
			char c;cin>>c;
			int t;
			if(isalpha(c))t=c-'a'+10;
			else t=c-'0';
			rep(j,4){
				q=(char)(t%2+'0')+q;
				t/=2;
			}
			s+=q;
		}
		int out=0;
		int t=1;
		for(int i=24;i>0;i--){
			out+=t*(s[i]-'0');
			t*=2;
		}
		if(s[0]=='1')cout<<"-";
		cout<<out<<".";
//		
		t=10000000; 
		out=0;
		for(int i=25;i<32;i++){
			t/=2;
			out+=t*(s[i]-'0');
		}
		if(out==0)cout<<0<<endl;
		else{
			int t=7;
			while(t>1&&out%10==0){out/=10;t--;}
			//cout<<out<<endl;
			printf("%0*d\n",t,out);
		}

	}
}
