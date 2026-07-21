//cara pikir 
//pake recursive tapi gak 3 x
// C++ program for implementation of Ford Fulkerson algorithm 
#include <iostream> 
#include <limits.h> 
#include <string.h> 
#include <queue> 
#include <iostream> 
#include <set> 
#include <iterator> 
#include <algorithm>
#include <map>
using namespace std;
int main(){
  int num,disp,inner;
  cin>>num>>disp;
  if(num<10){
    inner=disp+(100*(10-num));
    cout<<inner;
  }else{
    cout<<disp;
  }
 
}
