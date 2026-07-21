#include<iostream>
#include<cstring>
using namespace std;

int n,m;
char a[100][100],b[100][100];

int main(){
	cin >> n >> m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) cin >> a[i][j];
	for (int i=1;i<=m;i++)
		for (int j=1;j<=m;j++) cin >> b[i][j];
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			int f=0;
			for (int h=1;h<=m;h++){
				for (int l=1;l<=m;l++)
					if (a[i+h-1][j+l-1]!=b[h][l]){
						f=1;
						break;
					}
				if (f==1) break;
			}
			if (f==0){
				cout << "Yes" << endl;
				return 0;
			}		
		}
	}
	cout << "No" << endl;
	return 0;
}
