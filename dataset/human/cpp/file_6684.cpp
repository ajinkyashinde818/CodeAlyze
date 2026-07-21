#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>

using namespace std;

struct Point{int x,y;};
struct Circle{Point p;int r;};

/* _a,b©ç£ÌñæðÔ·Ö */
inline int DistanceSquared( Point a, Point b ){ return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y); }

/* ¾YASA éÇÌîñ©çA»êçÌÊuÖWªSafe©Danger©²×éÖ */
bool IsSafePlace( Circle c, Point taro, Point dem ){
	double vx1, vy1, vx2, vy2, alpha1, alpha2;
	int seki = (taro.x-c.p.x)*(dem.x-taro.x) + (taro.y-c.p.y)*(dem.y-taro.y);
	int D = seki*seki - DistanceSquared(taro,dem)*(DistanceSquared(c.p,taro)-c.r*c.r);

	if( D < 0 )
		return false;

	alpha1 = (-seki-sqrt((double)D)) / DistanceSquared(taro, dem);
	alpha2 = (-seki+sqrt((double)D)) / DistanceSquared(taro, dem);

	vx1 = (taro.x - c.p.x) + alpha1 * ( dem.x - taro.x );
	vy1 = (taro.y - c.p.y) + alpha1 * ( dem.y - taro.y );
	vx2 = (taro.x - c.p.x) + alpha2 * ( dem.x - taro.x );
	vy2 = (taro.y - c.p.y) + alpha2 * ( dem.y - taro.y );

	if( taro.x == c.p.x && taro.y == c.p.y || dem.x == c.p.x && dem.y == c.p.y){
		if( DistanceSquared( taro, dem ) > c.r * c.r )
			return true;
		else
			return false;
	}else if(
		( (vx1*(taro.y-c.p.y) - vy1*(taro.x-c.p.x)) * (vx1*(dem.y-c.p.y) - vy1*(dem.x-c.p.x)) > 0 ) &&
		( (vx2*(taro.y-c.p.y) - vy2*(taro.x-c.p.x)) * (vx2*(dem.y-c.p.y) - vy2*(dem.x-c.p.x)) > 0 ) )
		return false;
	else
		return true;
}
int main(void){
	while(true){
		int n, m;
		vector<Circle> vWall;

		cin >> n;
		
		if( n == 0 )
			break;

		for(int i = 0; i < n; ++i){
			Circle tc;
			cin >> tc.p.x >> tc.p.y >> tc.r;
			vWall.push_back( tc );
		}

		cin >> m;

		for(int i = 0; i < m; ++i){
			bool bDanger = true;

			Point p_taro, p_daemon;
			cin >> p_taro.x >> p_taro.y >> p_daemon.x >> p_daemon.y;
			for( unsigned int j = 0; j < vWall.size() && bDanger; ++j ){
				if( IsSafePlace( vWall[j], p_taro, p_daemon ) ){
					bDanger = false;
					cout << "Safe\n";
				}
			}

			if( bDanger )
				cout << "Danger\n";
		}
	}
}
