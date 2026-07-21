#include <stdio.h>
#include <bits/stdc++.h>

typedef long long  LL;

using namespace std;

int main(){
	
	LL N,C;
	cin >> N >> C;
	
	vector<LL> vecl(N+1);
	vecl.at(0) = 0;
	vector<LL> lmax(N+1,0);
	vector<LL> lini(N+1,0);
	
	vector<LL> vecr(N+1);
	vecr.at(0) = 0;
	vector<LL> rmax(N+1,0);
	vector<LL> rini(N+1,0);
	
	vector<vector<LL>> vec = vector<vector<LL>>(N+2, vector<LL>(2,0));
	
	vec.at(N+1).at(0) = C;
	vec.at(N+1).at(1) = 0;
	
	for(LL i=1; i<N+1; i++){
		cin >> vec.at(i).at(0) >> vec.at(i).at(1);
	}
	
	for(LL i=1; i<N+1; i++){
		vecl.at(i) = vecl.at(i-1) + vec.at(i).at(1) - (vec.at(i).at(0) - vec.at(i-1).at(0)) ;
		if(lmax.at(i-1) < vecl.at(i)) lmax.at(i) = vecl.at(i);
		else lmax.at(i) = lmax.at(i-1);
		if(lini.at(i-1) < vecl.at(i) - vec.at(i).at(0)) lini.at(i) = vecl.at(i) - vec.at(i).at(0);
		else lini.at(i) = lini.at(i-1);
		
	}
	
	for(int i=1; i<N+1; i++){
		vecr.at(i) = vecr.at(i-1) + vec.at(N+1-i).at(1) - (C - vec.at(N+1-i).at(0)) + (C - vec.at(N+2-i).at(0));
		if(rmax.at(i-1) < vecr.at(i)) rmax.at(i) = vecr.at(i);
		else rmax.at(i) = rmax.at(i-1);
		if(rini.at(i-1) < vecr.at(i) - (C - vec.at(N+1-i).at(0))) rini.at(i) = vecr.at(i) - (C - vec.at(N+1-i).at(0));
		else rini.at(i) = rini.at(i-1);
		
		
	}
	
	
	
	LL res = 0;
	
	//cout << "rmax = " << rmax << " rini = " << rini << endl;
	//cout << "lmax = " << lmax << " lini = " << lini << endl;
	
	
	
	/*
	for(LL i=0; i<N+1; i++){
		cout<< " i = " << i<< endl;
		cout<< "lmax = " << lmax.at(i)<< " lini = " << lini.at(i) << endl;
		cout<< "rmax = " << rmax.at(i)<< " rini = " << rini.at(i) << endl;
		
	}*/
		
	
	
	for(LL i=0; i<N+1; i++){
		if (res <= rmax.at(i)) res = rmax.at(i);
		if(res <= rini.at(i) + lmax.at(N-i))res = rini.at(i) + lmax.at(N-i);
		if(res <= lini.at(i) + rmax.at(N-i))res = lini.at(i) + rmax.at(N-i);
		if(res <= lmax.at(i))res = lmax.at(i);
		
	}
	cout << res << endl;
	
}
