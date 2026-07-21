#include <bits/stdc++.h>
using namespace std;
char str[105][105];
char ch[105][1045];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",str[i]);
	for(int i=0;i<m;i++){
		scanf("%s",ch[i]);
	}
	if(m==n){
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				if(str[i][j]!=ch[i][j]){
					puts("No");
					return 0;
				}
			}
		}
		puts("Yes");
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(str[i][j]==ch[0][0]){
				int flag=1;
				for(int k=0;k<m;k++){
					for(int b=0;b<m;b++){
						if(str[k+i][b+j]!=ch[k][b]){
							flag=0;
							break;
						}
					}
					if(flag==0){
						break;
					}
				}
				if(flag){
					puts("Yes");
					return 0;
				}
			}
		}
	}
	puts("No");
	return 0;
}
