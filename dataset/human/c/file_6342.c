#include <stdio.h>

int main(void){
	int a, b, c, n, i, m, p, cur;
	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &p);
	a=p-m;
	if(m>p){
		m=p;
	}	
	for (i = 2; i < n; i++){
		scanf("%d", &cur);
		b = cur-p;
		c = cur-m;
		if(b>c){
			if(a<b)a=b;
		}else if(a<c){
			a=c;
		}
		if(m>cur){
			m=cur;
		}
		p=cur;
	}
	printf("%d\n", a);
	return 0;
}
