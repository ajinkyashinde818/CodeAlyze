#include<stdio.h>
#include<algorithm>
using namespace std;
double ABS(double a){return max(a,-a);}
int main(){
	int T,D,ta,tb,da,db;
	scanf("%d%d%d%d%d%d",&T,&D,&ta,&tb,&da,&db);
	double ret=999999999;
	for(int i=0;i<=D;i+=da){
		for(int j=0;i+j<=D;j+=db){
			if(i+j==0)continue;
			double S=(double)(ta*i+tb*j)/(i+j);
			ret=min(ret,ABS(T-S));
		}
	}
	printf("%.12f\n",ret);
}
