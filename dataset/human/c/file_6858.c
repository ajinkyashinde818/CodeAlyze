#include <stdio.h>
#define max(a,b) (a)>(b) ? (a):(b);
int n;
int a[100][100];
int psum[100][100][100];
int getpsum(int uly,int ulx,int lry,int lrx){
	psum[ulx][lry][lrx]=0;
	int i,j;

	for(i=uly;i<=lry;i++)
		for(j=ulx;j<=lrx;j++)
			psum[ulx][lry][lrx]+=a[i][j];
	return psum[ulx][lry][lrx];
}
int getpsumu(int uly,int ulx,int lry,int lrx){
	int i;

	for(i=ulx;i<=lrx;i++)
		psum[ulx][lry][lrx]-=a[uly-1][i];

	return psum[ulx][lry][lrx];
}
int getpsuml(int uly,int ulx,int lry,int lrx){
	int i;
	psum[ulx][lry][lrx]=psum[ulx-1][lry][lrx];

	for(i=uly;i<=lry;i++)
		psum[ulx][lry][lrx]-=a[i][ulx-1];

	return psum[ulx][lry][lrx];
}
main(){
	int i,j,k,l;
	int  maxsum=-100000000LL;
	int tmp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	/*
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			for(k=i;k<n;k++)
				for(l=j;l<n;l++)
					maxsum=max(maxsum,getpsum(i,j,k,l));
	*/
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			for(k=i;k<n;k++)
				for(l=j;l<n;l++){
					if(i==0){
						if(j==0){
							tmp=getpsum(i,j,k,l);
							maxsum=max(maxsum,tmp);
						}else{
							tmp=getpsuml(i,j,k,l);
							maxsum=max(maxsum,tmp);
						}
					}else{
						tmp=getpsumu(i,j,k,l);
						maxsum=max(maxsum,tmp);
					}
				}

	printf("%d\n",maxsum);
	return 0;
}
