using namespace std;
#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> dl;
typedef vector<ii> vii;
typedef vector<dl> vdll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
#define pb push_back
#define mp make_pair
#define ft first
#define sc second
#define in insert
#define bs binary_search
#define INF LLONG_MAX
#define rc(s) return cout << s,0
#define int ll
const ll mod=1e9+7;
const int N=100005;
#define int ll
/*----------------------------*/ 
int arr[N];
/*----------------------------*/
int32_t main() {
	//freopen("sol.in","r",stdin);
	//freopen("sol.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    int mn=INF;
    int sum=0;
    int neg=0;
    for(int i=1;i<=n;i++){cin>>arr[i];mn=min(mn,abs(arr[i]));sum+=abs(arr[i]);if(arr[i]<0)neg++;}
    if(neg%2)sum-=2*abs(mn);
	rc(sum);
   	//THIS IS IS THE END
}
