#include <iostream>
using namespace std;
int main(void){
   long a,c,i;
   cin>>a;
   long chart[a-1][2];
   long b[a];
   for(i=0;i<a;i++){
       cin>>b[i];
   }
   chart[0][0]=-b[0]-b[1];
   chart[0][1]=b[0]+b[1];
   for(i=0;i<a-2;i++){
       long x=chart[i][0]+2*b[i+1]-b[i+2];
       long y=chart[i][1]-2*b[i+1]-b[i+2];
       if(x>y)
       chart[i+1][0]=x;
       else
       chart[i+1][0]=y;
       x=chart[i][0]+b[i+2];
       y=chart[i][1]+b[i+2];
       if(x>y)
       chart[i+1][1]=x;
       else
       chart[i+1][1]=y;
   }
   if(chart[a-2][0]>chart[a-2][1])
   cout<<chart[a-2][0]<<endl;
   else
   cout<<chart[a-2][1]<<endl;
   return 0;
}
