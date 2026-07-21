#include<bits/stdc++.h>

template<typename First, typename Second, typename Third>
struct triple {
   First first;
   Second second;
   Third third;
};

using namespace std;

void solve(){
   int a,b;
    cin>>a>>b;
    if(a>=10)
         cout<<b;
   else  
         cout<<b+(100)*(10-a);
}
int main(){
   std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   
   solve(); 
   return 0;
}
