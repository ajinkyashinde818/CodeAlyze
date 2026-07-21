#include <stdio.h>
void solve(void)
{
	int k,s;
	int x,y,z;
	int count=0;
	scanf("%d %d", &k, &s);
	for(x=(k<s?k:s);x>=0;--x){
		if(s-x > k+k){
			break;
		} else if( s-x < k ){
			count += s-x+1;
		} else {
			count += (k+k) - (s-x) + 1;
		}
	}
	printf("%d\n", count);
}
int main(int argc, char **argv)
{
	solve();
	return 0;
}
