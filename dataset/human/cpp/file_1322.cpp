#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

	

int main(){
	int g,a,b,c,n,count=0;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> n;
	if(a<b){
		g=b;
		b=a;
		a=g;
	}
	if(b<c){
		g=c;
		c=b;
		b=g;
	}
	if(a<b){
		g=b;
		b=a;
		a=g;
	}
	
	for(int i=0;i*a<=n;i++){
		for(int j=0;j*b+i*a<=n;j++){
			if( (n-j*b-a*i)%c==0){
				count++;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}
