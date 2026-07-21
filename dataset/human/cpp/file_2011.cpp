#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n;
  cin>>n;
  std::vector<int64_t> num_plus,num_minus;
  for(int i=0;i<n;i++){
    int temp;
    cin>>temp;
    if(temp>=0) num_plus.push_back(temp);
    else num_minus.push_back(temp);
  }

  std::sort(num_plus.begin(),num_plus.end());
  std::sort(num_minus.begin(),num_minus.end());

  int64_t result=0;
  for(int i=1;i<num_plus.size();i++){
    result+=num_plus[i];
  }
  //num_minus==0,2,4...
  if(num_minus.size()%2==0){
    for(int i=0;i<num_minus.size();i++){
      result+=(-1)*num_minus[i];

    }
    if(num_plus.size()>0)result+=num_plus[0];
  }else{
    for(int i=0;i<num_minus.size()-1;i++){
      result+=(-1)*num_minus[i];

    }

    if (num_plus.size()>0) {
      if(num_minus.back()*-1>num_plus.front()){
        result+=num_minus.back()*-1;
        result-=num_plus.front();
      }else{
        result+=num_plus.front();
        result-=num_minus.back()*-1;
      }
    } else {
      result+=num_minus.back();
    }

  }
  cout<<result<<endl;


  return 0;
}
