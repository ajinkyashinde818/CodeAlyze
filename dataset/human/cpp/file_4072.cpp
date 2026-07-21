#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
double x[1100];
double y[1100];
double r[1100];
double ijk[1100];
int v[1100];
int main(){
	double X1,X2,Y1,Y2;
	scanf("%lf%lf%lf%lf",&X1,&Y1,&X2,&Y2);
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%lf%lf%lf",x+i,y+i,r+i);
	}
	int s=a;
	int t=a+1;
	int n=a+2;
	x[s]=X1;
	y[s]=Y1;
	x[t]=X2;
	y[t]=Y2;
	for(int i=0;i<n;i++)ijk[i]=99999999999999.9;
	ijk[s]=0;
	for(int i=0;i<n;i++){
		int at=0;
		double dist=999999999999999.9;
		for(int j=0;j<n;j++){
			if(!v[j]&&ijk[j]<dist){
				at=j;dist=ijk[j];
			}
		}
		v[at]=1;
		for(int j=0;j<n;j++){
			ijk[j]=min(ijk[j],ijk[at]+max(0.0,sqrt((x[j]-x[at])*(x[j]-x[at])+(y[j]-y[at])*(y[j]-y[at]))-r[j]-r[at]));
		}
	}
	printf("%.12f\n",ijk[t]);
}
