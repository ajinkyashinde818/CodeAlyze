#include<stdio.h>
int ic(const void *_a, const void *_b){int a = *(int *)_a;int b = *(int *)_b;if(a<b){return -1;}else if(a>b){return 1;}else{return 0;}}
void main(){int V,d,count;while(scanf("%d%d",&V,&d)!=EOF){int i,fib[V],j;count=0;fib[0]=2,fib[1]=3;for(i=2;i<V;i++)fib[i]=((j = fib[i-1]+fib[i-2])>1001)?(j-1001):j;qsort(fib,V,sizeof(int),ic);for(i=1; i<V; i++)if((fib[i] - fib[i-1]) >= d)count++;printf("%d\n",++count);}}
