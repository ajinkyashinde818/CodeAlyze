#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>

using namespace std;

int main(){

	int n,m;
	cin >> n >> m;
	string s[n],t[m],split[m];
	
	for(int i=0;i<n;i++){
		cin >> s[i];
	}
	
	for(int i=0;i<m;i++){
		cin >> t[i];
	}
	
	int cnt;
	for(int i=0;i<s[0].size()-m+1;i++){
		for(int j=0;j<n-m+1;j++){
			cnt=0;
			for(int x=0;x<m;x++){
				for(int y=0;y<m;y++){
					if(t[x][y]!=s[i+x][j+y])continue;
					if(t[x][y]==s[i+x][j+y])cnt++;
					if(cnt==m*m){
						cout << "Yes" << endl;
						return 0;
					}
				}
			}
		}
	}
	
	cout << "No" << endl;
	return 0;
	
}
