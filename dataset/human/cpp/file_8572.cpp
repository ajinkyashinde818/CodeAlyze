#include <iostream>
using namespace std;
char a[55][55],b[55][55];
bool ch(int m,int n){
	if (m<n)return 0;
	bool f=1;
	for (int i =1 ;i<=m-n+1;++i){
		for (int j =1;j<=m-n+1;++j){
			f=1;
			for (int ii=1;ii<=n;++ii){
				if (!f)break;
				for (int jj=1;jj<=n;++jj){
					if (a[i + ii -1][j + jj -1]!=b[ii][jj]){
					//	cout << i << " "<< j <<" "<<ii<<" "<<jj<<endl;
						f=0;
						break;
					}
				}
			}
			if (f)return 1;
		}
	}
	return 0;
}
int main(){
	int m,n;
	cin >> m >> n;
//	cout<<endl;
	for (int i = 1;i<=m;++i){
		for (int j=1;j<=m;++j){
			cin >> a[i][j];
		}
}
	for (int i =1;i<=n;++i){
		for (int j =1;j<=n;++j)
		cin >> b[i][j];
	}
	if (ch(m,n))puts("Yes");else puts("No");
	return 0;
}
