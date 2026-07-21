#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
 
 
int main(){
  int N;
  cin >> N;
 
  std::vector<long> a(N);
  std::copy_n(std::istream_iterator<long>{std::cin}, a.size(), a.begin());
    
  long long sum1=a[0];
  long long sum2=0;
  for(int i=1;i<N;i++){
	sum2+=a[i];
  }
  
  long long min=sum2-sum1;
  if(min<0){
	min=-min;
  }
  for(int i=1;i<N-1;i++){
	sum2-=a[i];
	sum1+=a[i];
	long long tmp=sum2-sum1;
	if(tmp<0){
	  tmp=-tmp;
	}
	if(min>tmp){
	  min=tmp;
	}
  }
  cout << min<<endl;
}
