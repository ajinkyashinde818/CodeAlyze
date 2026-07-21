#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int a[n], b[n], flag = 0;
	bool flg = true;
	for(int i = 0; i<n; i++){
		scanf("%d %d", &a[i], &b[i]);
		if(a[i]==b[i]) flag++;
		else flag = 0;
		if(flag==3) flg = false;
	}
	if(flg == false) printf("Yes");
	else printf("No");
	return 0;
}
