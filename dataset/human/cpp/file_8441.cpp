#include<iostream>
#include<vector>
using namespace std ;

int main(){
	using vc = vector<char> ;
	using vcc = vector<vc> ;
	int n,m ;
	cin >> n >> m ;
	vcc a(n,vc(n)) ;
	vcc b(m,vc(m)) ;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> a.at(i).at(j) ;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cin >> b.at(i).at(j) ;
		}
	}
	for(int i=0;i<n-m+1;i++){
		for(int j=0;j<n-m+1;j++){
			bool ok = true ;
			for(int k=0;k<m;k++){
				for(int l=0;l<m;l++){
					if(a.at(k+i).at(l+j)!=b.at(k).at(l)) ok =false ;
				}
			}
			if(ok){
				cout << "Yes" << endl ;
				return 0 ;
			}
		}
	}
	cout << "No" << endl ;
}
