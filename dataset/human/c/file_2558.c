#include<stdio.h>

int main() {
    char str[3];
    int resa = 0, resb = 0, resc = 0;

    scanf("%s", str);

    for (int i = 0; i < 3; i++) {
        if (str[i] == 'a')
	    resa = 1;
	else if (str[i] == 'b')
	    resb = 1;
	else if (str[i] == 'c')
	    resc = 1;
	else
	    resa = 0;
    }
    if (resa == 1 && resb == 1 && resc == 1)
	printf("Yes\n");
    else
	printf("No\n");

    return 0;
}
