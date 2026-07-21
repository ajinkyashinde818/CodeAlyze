#include<iostream>
#include<complex>
#include<cmath>
#include<cstdio>
using namespace std;

complex<double> w[100];
int r[100];
complex<double> t,s;

bool inter(int a,double  x,double y){
  return sqrt( (w[a].real()-x)*(w[a].real()-x) + (w[a].imag()-y)*(w[a].imag()-y) ) <= r[a] + 1e-10;
}

double dot(complex<double> a,complex<double> b){
  return a.real()*b.real() + a.imag()*b.imag();
}

double cross(complex<double> a,complex<double> b){
  return a.real() * b.imag() - a.imag() * b.real();
}

double dis_s_p(complex<double> a,complex<double> b,complex<double> c){
  if( dot(b-a,c-a) < 1e-10 ) return abs(c-a);
  if( dot(a-b,c-b) < 1e-10 ) return abs(c-b);
  return abs( cross(b-a,c-a) ) / abs(b-a);
}

int main(){
  int n,m;

  while(1){
    cin >> n;
    if(!n)break;

    for(int i=0;i<n;i++)cin >> w[i].real() >> w[i].imag() >> r[i];

    cin >> m;
    for(int i=0;i<m;i++){
      cin >> t.real() >> t.imag() >> s.real() >> s.imag();

      bool f = true;
      for(int j=0;j<n;j++){
	bool a = inter(j,t.real(),t.imag()),b = inter(j,s.real(),s.imag());
	if(a != b)f = false;
	else if(!a && !b){
	  if(dis_s_p(t,s,w[j]) <= r[j] + 1e-10)f = false;
	}
	if(!f)break;
      }

      if(f)cout << "Danger\n";
      else cout << "Safe\n";
    }
  }
}
