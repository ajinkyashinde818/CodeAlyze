#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int N, cnt=0,Min=1987654321;
	long long sum=0;
	scanf("%d",&N);
	while(N--){
		int tmp;
		scanf("%d",&tmp);
		sum+=abs(tmp);
		Min=min(Min,abs(tmp));
		cnt+=tmp<0;
	}
	printf("%lld",sum-(cnt%2?Min*2:0));
}
