#include <iostream>
#include <string>
using namespace std;
int main(){
	int n,m;
	string a[100] ,b[100] ;
	cin >> n >> m;
	for( int i=0 ; i<n ; i++ )
			cin >> a[i] ;
	for( int i=0 ; i<m ; i++ )
		cin >> b[i];

	int counter=0,count=0;
	for( int i=0 ; i<n ; i++ ){
		string str=a[counter];
		string st=b[counter];
		if( str.find(st) <= n ){
			counter++;
		}
		if( counter==m )
			count++;
	}
	if( count == 1 )
		cout <<"Yes"<<endl;
	else
		cout<<"No"<<endl;

}
