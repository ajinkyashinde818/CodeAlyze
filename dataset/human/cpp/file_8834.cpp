#include<bits/stdc++.h>
using namespace std;
int n,m,c=0,chec=0;
char pn[100][100],pm[100][100];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",pn[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%s",pm[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(pn[i][j] == pm[0][0]){
				c = 0;
				for(int k=0;k<m;k++){
					for(int l=0;l<m;l++){
						if(pn[i+k][j+l] != pm[k][l]){
							c = 1;
						}
					}
				}
				if(c == 0){
					chec = 1;
				}
			}
		}
	}
	if(chec == 0){
		printf("No");
	}
	else{
		printf("Yes");
	}
}
