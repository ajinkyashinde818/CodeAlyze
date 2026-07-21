#include<stdio.h>
#include<stdlib.h>

int main(){
	int n, k, c;
	char *s;

	scanf("%d %d %d", &n, &k, &c);
	s = (char *)malloc(sizeof(char)*(n+1));
	scanf("%s", s);

	int *l, *r;
	l = (int *)malloc(sizeof(int)*n);
	r = (int *)malloc(sizeof(int)*n);

	int x = 0, d = 1;
	while(d <= n){
		if(s[d-1] == 'o'){
			l[x] = d;
			d += (c + 1);
			x++;
			if(x > k-1){
				break;
			}
		}else{
			d++;
		}
	}

	x = k-1; d = n;
	while(d > 0){
		if(s[d-1] == 'o'){
			r[x] = d;
			d -= (c + 1);
			x--;
			if(x < 0){
				break;
			}
		}else{
			d--;
		}
	}

	int i;
	for(i=0; i<k; i++){
		if(l[i] == r[i]){
			printf("%d\n", l[i]);
		}
	}
	return 0;
}
