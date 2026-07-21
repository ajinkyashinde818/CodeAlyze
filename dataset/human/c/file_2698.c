#include <stdio.h>

int main(){
	int k, s;
	scanf("%d %d", &k, &s);
	int count = 0;
	
	for(int x = 0; x <= k; x++){
		for(int y = 0; y <= k; y++){
			int num = s - (x + y);
            if (0 <= num && num <= k) {
                count++;
            }
        }
    }
    
    printf("%d", count);
}
