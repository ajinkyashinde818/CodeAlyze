#include <iostream>
using namespace std;
int main()
{
	int l, i=0, a[10];
    while(cin>>l){
        a[i] = l;
        i++;
    }
 if(a[0]<10)
 {
 cout<<100*(10-a[0])+a[1]<<"\n";
 }else{
 cout<<a[1]<<"\n";
 
 }

}
