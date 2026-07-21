#include<bits/stdc++.h>
using namespace std ;
const int N = 1e9+7 ;
int main(){
int n ;
scanf("%d",&n) ;
string s ; 
cin >> s ;  
int x[26] ;
for(int i=0;i<26;i++)
    x[i] = 1 ;
for(auto i:s){
	x[i-'a']++ ;
}
long long ans = 1 ;
for(auto i:x){
	ans *= i ;
  	ans %= N ;
}
cout << (ans-1+N)%N << '\n' ;  
}
