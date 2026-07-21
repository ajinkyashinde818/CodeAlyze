#include<stdio.h>
int main(void)
{
int x[200000];
int n, i, j;
scanf("%d", &n);
for(i=0;i<n;i++){
scanf("%d", &x[i]);
}
int max=-1000000000, min=x[0];
for(j=1;j<n;j++){
if(x[j]-min>max)
max=x[j]-min;
if(min>x[j])
min=x[j];

}
printf("%d\n", max);
return 0;
}
