#include <iostream>
#include<vector>
#include<cmath>
#include <iomanip>
using namespace std;

int main() {
	long long sx,sy,gx,gy;cin>>sx>>sy>>gx>>gy;
	int n;cin>>n;
	vector<long long> x(n),y(n),r(n);
	vector<vector<double>> d;
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i]>>r[i];
	}
	x.push_back(sx);
	y.push_back(sy);
	r.push_back(0);
	x.push_back(gx);
	y.push_back(gy);
	r.push_back(0);
	n+=2;
	for(int i=0;i<n;i++){
		vector<double> d2;
		for(int j=0;j<n;j++){
			double l=sqrt((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]))-r[i]-r[j];
			if(l<0)l=0;
			d2.push_back(l);
		}
		d.push_back(d2);
	}
//	for(int i=0;i<d.size();i++){
//		for(int j=0;j<d[i].size();j++){
//			cout<<d[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	vector<int> use(n,1);
	use[n-2]=0;
	double ans;
	for(int i=0;i<n;i++){
		double min=-1;
		int minnum=-1;
		for(int j=0;j<n;j++){
			if(use[j]){
				if((min<0)+(min>d[n-2][j])){
					min=d[n-2][j];
					minnum=j;
				}
			}
		}
		use[minnum]=0;
		if(minnum==n-1){
			ans=min;
			break;
		}
		for(int j=0;j<n;j++){
			double l=d[n-2][minnum]+d[minnum][j];
			if(d[n-2][j]>l){
				d[n-2][j]=d[n-2][minnum]+d[minnum][j];
			}
		}
	}
	cout<<setprecision(12)<<ans<<endl;

	return 0;
}
