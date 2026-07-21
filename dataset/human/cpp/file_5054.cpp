#include <iostream>
using namespace std;
int main() {
  int contest,displayedRating;
  cin>>contest>>displayedRating;
  if(contest>=10){
      cout<<displayedRating<<"";
  }
  else{
    cout<<(10-contest)*100+displayedRating<<" ";    
  }
  return 0;
}
