#include <iostream>
using namespace std;
int main(){
  int R,G,B,N;
  cin>>R>>G>>B>>N;
  unsigned ans=0;
  for(int b=0 ; b<=N ; b++){
    for(int g=0 ; g<=N ; g++){
      int B_G = b*B+g*G ;
      if( N>=B_G && (N-B_G)%R==0 ){
        ans++;
      }
    }
  }

  cout<<ans<<endl;
  return 0;
}
