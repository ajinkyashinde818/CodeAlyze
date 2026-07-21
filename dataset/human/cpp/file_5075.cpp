#include <functional>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;


int main() {
   int n,m;
 
   cin >> n >> m;
  
  if(n<=10){
   int as = 100*(10-n);
  
   cout << m+as << endl;
  }else{
    cout << m << endl;
  }
   
  return 0;
}
