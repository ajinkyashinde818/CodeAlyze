#include<stdio.h>
int main()
{
int  n, m, a[200001]={0}, b[200001]={0};
int  i, j, k, f=0;

scanf("%d %d", &n, &m);
for( k=0; k<m; k++){
scanf("%d %d", &i, &j);
if( i == 1) a[j] = 1;
if( j == n) b[i] = 1;
}

for( i=1; i<=n; i++){
if(a[i]==1){
if(b[i]==1){
f = 1;
}
}
}

if(f)
printf("POSSIBLE\n");
else
printf("IMPOSSIBLE");

return 0;
}
