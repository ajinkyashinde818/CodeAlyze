#include <iostream>
#include <algorithm>
#include <math.h> 
#include <string>
#include <iomanip>
using namespace std;
int main(){
   int n;
   long a[100000];
   cin >> n;
   int counter = 0;
   for(int i = 0; i < n; i++) cin >> a[i];
   for(int i = 0; i < n; i++){
       if(a[i] < 0) counter += 1;
   }

   long long total = 0;
   for(int i = 0; i < n; i++){
       if(a[i] < 0) total = total - a[i];
       else total = total + a[i];
   }

   long b[100000];
   for(int i = 0; i < n; i++) {
        if(a[i] < 0) b[i] = -a[i];
        else b[i] = a[i];
   }

   long min = 1000000000;
   for(int i = 0; i < n; i++) {
       if(min > b[i]) {
           min = b[i];
       }
   }

   if(counter%2 == 0){
       cout << total << endl;
   }else{
       cout << total-2*min << endl;
   }
}
