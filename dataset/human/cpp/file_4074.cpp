#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef pair<int , int> P2;
typedef pair<pair<int , int> , int> P3;
typedef pair<pair<int , int> , pair<int , int> > P4;
#define Fst first
#define Snd second
#define PB(a) push_back(a)
#define MP(a , b) make_pair((a) , (b))
#define M3P(a , b , c) make_pair(make_pair((a) , (b)) , (c))
#define M4P(a , b , c , d) make_pair(make_pair((a) , (b)) , make_pair((c) , (d)))
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)
#define repv(t,it,v) for(vector<t>::iterator it = v.begin() ; it != v.end() ; ++it)

int N;
int x[1010] , y[1010] , r[1010];
double d[1010][1010];
double ans[1010];
double INF = 1e12;
bool b[1010];

double dis(int a , int b){
	double w = 1. * (x[a] - x[b]);
	double z = 1. * (y[a] - y[b]);
	return max(0.0 , sqrt(w * w + z * z) - 1.*r[a] - 1.*r[b]);
}

int main(){
	scanf("%d%d%d%d%d" , x , y , x + 1 , y + 1 , &N);
	repp(i,2,N+2){
		scanf("%d%d%d" , x + i , y + i , r + i);
	}
	repp(i,0,N+2){
		repp(j,0,N+2){
			d[i][j] = dis(i,j);
		}
	}
	fill(ans,ans + 1010,INF);
	ans[0] = 0.0;
	b[0] = 1;
	int z = 0;
	repp(i,0,N+1){
		int w = 1009;
		repp(j,0,N+2){
			ans[j] = min(ans[j] , ans[z] + d[z][j]);
			if(!b[j] && ans[w] > ans[j]){
				w = j;
			}
		}
		z = w;
		b[w] = 1;
	}
	printf("%.13f\n" , ans[1]);
	return 0;
}
