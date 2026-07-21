#include<bits/stdc++.h>
using namespace std;
using ll = long long ;

int main(){
	vector<ll> vet,vet1;
	ll n,val;
	cin >> n;
	ll soma =0 ;
	for(int i= 0;i<n;i++){
		cin >> val;
		if(val < 0)
			vet1.push_back(abs(val));
		else{
			vet.push_back(abs(val));
			soma += val;
		}
	}
	
	int sz = vet1.size()/2;
	int sz1 = vet1.size();
	
	sort(vet1.begin(),vet1.end());
	sort(vet.begin(),vet.end());
	for(int i = sz1-1;i>=sz1-sz*2;i--){
		soma += vet1.back();
		vet1.pop_back();
	}
	
	if((vet1.size() & 1) and vet.size()){
		if(vet[0] < vet1[0]){
			
			soma +=vet1[0];
			soma -=2*vet[0];
		}else
			soma-=vet1[0];
	}else if((vet1.size()&1))
		soma -= vet1[0];
	cout<<soma<<endl;

}
