//36
#include<iostream>
#include<cmath>
#include<complex>

using namespace std;

typedef complex<double> P;

double cr(P a,P b){
  return a.real()*b.imag()-a.imag()*b.real();
}

int main(){
  for(int n;cin>>n,n;){
    P w[100];
    double r[100];
    for(int i=0;i<n;i++){
      double x,y;
      cin>>x>>y>>r[i];
      w[i]=P(x,y);
    }
    int m;
    cin>>m;
    while(m--){
      P t,s,l;
      double tx,ty,sx,sy;
      cin>>tx>>ty>>sx>>sy;
      t=P(tx,ty);
      s=P(sx,sy);
      l=t-s;
      int i;
      for(i=0;i<n;i++){
	if((abs(w[i]-t)-r[i])*(abs(w[i]-s)-r[i])<0)break;
	if(abs(w[i]-t)>r[i]&&cr((t-s)*P(0,1),w[i]-s)*cr((s-t)*P(0,1),w[i]-t)>0&&abs(w[i]-s)*fabs(sin(arg(w[i]-s)-arg(l)))<=r[i]+1e-9)break;
      }
      cout<<((i<n)?"Safe":"Danger")<<endl;
    }
  }
  return 0;
}
