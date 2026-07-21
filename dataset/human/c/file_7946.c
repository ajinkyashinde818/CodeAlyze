#include <stdio.h>
#include <string.h>

int main(void){
	int n, k, c, idx;
	char str[200000];

	scanf("%d%d%d%s", &n, &k, &c, str);

	int fwd[n], bck[n];
	for(int i=0, idx = 0; i < n || idx < k; i++) {
		if(str[i] == 'o') {
			fwd[idx++] = i+1;
			i += c;
		}
	}

	for(int i=n-1, idx = 0; i >= 0 || idx < k; i--) {
		if(str[i] == 'o') {
			bck[k-1-idx++] = i+1;
			i -= c;
		}
	}

	for(idx=0; idx < k; idx++) {
		if(fwd[idx] == bck[idx])
			printf("%d\n", fwd[idx]);
	}

	return 0;
}
