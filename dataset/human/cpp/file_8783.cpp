#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n,m;
  	cin>>n>>m;
  	vector<vector<char>> a(n, vector<char>(n));
  	vector<vector<char>> b(m, vector<char>(m));
  
  	for(int y=0;y<n;y++){
    	for(int x=0;x<n;x++){
      		cin>>a.at(y).at(x);	
    	} 
    }
  	
  	for(int y=0;y<m;y++){
    	for(int x=0;x<m;x++){
      		cin>>b.at(y).at(x);	
    	} 
    }
  for (int l=0;l<n-m+1;l++){
  	for (int k=0;k<n-m+1;k++){
      bool TorF=true;
  		for (int i=0;i<m;i++){
  			for (int j=0;j<m;j++){
  				if(a.at(j+l).at(i+k)!=b.at(j).at(i)){
                	TorF=false;
                }
    		}
  		}  
      if(TorF){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
  }
      cout<<"No"<<endl;
}
