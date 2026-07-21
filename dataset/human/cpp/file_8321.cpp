#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,type=-1;
char a[55][55],b[55][55];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",a[i-1]);
	}
	for(int i=1;i<=m;i++){
		scanf("%s",b[i-1]);
	}
	for(int i=1;i<=n-m+1;i++){
		for(int j=1;j<=n-m+1;j++){
			cnt=0;
			for(int k=i;k<=i+m-1;k++){
				for(int l=j;l<=j+m-1;l++){
					if(a[k-1][l-1]==b[k-i][l-j]){
						++cnt;
					}
				}
			}
			if(cnt==m*m){
				type=0;
				break;
			}
		}
	}
	if(type==0){
		printf("Yes");
	}else printf("No");
}
