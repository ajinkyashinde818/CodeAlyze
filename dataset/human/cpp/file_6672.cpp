#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

int main(){
	
	while(true){
		
		int n, m;
		
		cin >> n;
		
		if(n == 0){
			break;
		}
		
		long long int wx[200], wy[200], r[200];
		
		for(int i = 0; i < n; i++){
			cin >> wx[i] >> wy[i] >> r[i];
		}
		
		cin >> m;
		
		for(int loop = 0; loop < m; loop++){
			
			bool flag = false;
			
			long long int tx, ty, sx, sy;
			cin >> tx >> ty >> sx >> sy;
			
			for(int i = 0; i < n; i++){
				bool isin1 = false, isin2 = false;
				if((sx - wx[i]) * (sx - wx[i]) + (sy - wy[i]) * (sy - wy[i]) < r[i] * r[i]){
					isin1 = true;
				}
				if((tx - wx[i]) * (tx - wx[i]) + (ty - wy[i]) * (ty - wy[i]) < r[i] * r[i]){
					isin2 = true;
				}
				if(isin1 && isin2){
					continue;
				}else if(isin1 || isin2){
					flag = true;
					break;
				}
				long long int a, b, c;
				a = (ty - sy);
				b = (sx - tx);
				c = sx * (sy - ty) - sy * (sx - tx);
				if((a * wx[i] + b * wy[i] + c) * (a * wx[i] + b * wy[i] + c) > r[i] * r[i] * (a * a + b * b)){
					continue;
				}
				double a1, b1, x_center;
				a1 = (sx - tx) * (sx - tx) + (sy - ty) * (sy - ty);
				b1 = (sx - tx) * (wx[i] * (sx - tx) + wy[i] * (sy - ty)) - (sx * ty - tx * sy) * (sy - ty);
				x_center = b1 / a1;
				if((sx - x_center) * (tx - x_center) <= 0){
					flag = true;
					break;
				}
			}
			if(flag){
				cout << "Safe" << endl;
			}else{
				cout << "Danger" << endl;
			}
		}
		
	}
	return 0;
}
