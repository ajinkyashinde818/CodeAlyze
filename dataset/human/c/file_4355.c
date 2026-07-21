#include <stdio.h>
#include <string.h>
#define ll long long int
#define e 2.7182818
#define pi 3.14159

int main (){
	int tc;
	scanf ("%d", &tc);
	int ct = 0;
	int oof = 0;
	while (tc != 0){
		int A, B;
		scanf ("%d %d", &A, &B);
		if (A == B){
			ct++;
		}
		else {
			ct = 0;
		}
		if (ct == 3){
			oof = 1;
		}
		tc--;
	}
	(oof == 1) ? (printf ("Yes\n")) : (printf("No\n"));

return 0;
}
