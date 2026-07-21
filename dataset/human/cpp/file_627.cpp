#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
	int R,G,B,N;
	cin>>R>>G>>B>>N;

	int ans=0;
	int NR=N/R+1;
	int NG=N/G+1;
	int NB=(N-R-G)/B+1;
	for (int r=0;r<=NR;r++){
		if (R*r>N){
			break;
		}
		for (int g=0;g<=NG;g++){
			if (R*r+G*g>N){
				break;
			}
			int b=(N-R*r-G*g)/B;
			int N1=R*r+G*g+B*b;
			if (N1==N){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
