#include<iostream>
using namespace std;

int main(){
    long int N,C;
    //max1 = 0,max2=0,max3=0,max4=0,res1=0,res2=0,res3=0,res4=0;
    long int maxr=-1,maxl=-1;
    cin >> N >> C;
    unsigned long int x[N+2],v[N],sumr[N+1],suml[N+1];
    long int maxl1[N+1],maxr1[N+1];
    //3=N 20=C
    x[0]=0;
    x[N+1]=C;
    for (long int i =0; i < N; i++){
        cin >>x[i+1]>>v[i];
    } 
    //sum of right rotation
    sumr[0] = 0;
    for(long int i = 1;i<=N;i++){
        sumr[i]=sumr[i-1]+v[i-1];
    }
    
    //sum of left rotation
    suml[0] = 0;
     for(long int i = 1;i<=N;i++){
        suml[i]=suml[i-1]+v[N-i];
    }   
    
    maxl1[0]=0;
    for(long int J = 1;J<=N;J++){
       //
        long int maxl0 = suml[J] - C + x[N+1-J]; 
        maxl1[J] = max(maxl1[J-1],maxl0);
    }
    

    for(long int I= 0;I<=N;I++){
        //J=0
        long int res=sumr[I]+suml[0];
        res -= x[I];
        if(maxr<res) maxr =res;
        res = sumr[I]-x[I]*2;
        res += maxl1[N-I];
        if(maxr<res)             maxr =res;
//        cout << "maxr: "<< res <<endl;
        
    }
    
    maxr1[0]=0;
    for(long int I = 1;I<=N;I++){
       //
        long int maxr0 = sumr[I] - x[I]; 
        maxr1[I] = max(maxr1[I-1],maxr0);
    }
    

    for(long int J = 0;J<=N;J++){
        //I=0
        long int res=suml[J]+sumr[0];
        res -= C - x[N+1-J];
        if(maxl<res) maxl = res;
        res = suml[J]-2*C+2*x[N+1-J];
        res += maxr1[N-J];
        if(maxl<res) maxl =res;
//        cout << "maxl: " << res << endl;
    }
 
    cout << max(maxr,maxl) << endl;
}
