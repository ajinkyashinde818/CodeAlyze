#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
  	cin >> n >> m;
  	char a[n][n],b[m][m];
  	for (int i=0;i<n;i++){
      	for (int j=0;j<n;j++){
    	cin >> a[i][j];
        }
    }
  	for (int i=0;i<m;i++){
      	for (int j=0;j<m;j++){
    	cin >> b[i][j];
        }
    }
  	bool x=false;
  	for (int i=0;i<=n-m;i++){
      	for (int l=0;l<=n-m;l++){
    		int df=0;
    		for (int j=0;j<m;j++){
        		for (int k=0;k<m;k++){
            		if (a[j+i][k+l]!=b[j][k]) df++;
           		}
        	}
    		if (df==0) x=true;
        }
    }
  	if (x==true) cout << "Yes" <<endl;
  	else cout << "No" <<endl;
}
