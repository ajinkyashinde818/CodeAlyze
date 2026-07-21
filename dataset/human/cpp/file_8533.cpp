#include<bits/stdc++.h>
int i,j,k,l,x,y,n,m;
std::string a[50],b[50];
main(){
  for(std::cin>>n>>m;i<n;)std::cin>>a[i++];
  for(;j<m;)std::cin>>b[j++];
  for(;k<=n-m;++k)for(l=0;l<=n-m;++l){
      i=0;
      for(x=0;x<m;++x)for(y=0;y<m;)i|=a[k+x][l+y]-b[x][y++];
      j&=i;
    }
  puts(j?"No":"Yes");
}
