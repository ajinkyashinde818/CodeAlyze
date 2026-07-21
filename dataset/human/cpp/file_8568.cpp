#include<iostream>
#include<fstream>
#include<math.h>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<sstream>
#include<set>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define esta(x,v) (find((v).begin(),(v).end(),(x)) !=  (v).end())
#define index(x,v) (find((v).begin(),(v).end(),(x)) - (v).begin())
#define debug(x) cout << #x << " = "  << x << endl
#define pb push_back
#define mp make_pair

typedef long long tint;
typedef unsigned long long utint;
typedef long double ldouble;

typedef vector<int> vint;

int toNumber (string s)
{
	int Number;
	if ( ! (istringstream(s) >> Number) ) Number = 0; // el string vacio lo manda al cero
	return Number;
}

string toString (int number)
{
    ostringstream ostr;
    ostr << number;
    return  ostr.str();
}

int main (){
	int n,m;
	cin>>n>>m;
	vector<string> a(n), b(m);
	forn(i,n)cin>>a[i];
	forn(i,m)cin>>b[i];
	bool si=false;
	forn(i,n){
		forn(j,n){
			if(a[i][j]==b[0][0] && i+m-1<n && j+m-1<n){
				si=true;
				forn(b1, m){
					forn(b2, m){
						if(a[i+b1][j+b2]!=b[b1][b2]){
							si=false;
							break;
						}
					}
					if(!si)break;
				}
				if(si){
					cout<<"Yes"<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}
