#include <iostream>
 #include <vector>
 #include <map>
 using namespace std;
 vector<int> mat[2004];
 
 int main()
 {
     int n;
     cin>>n;
     map<int, int> edg;
     for(int i = 1; i <= 2e3; ++i) {
         edg[i] = (i * (i-1))/2;
     }
     int e = -1;
     for(auto i : edg) {
         if(i.second == n) {
             e = i.first;
         }
     }
     if(e == -1) {
         printf("No\n");
         return 0;
     }
     int cnt = 1;
     for(int i = 1; i <= e; ++i) {
         for(int j = i + 1; j <= e; ++j) {
             mat[i].push_back(cnt);
             mat[j].push_back(cnt);
             cnt++;
         }
     }
     printf("Yes\n");
     printf("%d\n", e);                              
     for(int i = 1; i <= e; ++i) {
         printf("%d ", mat[i].size());
         for(auto j : mat[i])
             printf("%d ", j);
         printf("\n");
     }
     
     return 0;
 }
