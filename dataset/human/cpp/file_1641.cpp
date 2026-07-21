#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> a[500];

int main() {
  int n;
  scanf("%d",&n);
  for(int i=1;i<500;i++)
    if ((i*(i-1)>>1)==n) {
    	int cnt=0;
    	for(int j=1;j<i;j++)
    	  for(int k=j+1;k<=i;k++) {
    	  	cnt++;
    	  	a[j].push_back(cnt);
    	  	a[k].push_back(cnt);
		  }
		printf("Yes\n%d\n",i);
		for(int j=1;j<=i;j++) {
			printf("%d ",a[j].size());
			for(int k=0;k<a[j].size();k++) printf("%d ",a[j][k]);
			printf("\n");
		}
		return 0;
	}
  puts("No");
  return 0;
}
