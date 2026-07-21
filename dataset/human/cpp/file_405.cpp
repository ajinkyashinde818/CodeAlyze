#include <iostream>
using namespace std;

int main(){
  int R,G,B,N;
  cin >> R >> G >> B >> N;
  int N_Origin = N;
  int R_max = N/R;
  int G_max;
  int B_max;
  int result = 0;
  for(int i=0;i <= R_max;i++){
    N = N_Origin;    
    N = N -R*i;
    G_max = N/G;
    for(int j=0;j <=G_max;j++){
    	
      N = N - G * j;
  	  if(N % B == 0){
//        cout << "i " << i << " j " << j << endl;
//        cout << N << endl;
        result++;
      }
	  N = N+ G*j;
    }
  }
  cout << result << endl;
  return 0;
}
