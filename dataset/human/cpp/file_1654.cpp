#include <cstdio>
 #include <cstdlib>
 #include <iostream>
 #include <fstream>
 #include <sstream>
 #include <set>
 #include <map>
 #include <vector>
 #include <list>
 #include <algorithm>
 #include <cstring>
 #include <cmath>
 #include <string>
 #include <queue>
 #include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
 #include <cassert>
 #include <iomanip>        //do setprecision
 #include <ctime>
 #include <complex>
 using namespace std;

 #define FOR(i,b,e) for(int i=(b);i<(e);++i)
 #define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
 #define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
 #define REP(x, n) for(int x = 0; x < (n); ++x)

 #define ST first
 #define ND second
 #define PB push_back
 #define PF push_front
 #define MP make_pair
 #define LL long long
 #define ULL unsigned LL
 #define LD long double
 #define pii pair<int,int>
 #define pll pair<LL,LL>

 const double pi = 3.14159265358979323846264;
 const int mod=1000000007;

int main(){
	int n;
	cin>>n;
	if(n==1){
		cout<<"Yes"<<endl;
		cout<<2<<endl;
		cout<<1<<" "<<1<<endl;
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	int mx=1;
	FOR(ii,2,n){
		mx+=ii;
		if(mx>n){
			//cerr<<"over:"<<ii<<" "<<mx<<" bf:"<<mx-ii<<endl;
			break;
		}
		if(n==mx){
			int s=ii;
			int k=ii+1;
			vector<vector<int>> ans=vector<vector<int>>(k+1,vector<int>(k+1,0));
			FOR(j,0,s)ans[0][j]=j+1;
			int lst=s;
			FORQ(i,1,k){
				ans[i][0]=i;
				FOR(j,1,i){
					ans[i][j]=ans[j][i-1];
				}
				FOR(j,i,s){
					lst++;
					ans[i][j]=lst;
				}
			}

			cout<<"Yes"<<endl;
			cout<<k<<endl;
			FOR(i,0,k){
				cout<<s;
				FOR(j,0,s){
					cout<<" "<<ans[i][j];
				}
				cout<<endl;
			}
			return 0;
		}
	}
	cout<<"No"<<endl;
	return 0;
}
