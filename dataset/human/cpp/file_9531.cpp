#include <iostream>
using namespace std;

bool match(int l, int m, int r, int c, string arr1[], string arr2[]){
	for (int i=0; i<m; i++){
		for (int j=0; j<m; j++){
			char char1 = arr1[i+r][j+c]; 
			char char2 = arr2[i][j];
			if (char1 != char2){
				return false;
			}
		}
	}
	return true;
}
  
//#.#         #.  00 01   for (int i=0; i<2; i++)
//.#.  11 12  .#  10 11        for (int j=0; j<2; j++)
//#.#  21 22                         arr1[i+r][j+c]==arr2[i][j]




 
int main() {
    int l, m;
    cin >> l >> m;
    string arr1[l];
    string arr2[m];
    for (int i=0; i<l; i++){
    	cin>> arr1[i];
    }
    for (int i=0; i<m; i++){
    	cin>> arr2[i];
    }
    for (int i=0; i<=l-m; i++){
    	for (int j=0; j<=l-m; j++){
    		if (match(l, m, i, j, arr1, arr2)){
    			cout << "Yes\n";
    			return 0;
    		}
    	}
    }
    cout <<"No\n";
}
