#include <bits/stdc++.h>

int main(){
    int N;
    std::cin >> N;
    std::vector< int > A(N);
    std::vector< int > B(N);
    std::map< int, int > Amp;
    std::map< int, int > Bmp;
    for(int i=0; i<N; i++){
        std::cin >> A[i];
        
        auto itra = Amp.find(A[i]);
        if(itra != Amp.end()){
            Amp[A[i]]++;
        }else{
            Amp[A[i]] = 1;
        }
    }
    for(int i=0; i<N; i++){
        std::cin >> B[i];
        auto itrb = Bmp.find(B[i]);
        if(itrb != Bmp.end()){
            Bmp[B[i]]++;
        }else{
            Bmp[B[i]] = 1;
        }
    }
    
    for(auto itra=Amp.begin(); itra != Amp.end(); itra++){
        auto itrb = Bmp.find(itra->first);
        if(itrb != Bmp.end()){
            if(itra->second + itrb->second > N){
                std::cout << "No" << std::endl;
                return 0;
            }
        }
    }
    
    int cnt = 0;
    int Aindex = 0;
    int Bindex = 0;
    while(cnt <= N){
        if(A[Aindex] != B[Aindex]){
            cnt++;
            Aindex++;
            if(Aindex == N){ Aindex = 0; }
        }else{
            while(A[Aindex] == B[Bindex]){
                Bindex++;
                if(Bindex == N){ Bindex = 0; }
            }
            std::swap(B[Aindex], B[Bindex]);
            cnt = 0;
            Aindex++;
            if(Aindex == N){ Aindex = 0; }
            Bindex++;
            if(Bindex == N){ Bindex = 0; }
        }
    }
    
    std::cout << "Yes" << std::endl;
    for(int i=0; i<N-1; i++){
        std::cout << B[i] << " ";
    }
    std::cout << B[N-1] << std::endl;
    
    return 0;
    
}
