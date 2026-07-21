#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> A(N),B(N);
	for(auto &i:A)cin >> i;
	for(auto &i:B)cin >> i;
	for(auto &i:A)i--;
	for(auto &i:B)i--;
	
	vector<int> Acount(N,0),Bcount(N,0);
	for(auto &i:A)Acount[i]++;
	for(auto &i:B)Bcount[i]++;
	
	int maxsum=0,maxi;
	for(int i=0;i<N;i++){
		if(maxsum<Acount[i]+Bcount[i]){
			maxsum=Acount[i]+Bcount[i];
			maxi=i;
		}
	}
	if(maxsum>N){
		cout << "No" << endl;
		return 0;
	}
	
	cout << "Yes" << endl;
	int diff=-N;
	for(int i=0;i<N;i++){
		if(Acount[i]+Bcount[i]==0)continue;
		
		int Apos=(int)(lower_bound(A.begin(),A.end(),i)-A.begin());
		int Bpos=(int)(lower_bound(B.begin(),B.end(),i)-B.begin());
		
		diff=max(diff,Apos-Bpos+Acount[i]);
	}
	
	for(int i=0;i<N;i++)printf("%d%c",B[(i-diff+N)%N]+1,((i==N-1)?('\n'):(' ')));
	return 0;
}
