#include<stdio.h>

void swap(char* pX, char* pY)
{
    char tmp;

    tmp = *pX;
    *pX = *pY;
    *pY = tmp;
}

int main(void)
{
    char a[101], b[101];
    int numA=0;
    int numB=0;

    scanf("%s", a);
    scanf("%s", b);

    while('\0' != a[numA]) {
        numA++;
    }

    while('\0' != b[numB]) {
        numB++;
    }

    for(int i=0; numA>i; i++) {
        for(int j=numA-1; i<j; j--) {
            if(a[j] < a[j-1]) {
                swap(&a[j], &a[j-1]);
            }
        }
    }

    for(int i=0; numB>i; i++) {
        for(int j=numB-1; i<j; j--) {
            if(b[j] > b[j-1]) {
                swap(&b[j], &b[j-1]);
            }
        }
    }

    int i=0;
    while(i<=numA) {
        if(a[i] < b[i]) {
            printf("Yes\n");
            return 0;
        }
        else if((a[i] > b[i]) || ('\0'==b[i])) {
            printf("No\n");
            return 0;
        }
        else {
            i++;
            continue;
        }
    }

    printf("Yes\n");

    return 0;
}
