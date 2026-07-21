#include<bits/stdc++.h>
using namespace std;

int N;
int x[1002],y[1002],r[1002];
double z[1002][1002];
pair<double,int>p[1002];
bool f[1002];

main(){
	cin>>x[0]>>y[0]>>x[1]>>y[1];
	cin>>N;
	N+=2;
	for(int i=2;i<N;++i){
		cin>>x[i]>>y[i]>>r[i];
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			z[i][j]=z[j][i]=max(0.0,hypot(x[i]-x[j],y[i]-y[j])-r[i]-r[j]);
		}
	}
	for(int i=1;i<N;++i){
		p[i]={1e10,0};
	}
	int v=0;
	p[0]={0,0};
	f[0]=true;
	while(v!=1){
		for(int i=0;i<N;++i){
			if(!f[i]&&p[v].first+z[v][i]<p[i].first){
				p[i]={p[v].first+z[v][i],v};
			}
		}
		double d=1e10;
		for(int i=0;i<N;++i){
			if(!f[i]&&p[i].first<d){
				d=p[i].first;
				v=i;
			}
		}
		f[v]=true;
	}
	printf("%.15f",p[1].first);
}
