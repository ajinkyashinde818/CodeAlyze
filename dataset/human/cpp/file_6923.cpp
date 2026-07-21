#include <bits/stdc++.h>
using namespace std;

int main()
{
  	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 	int n; 
  	cin >> n;
  	vector<int> a(n), b(n);
  	for(int i = 0; i < n; i++)
      	cin >> a[i];
  	for(int i = 0; i < n; i++)
      	cin >> b[n-i-1];
  	
  	int same = -1;
  	for(int i = 0; i < n; i++)
      	if(a[i] == b[i]) {
         	same = a[i];
          	break;
        }
  	
  	int left = 0;
  	for(int i = 0; i < n; i++)
    	if(a[i] == same && b[i] == same) {
         	left = i;
          	break;
        }
  
  	int right = -1;
  	for(int i = n-1; i >= 0; i--)
      	if(a[i] == same && b[i] == same) {
         	right = i;
          	break;
        }
  	
  	for(int i = 0; i < n; i++)
    	if(a[i] != same && b[i] != same && left <= right) {
          	swap(b[i], b[left]);
          	left++;
        }
  
  	if(left <= right) {
     	cout << "No"; 
    } else {
     	cout << "Yes\n";
      	for(int i = 0; i < n; i++) cout << b[i] << " ";
    }
}
