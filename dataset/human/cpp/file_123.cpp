#include<iostream>
using namespace std;

int main()
{
    int R,G,B,N;
    cin >> R >> G >> B >> N;
    int r,g;
    int N1=N;
    int N2=N;
    int c=0;
    for (r=0;r<=N/R;r++){
        N1=N-R*r;
        if(N1==0){
        	c++;
            break;
        }
    	for(g=0;g<=N1/G;g++){
            N2=N1-G*g;
            if(N2==0){
            	c++;
                break;
            }
            if(N2%B==0){
            	c++;
                continue;
            }
        }
    }
    cout << c << endl;
}
