#include<stdio.h>
 
char f[5000];
char match[5000][5000];
int rank[5000];
int num,n;
 
void func(int i){
    int j;
    if(f[i-1]==1) return;
    f[i-1]=1;
    for(j=1;j<=n;j++){
    	if(match[j-1][i-1]) func(j);
    }
    printf("%d\n",i);
    rank[num]=i-1;
    num++;
}
 
int main(){
    long i;
    int j,k;
    long m;
    int w,l;
    int flag;
    scanf("%d",&n);
    scanf("%ld",&m);
    for(i=0;i<m;i++){
        scanf("%d %d",&w,&l);
        match[w-1][l-1]=1;
    }
    for(j=1;j<=n;j++){
        func(j);
    }
    flag=1;
    for(j=0;j<n-1;j++){
    	if(match[rank[j]][rank[j+1]]==0){
    		flag=0;
    		break;
    	}
    }
    if(flag) printf("0\n");
    else printf("1\n");
    return 0;
}
