#include "stdio.h"
#define rep(i,n) for(i=0;i<n;i++)
int main(){
	int n,i,j,x,y,sz,ret,minus;
	char mt[1000][1000];

	while( scanf("%d\n",&n) , n){
		ret = 0;

		rep(i,n)scanf("%s\n",mt[i]);
	
		rep(y,n)rep(x,n){
		
			if(mt[y][x] == '.'){
			
				minus = (x>y?x:y);
				rep(sz,n-minus){
					rep(i,sz+1)if(mt[y+sz][x+i] == '*'){goto l;}
					rep(i,sz+1)if(mt[y+i][x+sz] == '*'){goto l;}
					
					if(ret<sz+1)ret = sz+1;
				}
				l:;
			}
		}
		printf("%d\n",ret);
	}
	return 0;
}
