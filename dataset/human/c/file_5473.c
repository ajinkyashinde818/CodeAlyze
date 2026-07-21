#include<stdio.h>
#include<math.h>
int main(void){
    int w,h,n;
    int X[1000],Y[1000];
    int i,j,k;
    int ans,min,difx,dify;

    scanf("%d%d%d",&w,&h,&n);
    scanf("%d%d",&X[0],&Y[0]);

    ans=0;
    for(i=1;i<n;i++){
	scanf("%d%d",&X[i],&Y[i]);
	if(X[i]>X[i-1] && Y[i]>Y[i-1]||
	   X[i]<X[i-1] && Y[i]<Y[i-1]){
	    difx=abs(X[i]-X[i-1]);
	    dify=abs(Y[i]-Y[i-1]);
	    if(difx>dify) ans+=difx;
	    else ans+=dify;
	}else{
	    if(X[i]>X[i-1]) ans+=X[i]-X[i-1];
	    else ans+=X[i-1]-X[i];
	    if(Y[i]>Y[i-1]) ans+=Y[i]-Y[i-1];
	    else ans+=Y[i-1]-Y[i];
	}
    }

    printf("%d\n",ans);

    return 0;
}
