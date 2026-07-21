#include <stdio.h>

int main(int argc, char** argv){
	int n,value;
	int base,max_diff;
	int i;

	// Input n + two number
	scanf("%d%d%d",&n, &base, &value);
	max_diff = value - base;
	if( value < base ) {
		base = value;
	}

	// Check Rest Number
	for(i=3;i<=n;i++){
		scanf("%d",&value);
		if( value - base > max_diff ){
			max_diff = value - base;
		}
		if( value < base ) {
			base = value;
		}
	}

	// Output
	printf("%d\n",max_diff);

	return 0;
}
