#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

char s[1010][1099];
int main(){
	ll n;
	while(scanf("%lld",&n),n){
		rep(i,0,n){
			scanf(" %s",s[i]);
			int j=0;
			while(s[i][j]=='.'){
				if(s[i][j+1]=='.')s[i][j]=' ';
				else{
					s[i][j]='+';
					int temp=i-1;
					while(temp>=0&&s[temp][j]==' ')s[temp--][j]='|';
				}
				j++;
			}
		}
		rep(i,0,n)puts(s[i]);
	}
}
