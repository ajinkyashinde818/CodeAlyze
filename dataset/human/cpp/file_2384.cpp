#include <bits/stdc++.h>
    using namespace std;
     
int32_t main() {
      int N, counter=0, Vmin;
  	  long long sum=0;
	  cin >> N;
  
      vector<int> V(N);
	  for (int i = 0; i < N; i++) {
 	  cin >> V[i];
	  }
      
      for(int i = 0; i < N; i++){
        if(V[i] < 0){
          ++counter;
          V[i] = -V[i];
        }
       }
     
      sort(V.begin(), V.end());
        Vmin = V[0];
          
      for(int i = 0; i < N; i++){
            sum +=V[i];
      }
 
      if(counter%2 == 0)
        cout << sum <<endl;
      else
        cout << sum - 2*Vmin <<endl;

    }
