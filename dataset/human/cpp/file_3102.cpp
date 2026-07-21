#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
  int N;
  cin>>N;
  long A[N];
  long sum=0;
  long min=10*10*10*10*10*10*10*10*10;
  int mainasu=0;
  for(int i=0;i<N;i++){
    cin>>A[i];
    if(abs(A[i])<min)min=abs(A[i]);
    
    //中の負の数
    if(i!=0&&i!=N-1){
      if(A[i]<0) mainasu++;
    }
    
    sum+=abs(A[i]);
  }
  long ans=0;
  if(A[0]<0 && A[N-1]<0){
    if(mainasu==0)ans =sum;
    else if(mainasu%2==1) ans=sum -2*min;
    else ans = sum;
  }else if(A[0]>=0 && A[N-1]>=0){
    if(mainasu%2==1) ans=sum -2*min;
    else ans = sum;
  }else{
    if(mainasu%2==0) ans=sum -2*min;
    else ans = sum;
  }

  cout<<ans<<endl;
    return 0;
}
