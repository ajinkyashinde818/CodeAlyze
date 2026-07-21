//I_F_A
#include "bits/stdc++.h"
using namespace std;

int main(){

	long long n,m;
	cin >> n >> m;

	char arr[n+1][n+1],brr[m+1][m+1];
	
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=n;j++)
			cin >> arr[i][j];

	for(long long i=1;i<=m;i++)
		for(long long j=1;j<=m;j++)
			cin >> brr[i][j];

	bool found = 0;

	for(long long i=1;i+m-1<=n;i++){

		for(long long j=1;j+m-1<=n;j++){

			bool wrong = 0;
			for(long long k=i;k<=i+m-1;k++){

				for(long long t=j;t<=j+m-1;t++){

					if(brr[k-i+1][t-j+1] != arr[k][t]){

						wrong = 1;
					}
				}
			}
			if(wrong == 0)
				found = 1;
		}
	}
	if(found == 1)
		cout << "Yes\n";
	else
		cout << "No\n";
}
