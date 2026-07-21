#include<stdio.h>
 
int main()
{
    int n,i,j;
    scanf("%d",&n);
    int r[200000];
    for(i=0;i<n;i++){
		scanf("%d",&r[i]);
	}
int maxv=r[1]-r[0];
int minv=r[0];

for(j=1;j<n;++j){
	if(maxv<(r[j]-minv)){
		maxv=r[j]-minv;
		}
		else{
		maxv=maxv;
		}
    if(minv>r[j]){
		minv=r[j];
		}
		else{
			minv=minv;
			
			
			
			
}
}
		printf("%d\n",maxv);
		return 0;
}
