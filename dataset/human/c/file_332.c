#include <stdio.h>

int main(void) {
	int asumikana,kitamuraeri;
	int mimorisuzuko,tokuisora;
	int tomatuharuka,igutiyuka;
	int murakawarie,isikawakaito;
	double sakuraayane=10000000.0;
	if(scanf("%d%d",&asumikana,&kitamuraeri)!=2)return 1;
	if(scanf("%d%d",&mimorisuzuko,&tokuisora)!=2)return 1;
	if(scanf("%d%d",&tomatuharuka,&igutiyuka)!=2)return 1;
	for(murakawarie=0;murakawarie*tomatuharuka<kitamuraeri;murakawarie++) {
		for(isikawakaito=0;isikawakaito*igutiyuka<=kitamuraeri-murakawarie*tomatuharuka;isikawakaito++) {
			if(murakawarie+isikawakaito>0) {
				double nakamurayuuiti=tomatuharuka*murakawarie;
				double sakagutidaisuke=igutiyuka*isikawakaito;
				double tanedarisa=(mimorisuzuko*nakamurayuuiti+tokuisora*sakagutidaisuke)/(nakamurayuuiti+sakagutidaisuke);
				double minaseinori=asumikana-tanedarisa;
				if(minaseinori<0)minaseinori=-minaseinori;
				if(minaseinori<sakuraayane)sakuraayane=minaseinori;
			}
		}
	}
	printf("%.15f\n",sakuraayane);
	return 0;
}
