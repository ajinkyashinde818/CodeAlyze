#include <iostream>
using namespace std;
int main(void){
int R,G,B,N,count;
count = 0;

cin >> R >> G >> B >> N;

for (int r=0;r*R<=N;r=r+1) {
    for (int g=0;r*R+g*G<=N;g=g+1) {

            if (((N-(r*R+g*G))%B)==0 && ((N-(r*R+g*G))%B)>=0) {
            count= count+1;
            }
            
        
        
    }
   
    
}

cout << count << endl;
   
   
}
