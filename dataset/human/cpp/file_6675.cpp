#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>
#include<cctype>
#include<complex>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<bitset>
using namespace std;
const int dx[] = {1,0,-1,0},dy[] = {0,1,0,-1};
#define INF 1e+8
#define EPS 1e-10
#define PB push_back
#define fi first
#define se second
#define ll long long 
#define reps(i,j,k) for(int i = (j); i < (k); i++)
#define rep(i,j) reps(i,0,j)
typedef pair<double,double> Pdd;
double check_p(double A,double B,double C,double D){
    return (-B+sqrt(D))/(2*A);
}
double check_m(double A,double B,double C,double D){
    return (-B-sqrt(D))/(2*A);
}
int main(){
    int n;
    while(scanf("%d",&n),n){
        vector < Pdd > circle;
        vector < double > R;
        rep(i,n){
            double a,b,r;
            scanf("%lf%lf%lf",&a,&b,&r);
            circle.PB(Pdd(a,b));
            R.PB(r);
        }
        int m;
        scanf("%d",&m);
        rep(i,m){
            double tx,ty,sx,sy;
            scanf("%lf%lf%lf%lf",&tx,&ty,&sx,&sy);
            double m,d;
            double a,b,r;
            bool isstraight = false;
            m = (sy-ty)/(sx-tx);
            d = sy - m*sx;
            if(sx == tx){
                isstraight = true;
            }
            bool flg = false;
            rep(j,n){
                a = circle[j].fi;
                b = circle[j].se;
                r = R[j];
                double A,B,C;
                A = m*m+1;
                B = (-2.0*a+2.0*m*d-2.0*m*b);
                C = a*a+b*b+d*d-2.0*b*d-r*r;
                if(isstraight){
                    if(fabs(a-sx) <= r){
                        flg = true;
                        break;
                    }
                }
                else if(!(B*B-4.0*A*C < EPS)){
                    if(min(sx,tx)-check_p(A,B,C,B*B-4.0*A*C) < EPS  && check_p(A,B,C,B*B-4.0*A*C)-max(sx,tx) < EPS ){
                        flg = true;
                        break;
                    }
                    if(min(sx,tx)-check_m(A,B,C,B*B-4.0*A*C) < EPS && check_m(A,B,C,B*B-4.0*A*C)-max(sx,tx) < EPS){  
                        flg = true;
                        break;  
                    }
                }
            }
            if(flg)puts("Safe");
            else puts("Danger");
        }
    }
    return 0;
}
