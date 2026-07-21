#include<stdio.h>

int main(void)
{
int  n, a[100001];
int  i, p, c;

scanf("%d", &n);

for(i=1; i<=n; i++){
scanf("%d", &a[i]);
}


i = a[1];
c=1;
while( i != 1 && i != 2){
p = a[i];
a[i] = 1;
i = p;
c++;
}

if( i == 2){
printf("%d\n", c);
} else {
printf("-1\n");
}

return 0;
}
