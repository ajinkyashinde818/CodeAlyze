#include <stdio.h>

int main(void){
	int a, b, c, d;
	int s_ab, s_cd;
	
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	s_ab = a*b;
	s_cd = c*d;
	
	if (s_ab > s_cd) printf("%d\n", s_ab);
	else printf("%d\n", s_cd);
	
	return 0;
}
