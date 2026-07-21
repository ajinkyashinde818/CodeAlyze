#include<stdio.h>
int main() {
    int a[100003];
    int i = 0;
    int temp;
   
    do{

        scanf("%d", &temp);
        a[i] = temp;
        i++;
    } while (temp != 0);
    for (int j = 0; j < i-1; j++)
        printf("Case %d: %d\n", j+1, a[j]);

        return 0;
}
