#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n,chara[26],i;
	double r=1;
	string s;
	cin>>n;
	cin>>s;
	for(i=0;i<26;i++) chara[i]=0;
	for(i=0;i<n;i++){
		chara[s[i]-'a']++;
	}
	for(i=0;i<26;i++){
		r=r*(chara[i]+1);
		r=fmod(r,pow(10,9)+7);
	}
	r--;
	cout<<(int)r<<endl;
	return 0;
}
