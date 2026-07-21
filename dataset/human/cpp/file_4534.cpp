#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	double T, D;
	cin >> T >> D;
	double ta, tb, da, db;
	cin >> ta >> tb >> da >> db;
	double temp = -1000;
	for(int i=0; i <= D/da+10; i++){
		for(int j=0; j <= D/db+10; j++){
			if(D < da*i + db*j) continue;
			if(da*i+db*j == 0) continue;
			double t = (ta*da*i+tb*db*j)/(da*i+db*j);
			if(abs(T-temp) > abs(T-t)) temp = t;
		}
	}
	printf("%.10f\n", abs(T-temp));
}
