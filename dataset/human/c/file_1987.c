#include <stdio.h>

int main(void){
	
	typedef long long int lld;
	lld untasty_cure, tasty_cure, tasty_poison; 
	scanf("%lld %lld %lld", &untasty_cure, &tasty_cure, &tasty_poison);
	
	if(tasty_poison-1 <= tasty_cure + untasty_cure) printf("%lld", tasty_poison + tasty_cure);
	else printf("%lld", tasty_cure * 2 + untasty_cure + 1);
}
