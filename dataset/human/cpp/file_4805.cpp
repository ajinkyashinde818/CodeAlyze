/*
   وَعَلَى اللَّهِ فَلْيَتَوَكَّلِ الْمُؤْمِنُونَ
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
   //  freopen("in.txt", "r", stdin) ;
   ios :: sync_with_stdio(0) ;
   cin.tie(0) ;
   cout.tie(0) ;

   int a, b ;
   cin >> a >> b ;
   if(a > 10) return cout << b, 0 ;
   cout << 100 * (10 - a) + b ;


}
