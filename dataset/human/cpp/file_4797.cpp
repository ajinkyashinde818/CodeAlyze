#include <iostream>
using namespace std;

int main(){
int N;
int R;
cin>>N>>R;
if(N>=11&&N<=100&&R>=0&&R<=4111)
{
cout<<R<<endl;
}
else if(N<=10&&N>=1&&R>=0&&R<=4111)
{
cout<<R+(100*(10-N))<<endl;
}
return 0;
}
