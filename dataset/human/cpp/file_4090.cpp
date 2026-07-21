#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
typedef long long int ll;

double d[1010][1010];
double x[1010],y[1010],r[1010];

double dist(double a,double b){
	return sqrt(a*a+b*b);
}

double X[2],Y[2];

double hyado[1010];
int used[1010];

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	for(int i=0;i<2;i++){
		cin >> X[i] >> Y[i];
	}
	int n; cin >> n;
	for(int i=0;i<n;i++){
		cin >> x[i] >> y[i] >> r[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			double dis=dist(x[i]-x[j],y[i]-y[j]);
			d[i][j]=max((double)0,dis-r[i]-r[j]);
		}
		d[i][n]=d[n][i]=max((double)0,dist(x[i]-X[0],y[i]-Y[0])-r[i]);
		d[i][n+1]=d[n+1][i]=max((double)0,dist(x[i]-X[1],y[i]-Y[1])-r[i]);
	}
	d[n][n+1]=d[n+1][n]=dist(X[0]-X[1],Y[0]-Y[1]);

	for(int i=0;i<n+2;i++){
		hyado[i]=1e18;
	}
	for(int i=0;i<n;i++){
		used[i]=0;
	}
	hyado[n]=0;
	for(int i=0;i<n+2;i++){
		int ne=-1;
		for(int j=0;j<n+2;j++){
			if(used[j]==0&&(ne==-1||hyado[ne]>hyado[j]))ne=j;
		}
		used[ne]=1;
		for(int j=0;j<n+2;j++){
			 hyado[j]=min(hyado[j],hyado[ne]+d[ne][j]);
		}
	}
	printf("%.10f\n",hyado[n+1]);
	return 0;
}
