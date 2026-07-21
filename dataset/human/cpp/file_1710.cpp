#include<iostream>
#include<cmath>

using namespace std;

int main(){
   int n;
   cin >> n;

   // チェック
   int a = (int)((1 + sqrt(1 + 8 * n))/2);
   if (a * (a-1)  != n * 2){
      cout << "No" << endl;
      return 0;
   }else{
      cout << "Yes" << endl;
   }

   // 出力
   cout << a << endl;
   int x = 1;
   int* num = new int[a];
   for(int i=0;i<a;i++){
      num[i] = x;
      // 数
      cout << a-1 << " ";
      for(int j=0;j<i;j++){
         cout << num[j] << " ";
         num[j]++;
      }
      for(int j=i;j<a-1;j++){
         cout << x << " ";
         x++;
      }
      cout << endl;
   }
}
