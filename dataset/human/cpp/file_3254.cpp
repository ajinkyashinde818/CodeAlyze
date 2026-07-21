#include <iostream>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    int *a =new int[n];
    long long min=10000000000;
    long long sum=0;
    int c=0;
    for (int i=0;i<n;i++){
    	cin>>a[i];
        if(a[i]<0){
        	c++;
            sum-=a[i];
            if(min>-1*a[i]){
        		min=-1*a[i];
            }
        }else{
        	sum+=a[i];
          	if(min>a[i]){
        		min=a[i];
            }
        }
    }
    long long r;
	if(c%2==0){
    	r=sum;
    }else{
    	r=sum-2*min;
    }
          
    cout << r << endl;
}
