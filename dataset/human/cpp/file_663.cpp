#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <numeric>
using namespace std;


int main()
{
    
    int R,G,B,N;
    cin>>R>>G>>B>>N;
    int counter=0;
    for(int r=0;r<=N/R;r++){
        for(int b=0;b<=(N-r*R)/B;b++){
            if((N-r*R-b*B)%G==0){
                counter+=1;
            }
        }
    }
    cout<<counter<<endl;
    
    }
