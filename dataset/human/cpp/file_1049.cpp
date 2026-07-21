#include<iostream>
using namespace std;
int main () {
 
  int R, G, B ,N;
  cin >> R >> G >> B >> N;
  int res = 0;
  int rn = N/R;
  int nrest = N;
  for (int r = 0; r < rn+1; r++) {
    nrest = N - r*R;
    if (nrest==0) { 
      res++;
      continue;
    }
    int gn = nrest/G;
    for (int g = 0; g < gn+1; g++) {
      nrest = N - r*R - g*G;
      if (nrest==0) { 
	res++;
	break;
      }
      if (nrest%B == 0) {
	res++;
      }
      //int bn = nrest/B;
      // for (int b = 0; b < bn+1; b++) {
      // 	nrest = N - r*R - g*G - b*B;
      // 	if (nrest==0) { 
      // 	  res++;
      // 	  //continue;
      // 	  break;
      // 	}
      // }
    }
  }
  cout<<res<<endl;
  return 0;
}
