#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
#include <numeric>
#include <iomanip>
#define fi first
#define se second
#define fcout(n) cout<<fixed<<setprecision((n))
#define cinl(str) getline(cin,(str))
using namespace std;
bool value(int y,int x,int R,int C){return 0<=y&&y<R&&0<=x&&x<C;}
typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long > vll;
typedef vector< vi > vvi;
double pie=acos(-1);
int INF=1000000007;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };


int main() {
	int n,m;
	char a[55][55],b[55][55];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[j][i];
		}
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cin>>b[j][i];
		}
	}

	int check=0;

	for(int i=0;i<n-m+1;i++){
		for(int j=0;j<n-m+1;j++){
			for(int k=0;k<m;k++){
				for(int l=0;l<m;l++){
					if(b[l][k]==a[j+l][i+k]){
						check++;
					}
					else{
						check=0;
						break;
					}
				}
				if(check==0) break;
				if(k==m-1){
					cout<<"Yes"<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"No"<<endl;
}
