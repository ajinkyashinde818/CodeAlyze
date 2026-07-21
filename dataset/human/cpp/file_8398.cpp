#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<string.h>
using namespace std;
int n,m;
string a[51], b[51];
int main(){
	while (~scanf("%d%d", &n,&m)){
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		for (int i = 0; i < m; i++){
			cin >> b[i];
		}
		bool h=true;
		for (int i = 0; i < n-m+1 ; i++){
			for (int j = 0; j < n-m+1 ; j++){
				h = true;
				for (int k = 0; k < m; k++){
					for (int w = 0; w < m; w++){
						//if ((i + k) >= n || (j + w) >= n){ h = false; break; }
						if (b[k][w] != a[i + k][j + w]){
							h = false; break;
						}
					}
					if (h == false)break;
				}
				if (h == true)break;
			}
			if (h == true)break;
		}
		if (h == true){ printf("Yes\n"); }
		else{ printf("No\n"); }
	}
	return 0;
}
