#include <iostream>
#include <climits>
#include <string>
#include <stdlib.h>
#include <algorithm>
using namespace std;

long long int i,j,ans=1;
 
int ascSort(const void* v1, const void* v2) {
    const int _v1 = *((const int*)v1);
    const int _v2 = *((const int*)v2);
 
    if ( _v1 < _v2 ) {
        return 1;
    } else if ( _v1 > _v2 ) {
        return -1;
    } else {
        return 0;
    }
}
int INF = 1<<29;
const int mod = 1000000007;

int main(){
	string a[50],b[50];
	int n,m,x,y;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<m;i++){
		cin>>b[i];
	}
	int count,check=0;
	for(i=0;i<n-m+1;i++){
		for(j=0;j<n-m+1;j++){
			count = 0;
			for(x=i;x<m+i;x++){
				for(y=j;y<m+j;y++){
					if(a[x][y]==b[x-i][y-j]){
						count += 1;
					}
				}
			}
		if(count == m*m){
			check = 1;
			break;
		}
		}
	}
	if(check==1){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}
