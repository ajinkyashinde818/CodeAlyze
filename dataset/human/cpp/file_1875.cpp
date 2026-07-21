#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define rep(i,j) REP((i), 0, (j))
#define REP(i,j,k) for(int i=(j);(i)<(k);++i)
#define BW(a,x,b) ((a)<=(x)&&(x)<=(b))
#define F first
#define S second
#define INF 1 << 30

typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef long long ll;

int main(){
  int Q;
  char s[9];
  int bin[32];
  scanf("%d", &Q);
  while(Q--){
    scanf("%s", s);
    for(int i = 0; i < 8; i++){
      switch(s[i]){
      case '0':
	bin[i*4] =  bin[i*4+1] = bin[i*4+2] = bin[i*4+3] = 0;
	break;
      case '1':
	bin[i*4] = bin[i*4+1] = bin[i*4+2] = 0;
	bin[i*4+3] = 1;
	break;
      case '2':
	bin[i*4] = bin[i*4+1] = bin[i*4+3] = 0;
	bin[i*4+2] = 1;
	break;
      case '3':
	bin[i*4] = bin[i*4+1] = 0;
	bin[i*4+2] = bin[i*4+3] = 1;
	break;
      case '4':
	bin[i*4] = bin[i*4+2] = bin[i*4+3] = 0;
	bin[i*4+1] = 1;
	break;
      case '5':
	bin[i*4] = bin[i*4+2] = 0;
	bin[i*4+1] = bin[i*4+3] = 1;
	break;
      case '6':
	bin[i*4] = bin[i*4+3] = 0;
	bin[i*4+1] = bin[i*4+2] = 1;
	break;
      case '7':
	bin[i*4] = 0;
	bin[i*4+1] = bin[i*4+2] = bin[i*4+3] = 1;
	break;
      case '8':
	bin[i*4+1] = bin[i*4+2] = bin[i*4+3] = 0;
	bin[i*4] = 1;
	break;
      case '9':
	bin[i*4+1] = bin[i*4+2] = 0;
	bin[i*4] = bin[i*4+3] = 1;
	break;
      case 'a':
	bin[i*4+1] = bin[i*4+3] = 0;
	bin[i*4] = bin[i*4+2] = 1;
	break;
      case 'b':
	bin[i*4+1] = 0;
	bin[i*4] = bin[i*4+2] = bin[i*4+3] = 1;
	break;
      case 'c':
	bin[i*4+2] = bin[i*4+3] = 0;
	bin[i*4] = bin[i*4+1] = 1;
	break;
      case 'd':
	bin[i*4+2] = 0;
	bin[i*4] = bin[i*4+1] = bin[i*4+3] = 1;
	break;
      case 'e':
	bin[i*4+3] = 0;
	bin[i*4] = bin[i*4+1] = bin[i*4+2] = 1;
	break;
      case 'f':
	bin[i*4] = bin[i*4+1] = bin[i*4+2] = bin[i*4+3] = 1;
	break;
      }
    }

    //    puts(s);
    //    rep(i, 32) printf(i%4?"%d":" %d", bin[i]); puts("");

    double res = 0;
    for(int i = 25, j = 1; i < 32; i += 1, j += 1)
      res += pow(0.5, j) * bin[i];

    for(int i = 1, j = 23; i < 25; i += 1, j -= 1)
      res += pow(2.0, j) * bin[i];

    if(bin[0]) res *= -1;

    //    if((s[6] == '0' || s[6] == '8') && s[7] == '0') printf("%.1lf\n", res);
    if(bin[31] == 1) printf("%.7lf\n", res);
    else if(bin[30] == 1) printf("%.6lf\n", res);
    else if(bin[29] == 1) printf("%.5lf\n", res);
    else if(bin[28] == 1) printf("%.4lf\n", res);
    else if(bin[27] == 1) printf("%.3lf\n", res);
    else if(bin[26] == 1) printf("%.2lf\n", res);
    else printf("%.1lf\n", res);
  }
  return 0;
}
