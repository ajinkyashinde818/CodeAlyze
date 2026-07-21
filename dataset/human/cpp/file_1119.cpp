#include <iostream>
using namespace std;

int main() {
    int A,B,C,D;
  int total=0;
int p;
    cin >>A>>B>>C>>D;

  for(int i=0;i<=D;i++){
        for(int j=0;j<=D;j++){
        p=A*i+B*j;
            if(p==D){
total+=1; 

}
else if((D-p)%C==0&&(D-p)>=0){
     total+=1;
}
}
}
    
   cout << total<< endl;
    }
