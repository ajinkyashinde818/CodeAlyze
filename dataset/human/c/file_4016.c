#include <stdio.h>
int main(){
    int a,b,k;
    int count = 0;
    int ans;
 
    scanf("%d%d%d",&a,&b,&k);
  
  	for (int i = 100; i >= 0; i--) {
        if (((a % i) == 0) && ((b % i) == 0)) {
            count++;
            if (count == k) {
                ans = i;
                break;
            }
        }
    }
 
    printf("%d\n",ans);
	return 0;
}
