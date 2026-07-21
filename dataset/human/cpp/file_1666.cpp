#include <iostream>
#include<vector>

using namespace std;

int main() {
	int n;cin>>n;
	int num=1;
	while(num*num<1+8*n){
		num++;
	}
	if(num*num!=1+8*n){
		cout<<"No"<<endl;
		return 0;
	}
	if(num%2==0){
		cout<<"No"<<endl;
		return 0;
	}
	int sn=(-1+num)/2;
	int k=sn+1;
	vector<vector<int>> s(k,vector<int>(sn));
	int it=0;
	int jt=0;
	num=1;
	while(num<=n){
		for(int j=jt;j<sn;j++){
			s[it][j]=num+j-jt;
		}
		for(int i=it+1;i<k;i++){
			s[i][jt]=num+i-it-1;
		}
		num+=sn-jt;
		jt++;
		it++;
	}
	cout<<"Yes"<<endl;
	cout<<k<<endl;
	for(int i=0;i<k;i++){
		cout<<sn<<' ';
		for(int j=0;j<sn;j++){
			cout<<s[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
