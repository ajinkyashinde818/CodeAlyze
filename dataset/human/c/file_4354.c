#include <stdio.h>
#include <string.h>
int main(){
int n, a , ab, ctr = 0, flag = 0;
scanf("%d", &n);
for(int i = 0;i < n;i++){
	scanf("%d %d", &a, &ab);
	if(a == ab){
		ctr++;
	}else{
		ctr = 0;
	}
	if(ctr >= 3){
		flag = 1;
	}
}
flag == 1 ? printf("Yes") : printf("No");
return 0;
}
