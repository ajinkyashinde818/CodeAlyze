#include<stdio.h>

int m,n;
int x[100];

int lower( int INF,int (*compare)(int) )
{
	int start = 0,end = INF,medi;
	while( start <= end )
	{
		medi = (start+end)/2;
		if( compare(medi) ){
			if( compare(medi-1) )
				end = medi-1;
			else
				break;
		}
		else{
			start = medi+1;
		}
	}
	return medi;
}

int compare( int size ){	//size:本棚の幅
	int i,cnt = 0;
	int rui = 0;
	
	for( i = 0;i < n;i++ ){
		if( size < x[i] )
			return 0;
		if( rui+x[i] > size ){
			rui = x[i];
			cnt++;
		}
		else{
			rui += x[i];
		}
	}
	if( cnt >= m )
		return 0;
	return 1;
}

int main(){
	while( scanf("%d%d",&m,&n) ){
		if( m == 0 )
			break;
		
		for( int i = 0;i < n;i++ ){
			scanf("%d",x+i);
		}
		printf("%d\n",lower( 1500000,compare ) );
	}
	return 0;
}
