#include <stdio.h>
long d[26]={},m=1e9+7,i,n,a=1;main(){scanf("%d\n",&n);for(;i<n;++i)d[getchar()-'a']++;for(i=0;i<26;++i)a=(a*(d[i]+1))%m;printf("%d\n",a-1);}
