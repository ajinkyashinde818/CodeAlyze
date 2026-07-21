#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <iterator>
#include <cstdlib>
#include <sstream>

using namespace std;

#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) (EQ((a).real(),(b).real()) && EQ((a).imag(),(b).imag()))

typedef complex<double> P;
typedef long long ll;

const int MAX_SIZE = 10000;

// àÏ
double dot(P a, P b) {
  return (a.real() * b.real() + a.imag() * b.imag());
}
// OÏ
double cross(P a, P b) {
  return (a.real() * b.imag() - a.imag() * b.real());
}
// _cª¼üabãÉ é©È¢©
int is_point_on_line(P a, P b, P c) {
  return EQ( cross(b-a, c-a), 0.0 );
}
// 2¼üÌ¼s»è
int is_orthogonal(P a1, P a2, P b1, P b2) {
  return EQ( dot(a1-a2, b1-b2), 0.0 );
}
// 2¼üÌ½s»è
int is_parallel(P a1, P a2, P b1, P b2) {
  return EQ( cross(a1-a2, b1-b2), 0.0 );
}
// _a,bðÊé¼üÆ_cÌÔÌ£
double distance_l_p(P a, P b, P c) {
  return abs(cross(b-a, c-a)) / abs(b-a);
}
// _a,bð[_Æ·éüªÆ_cÆÌ£
double distance_ls_p(P a, P b, P c) {
  if ( dot(b-a, c-a) < EPS ) return abs(c-a);
  if ( dot(a-b, c-b) < EPS ) return abs(c-b);
  return abs(cross(b-a, c-a)) / abs(b-a);
}
// a1,a2ð[_Æ·éüªÆb1,b2ð[_Æ·éüªÌð·»è
int is_intersected_ls(P a1, P a2, P b1, P b2) {
  return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS ) &&
         ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS );
}
// a1,a2ð[_Æ·éüªÆb1,b2ð[_Æ·éüªÌð_vZ
P intersection_ls(P a1, P a2, P b1, P b2) {
  P b = b2-b1;
  double d1 = abs(cross(b, a1-b1));
  double d2 = abs(cross(b, a2-b1));
  double t = d1 / (d1 + d2);

  return a1 + (a2-a1) * t;
}
// a1,a2ðÊé¼üÆb1,b2ðÊé¼üÌð·»è
int is_intersected_l(P a1, P a2, P b1, P b2) {
  return !EQ( cross(a1-a2, b1-b2), 0.0 );
}
// a1,a2ðÊé¼üÆb1,b2ðÊé¼üÌð_vZ
P intersection_l(P a1, P a2, P b1, P b2) {
  P a = a2 - a1; P b = b2 - b1;
  return a1 + a * cross(b, b1-a1) / cross(b, a);
}


struct Circle{
	int x,y,r;
};

/*
~üÆüªÌð·»è
*/
bool isCircleCrossLine(P a,P b,P c,double r){
	double d1 = abs(a-c);
	double d2 = abs(b-c);
	if(d1<r&&d2<r){
		return false;
	}
	double d = distance_ls_p(a,b,c);
	if(EQ(d,r)||d<r){
		return true;
	}
	else
		return false;
}

int main(){
	int n;
	while(cin>>n&&n!=0){
		vector<Circle> vc;
		for(int i = 0; i < n; i++){
			Circle c;
			cin>>c.x>>c.y>>c.r;
			vc.push_back(c);
		}
		int m;
		cin>>m;
		for(int i = 0; i < m; i++){
			int txm,tym,sxm,sym;
			cin>>txm>>tym>>sxm>>sym;
			bool f=false;
			for(int j = 0; j < vc.size(); j++){
				if(isCircleCrossLine(P(sxm,sym),P(txm,tym),P(vc[j].x,vc[j].y),vc[j].r)){
					f=true;
					break;
				}
				//double d1 = abs(P(txm-vc[j].x,tym-vc[j].y));
				//double d2 = abs(P(sxm-vc[j].x,sym-vc[j].y));
				//if(d1<vc[j].r&&d2<vc[j].r){
				//	continue;
				//}
				//double d = distance_ls_p(P(txm,tym),P(sxm,sym),P(vc[j].x,vc[j].y));
				//if(d<=vc[j].r){
				//	f=true;
				//	break;
				//}
			}
			if(f){
				cout<<"Safe"<<endl;
			}
			else
				cout<<"Danger"<<endl;
			//bool f=false;
			//for(int j = 0; j < vc.size(); j++){
			//	double d = distance_ls_p(P(txm,tym),P(sxm,sym),P(vc[j].x,vc[j].y));
			//	if(d>=vc[j].r){
			//		f=true;
			//		break;
			//	}
			//}
			//if(!f){
			//	cout<<"Safe"<<endl;
			//}
			//else{
			//	cout<<"Danger"<<endl;
			//}
		}
	}

	return 0;
}
