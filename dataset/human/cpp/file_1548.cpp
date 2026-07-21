#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;
const int MAX_K = 1e3;

int main(){ 
  int N; scanf("%d", &N);
  if(N == 1){
    cout << "Yes" << endl;
    cout << "2" << endl;
    cout << "1 1" << endl;
    cout << "1 1" << endl;
    return 0;
  }
  int k = 0;
  for(int res = 1; res <= MAX_K; res++){
    if((res*(res+1))/2 == N){  k = res; break;}
  }
  
  if( k == 0){ printf("%s\n", "No"); return 0;}
  
  vector<int> vec[k+1];
  int cnt = 0;
  
  for(int i = 2; i <= k-1; i++){ 
    //上から何段目スタートか
    for(int h = i*(i-1)/2 + 1; h <= i*(i+1)/2; h++){
      vec[cnt].push_back(h);
    }
      int w = i*(i+1)/2;
    for(int times = 0; i+times < k ; times++){
      w += i+times;
      vec[cnt].push_back(w);
     
    }
    cnt++;
  }
  
  for(int s = 0; s < k; s++){
    vec[cnt].push_back( ( (s*(s+1))/2 )+1 );
  }
  
  cnt++;
  
  for(int t = (k*(k-1))/2 + 1; t <= k*(k+1)/2; t++){
    vec[cnt].push_back( t );
  }
  
  cnt++;
  
  for(int u = 1; u <= k; u++){
    vec[cnt].push_back( (u*(u+1) )/2);
  }
  
  printf("%s\n", "Yes");
  printf("%d\n", k+1);
  
  for(int i = 0; i <= k; i++){
    printf("%d ", (int)vec[i].size());
    for(auto n : vec[i]){ printf("%d ", n);}
    printf("\n");
  }
  
  return 0;
}
